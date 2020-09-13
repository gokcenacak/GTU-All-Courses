/* SPIM S20 MIPS simulator.
   Execute SPIM syscalls, both in simulator and bare mode.
   Execute MIPS syscalls in bare mode, when running on MIPS systems.
   Copyright (c) 1990-2010, James R. Larus.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation and/or
   other materials provided with the distribution.

   Neither the name of the James R. Larus nor the names of its contributors may be
   used to endorse or promote products derived from this software without specific
   prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef _WIN32
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

#ifdef _WIN32
#include <io.h>
#endif

#include "spim.h"
#include "string-stream.h"
#include "inst.h"
#include "reg.h"
#include "mem.h"
#include "sym-tbl.h"
#include "syscall.h"
#include "spim-utils.h"

#include <iostream>
using namespace std;

#ifdef _WIN32
/* Windows has an handler that is invoked when an invalid argument is passed to a system
   call. https://msdn.microsoft.com/en-us/library/a9yf33zb(v=vs.110).aspx

   All good, except that the handler tries to invoke Watson and then kill spim with an exception.

   Override the handler to just report an error.
*/

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void myInvalidParameterHandler(const wchar_t* expression,
   const wchar_t* function, 
   const wchar_t* file, 
   unsigned int line, 
   uintptr_t pReserved)
{
  if (function != NULL)
    {
      run_error ("Bad parameter to system call: %s\n", function);
    }
  else
    {
      run_error ("Bad parameter to system call\n");
    }
}

static _invalid_parameter_handler oldHandler;

void windowsParameterHandlingControl(int flag )
{
  static _invalid_parameter_handler oldHandler;
  static _invalid_parameter_handler newHandler = myInvalidParameterHandler;

  if (flag == 0)
    {
      oldHandler = _set_invalid_parameter_handler(newHandler);
      _CrtSetReportMode(_CRT_ASSERT, 0); // Disable the message box for assertions.
    }
  else
    {
      newHandler = _set_invalid_parameter_handler(oldHandler);
      _CrtSetReportMode(_CRT_ASSERT, 1);  // Enable the message box for assertions.
    }
}
#endif

int pid = 0;
int current_process;
enum process_state{none, ready, blocked, finished, running};
mem_addr process_table_addr;
mem_addr scheduler_pc;
bool is_Scheduling = false;

void save_process_registers(int addr){
   //Saving register contents
      for(int i = 0 ; i < 32 ; i++){
        set_mem_word(addr,R[i]);
        addr+=4;
      }

      //Saving HI register content
      set_mem_word(addr,HI);
      addr+=4;

      //Saving LO register content
      set_mem_word(addr,LO);
      addr+=4;

      //Saving PC register content
      set_mem_word(addr,PC);
      addr+=4;

      //Saving nPC register content
      set_mem_word(addr,nPC);

}

void read_process_registers(int addr){
    //Saving register contents
      for(int i = 0 ; i < 32 ; i++){
        R[i] = read_mem_word(addr);
        addr+=4;
      }

      //Saving HI register content from memory
      HI = read_mem_word(addr);
      addr+=4;

      //Saving LO register content from memory
      LO = read_mem_word(addr);
      addr+=4;

      //Saving PC register content from memory
      PC = read_mem_word(addr);
      addr+=4;

      //Reading nPC register content from memory
      nPC = read_mem_word(addr);
}

void printProcess(int pid){
      int addr;
      addr = read_mem_word(process_table_addr + pid * 4);
      addr = read_mem_word(addr);
      
      //set init process pid 0
      int myPID = read_mem_word(addr);
      addr+=4;
      //set process name
      char process_name[256];
      for(int i = 0 ; i < 256; i++){
        process_name[i] = read_mem_byte(addr);
        addr+=1;
      }
      //Get process's state
      int process_state = read_mem_word(addr);
      addr+=4;

      //Printing PID, Name and State of the process
      write_output (console_out, "PID: %d ", myPID);
      write_output (console_out, "Process name: %s ", process_name);
      if(process_state == 0){
        write_output (console_out, "Process state: None ");
      }
      else if(process_state == 1){
        write_output (console_out, "Process state: Ready ");
      }
      else if(process_state == 2){
        write_output (console_out, "Process state: Blocked ");

      }
      else if(process_state == 3){
        write_output (console_out, "Process state: Finished ");

      }
      else if(process_state == 4){
        write_output (console_out, "Process state: Running ");

      }
      //Passing through registers address' to calculate PC's address
      for(int i = 0 ; i < 32 ; i++){
        addr+=4;
      }

      addr+=4;
      addr+=4;

      //Print PC
      write_output (console_out, "PC: %d \n", read_mem_word(addr));
      addr+=4;


}
/*You implement your handler here*/
void SPIM_timerHandler()
{
  if(!is_Scheduling) {
    is_Scheduling = true;

    //Getting current process's entry address
    mem_addr addr = process_table_addr + 4 * current_process;
    addr = read_mem_word(addr);
    addr = read_mem_word(addr);

    //Getting current process's entry's memory component area's address to save the current values to the process table
    addr+=264;
    save_process_registers(addr);

    //Calculating init process's entry address
    addr = process_table_addr;
    addr = read_mem_word(addr);
    addr = read_mem_word(addr);
    addr+=264;

    //Getting init process's memory contents and loading them
    read_process_registers(addr);

    write_output (console_out, "\n======================= PROCESS SWITCH =======================\n");

    for(int i = 0; i < 10 ; i++){
      printProcess(i);
    }
    write_output (console_out, "==============================================================\n");

    //Setting PC to scheduler's PC
    PC = scheduler_pc;
  }
}


/* Decides which syscall to execute or simulate.  Returns zero upon
   exit syscall and non-zero to continue execution. */
int
do_syscall ()
{
#ifdef _WIN32
    windowsParameterHandlingControl(0);
#endif

  /* Syscalls for the source-language version of SPIM.  These are easier to
     use than the real syscall and are portable to non-MIPS operating
     systems. */

  switch (R[REG_V0])
    {
    case PRINT_INT_SYSCALL:
      write_output (console_out, "%d", R[REG_A0]);
      break;

    case PRINT_FLOAT_SYSCALL:
      {
	float val = FPR_S (REG_FA0);

	write_output (console_out, "%.8f", val);
	break;
      }

    case PRINT_DOUBLE_SYSCALL:
      write_output (console_out, "%.18g", FPR[REG_FA0 / 2]);
      break;

    case PRINT_STRING_SYSCALL:
      write_output (console_out, "%s", mem_reference (R[REG_A0]));
      break;

    case READ_INT_SYSCALL:
    {
      static char str [256];

    	read_input (str, 256);
    	R[REG_RES] = atol (str);
    	break;
    }

    case READ_FLOAT_SYSCALL:
    {
	     static char str [256];

	     read_input (str, 256);
	     FPR_S (REG_FRES) = (float) atof (str);
	     break;
    }

    case READ_DOUBLE_SYSCALL:
    {
	   static char str [256];
      read_input (str, 256);
      FPR [REG_FRES] = atof (str);
      break;
    }

    case READ_STRING_SYSCALL:
      {
	read_input ( (char *) mem_reference (R[REG_A0]), R[REG_A1]);
	data_modified = true;
	break;
      }

    case SBRK_SYSCALL:
      {
	mem_addr x = data_top;
	expand_data (R[REG_A0]);
	R[REG_RES] = x;
	data_modified = true;
	break;
      }

    case PRINT_CHARACTER_SYSCALL:
      write_output (console_out, "%c", R[REG_A0]);
      break;

    case READ_CHARACTER_SYSCALL:
      {
	static char str [2];

	read_input (str, 2);
	if (*str == '\0') *str = '\n';      /* makes xspim = spim */
	R[REG_RES] = (long) str[0];
	break;
      }

    case EXIT_SYSCALL:
      spim_return_value = 0;
      return (0);

    case EXIT2_SYSCALL:
      spim_return_value = R[REG_A0];	/* value passed to spim's exit() call */
      return (0);

    case OPEN_SYSCALL:
      {
#ifdef _WIN32
        R[REG_RES] = _open((char*)mem_reference (R[REG_A0]), R[REG_A1], R[REG_A2]);
#else
	R[REG_RES] = open((char*)mem_reference (R[REG_A0]), R[REG_A1], R[REG_A2]);
#endif
	break;
      }

    case READ_SYSCALL:
    {
	     /* Test if address is valid */
	     (void)mem_reference (R[REG_A1] + R[REG_A2] - 1);
#ifdef _WIN32
	     R[REG_RES] = _read(R[REG_A0], mem_reference (R[REG_A1]), R[REG_A2]);
#else
	     R[REG_RES] = read(R[REG_A0], mem_reference (R[REG_A1]), R[REG_A2]);
#endif
	     data_modified = true;
	     break;
    }

    case WRITE_SYSCALL:
    {
	     /* Test if address is valid */
	     (void)mem_reference (R[REG_A1] + R[REG_A2] - 1);
#ifdef _WIN32
	     R[REG_RES] = _write(R[REG_A0], mem_reference (R[REG_A1]), R[REG_A2]);
#else
	     R[REG_RES] = write(R[REG_A0], mem_reference (R[REG_A1]), R[REG_A2]);
#endif
	     break;
    }

    case CLOSE_SYSCALL:
    {
#ifdef _WIN32
	   R[REG_RES] = _close(R[REG_A0]);
#else
	   R[REG_RES] = close(R[REG_A0]);
#endif
	   break;
    }

    case CREATE_INIT_PROCESS:{

      //get process table's address from a0
      mem_addr addr = R[REG_A0];
      process_table_addr = R[REG_A0];
      //get scheduler's pc from register a1
      scheduler_pc = R[REG_A1];

      //Getting init process's entry address
      addr = read_mem_word(addr + 0);
      addr = read_mem_word(addr + 0);
      
      char process_name[256] = "init";
      //set init process pid 0
      set_mem_word(addr, 0);
      addr+=4;
      //set process name
      for(int i = 0 ; i < 256; i++){
        set_mem_byte(addr,process_name[i]);
        addr+=1;
      }
      //Set as running
      set_mem_word(addr, running);
      addr+=4;

      //Save the registers
      save_process_registers(addr);

      pid+=1;

      read_process_registers(addr);

      break;
    }
    case FORK:{
      char process_name[256];  

      //Getting init process's name's address
      mem_addr process_name_addr = process_table_addr;
      process_name_addr = read_mem_word(process_table_addr);
      process_name_addr = read_mem_word(process_name_addr);
      process_name_addr+=4;

      //Reading init process's name into an array
      for(int i = 0; i < 256 ; i++){
        process_name[i] = read_mem_byte(process_name_addr + 0);
        process_name_addr += 1;
      }

      //Getting the address of the next available area in the process table for an process table entry
      mem_addr addr = process_table_addr + 4 * pid;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);

      //Setting pid value
      set_mem_word(addr,pid);
      addr+=4;

      //Setting process name to parent's name
      for(int i = 0 ; i < 256; i++){
        set_mem_byte(addr,process_name[i]);
        addr+=1;
      }

      //Setting process's status
      set_mem_word(addr,ready);
      addr+=4;


      //Setting child process's return value to be 0
      R[REG_RES] = 0;
      //Saving newly changed register values to child's entry
      PC +=4;
      save_process_registers(addr);
      PC -=4;

      //Setting parent process's return value to be child's pid
      R[REG_RES] = pid;

      //Increase pid with 1 if there are less than 10 processes in the process table
      if(pid < 10)
        pid+=1;
      else{
        fprintf(stdout, "Can create only 10 processes!\n");
        exit(EXIT_FAILURE);
      }

      break;
    }
    case EXECVE:{

      char filename[256];
      //Get requested process name from the register a0
      char * process_name = (char*) mem_reference(R[REG_A0]);

      //Add .s extension to be compatible with the read assembly file function
      strcpy(filename, process_name);
      strcat(filename,".s\0");

      //Calculate the calling process' entry starting address
      mem_addr addr = process_table_addr + 4 * current_process;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);
      addr+=4;

      //Change process name to requested name
      for(int i = 0; i < 256; i++){
        set_mem_byte(addr,process_name[i]);
        addr+=1;
      }
      addr+=4;

      //Initializing symbol table and reading the new requested process's file
      initialize_symbol_table();
      read_assembly_file (filename);

      //Finding main in the new file to run the program
      PC = find_symbol_address("main");
      //To make sure it lands on the main label
      PC -= 4;
      break;
    }
    case GIVE_CNT:{
      //Calculating current process's entry address
      mem_addr addr = process_table_addr + 4 * current_process;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);
      //Calculating current process's entry's status address
      addr+=260;

      //If current process is not finished, make it ready
      if(read_mem_word(addr) != finished) {
        set_mem_word(addr, ready);
      }

      //Set the new process running
      current_process = R[REG_A0];

      //Get the address of the process entry of new current process
      addr = process_table_addr + 4 * current_process;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);
      addr+=260;

      //Set the new process running
      set_mem_word(addr, running);
      addr+=4;

      read_process_registers(addr);
      PC -= 4;
      is_Scheduling = false;
      break;
    }

    case GET_CURRENT_PROCESS:{
      R[REG_RES] = current_process;
      break;
    }

    case PROCESS_EXIT:{
      //Get current process's entry address
      mem_addr addr = process_table_addr + 4 * current_process;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);

      //Get current process's entry's status address
      addr+=260;

      //Set the status to finished
      set_mem_word(addr,finished);

      //Pull PC back so the process doesn't try to run non-instructions
      PC = PC - BYTES_PER_WORD;
      break;
    }

    case WAITPID:{
      //Get waited pid value from a0 register
      int waited_pid = (int) R[REG_A0];

      //Calculate waited pid-ed process's entry address in the process table
      mem_addr addr = process_table_addr + 4 * waited_pid;
      addr = read_mem_word(addr);
      addr = read_mem_word(addr);
      addr+=260;

      //Calculate waited pid-ed process's entry's status address in the process table
      //and check if that process is finished or not, if not pull the PC by one instruction
      //to stop waiting process from running
      if(read_mem_word(addr) != finished){
        PC = PC - BYTES_PER_WORD;
      }
      
      break;
    }

    case RAND_INT:{
      //Generate a random number between 0-3 and put it into register v0
      R[REG_RES] = rand() % 4;
      break;
    }

    case SET_RAND_INT_SEED:{
      //Set random number seed
      srand (time(NULL));
      break;
    }

    default:{
      run_error ("Unknown system call: %d\n", R[REG_V0]);
      break;
    }
}
#ifdef _WIN32
    windowsParameterHandlingControl(1);
#endif
  return (1);
}


void
handle_exception ()
{
  if (!quiet && CP0_ExCode != ExcCode_Int)
    error ("Exception occurred at PC=0x%08x\n", CP0_EPC);

  exception_occurred = 0;
  PC = EXCEPTION_ADDR;

  switch (CP0_ExCode)
    {
    case ExcCode_Int:
      break;

    case ExcCode_AdEL:
      if (!quiet)
	error ("  Unaligned address in inst/data fetch: 0x%08x\n", CP0_BadVAddr);
      break;

    case ExcCode_AdES:
      if (!quiet)
	error ("  Unaligned address in store: 0x%08x\n", CP0_BadVAddr);
      break;

    case ExcCode_IBE:
      if (!quiet)
	error ("  Bad address in text read: 0x%08x\n", CP0_BadVAddr);
      break;

    case ExcCode_DBE:
      if (!quiet)
	error ("  Bad address in data/stack read: 0x%08x\n", CP0_BadVAddr);
      break;

    case ExcCode_Sys:
      if (!quiet)
	error ("  Error in syscall\n");
      break;

    case ExcCode_Bp:
      exception_occurred = 0;
      return;

    case ExcCode_RI:
      if (!quiet)
	error ("  Reserved instruction execution\n");
      break;

    case ExcCode_CpU:
      if (!quiet)
	error ("  Coprocessor unuable\n");
      break;

    case ExcCode_Ov:
      if (!quiet)
	error ("  Arithmetic overflow\n");
      break;

    case ExcCode_Tr:
      if (!quiet)
	error ("  Trap\n");
      break;

    case ExcCode_FPE:
      if (!quiet)
	error ("  Floating point\n");
      break;

    default:
      if (!quiet)
	error ("Unknown exception: %d\n", CP0_ExCode);
      break;
    }
}
