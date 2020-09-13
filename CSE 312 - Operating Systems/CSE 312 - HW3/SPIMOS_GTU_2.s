.data

	#Process 1 space allocation
	p1_pid: .space 4
	p1_process_name: .space 256
	p1_process_state: .space 4
	p1_registers: .space 128
	p1_HI_register: .space 4
	p1_LO_register: .space 4
	p1_PC: .space 4
	p1_nPC: .space 4
	p1_process_table_entry: .word p1_pid, p1_process_name, p1_process_state, p1_registers, p1_HI_register, p1_LO_register, p1_PC, p1_nPC

	#Process 2 space allocation
	p2_pid: .space 4
	p2_process_name: .space 256
	p2_process_state: .space 4
	p2_registers: .space 128
	p2_HI_register: .space 4
	p2_LO_register: .space 4
	p2_PC: .space 4
	p2_nPC: .space 4
	p2_process_table_entry: .word p2_pid, p2_process_name, p2_process_state, p2_registers, p2_HI_register, p2_LO_register, p2_PC, p2_nPC

	#Process 3 space allocation
	p3_pid: .space 4
	p3_process_name: .space 256
	p3_process_state: .space 4
	p3_registers: .space 128
	p3_HI_register: .space 4
	p3_LO_register: .space 4
	p3_PC: .space 4
	p3_nPC: .space 4
	p3_process_table_entry: .word p3_pid, p3_process_name, p3_process_state, p3_registers, p3_HI_register, p3_LO_register, p3_PC, p3_nPC

	#Process 4 space allocation
	p4_pid: .space 4
	p4_process_name: .space 256
	p4_process_state: .space 4
	p4_registers: .space 128
	p4_HI_register: .space 4
	p4_LO_register: .space 4
	p4_PC: .space 4
	p4_nPC: .space 4
	p4_process_table_entry: .word p4_pid, p4_process_name, p4_process_state, p4_registers, p4_HI_register, p4_LO_register, p4_PC, p4_nPC

	#Process 5 space allocation
	p5_pid: .space 4
	p5_process_name: .space 256
	p5_process_state: .space 4
	p5_registers: .space 128
	p5_HI_register: .space 4
	p5_LO_register: .space 4
	p5_PC: .space 4
	p5_nPC: .space 4
	p5_process_table_entry: .word p5_pid, p5_process_name, p5_process_state, p5_registers, p5_HI_register, p5_LO_register, p5_PC, p5_nPC

	#Process 6 space allocation
	p6_pid: .space 4
	p6_process_name: .space 256
	p6_process_state: .space 4
	p6_registers: .space 128
	p6_HI_register: .space 4
	p6_LO_register: .space 4
	p6_PC: .space 4
	p6_nPC: .space 4
	p6_process_table_entry: .word p6_pid, p6_process_name, p6_process_state, p6_registers, p6_HI_register, p6_LO_register, p6_PC, p6_nPC

	#Process 7 space allocation
	p7_pid: .space 4
	p7_process_name: .space 256
	p7_process_state: .space 4
	p7_registers: .space 128
	p7_HI_register: .space 4
	p7_LO_register: .space 4
	p7_PC: .space 4
	p7_nPC: .space 4
	p7_process_table_entry: .word p7_pid, p7_process_name, p7_process_state, p7_registers, p7_HI_register, p7_LO_register, p7_PC, p7_nPC

	#Process 8 space allocation
	p8_pid: .space 4
	p8_process_name: .space 256
	p8_process_state: .space 4
	p8_registers: .space 128
	p8_HI_register: .space 4
	p8_LO_register: .space 4
	p8_PC: .space 4
	p8_nPC: .space 4
	p8_process_table_entry: .word p8_pid, p8_process_name, p8_process_state, p8_registers, p8_HI_register, p8_LO_register, p8_PC, p8_nPC

	#Process 9 space allocation
	p9_pid: .space 4
	p9_process_name: .space 256
	p9_process_state: .space 4
	p9_registers: .space 128
	p9_HI_register: .space 4
	p9_LO_register: .space 4
	p9_PC: .space 4
	p9_nPC: .space 4
	p9_process_table_entry: .word p9_pid, p9_process_name, p9_process_state, p9_registers, p9_HI_register, p9_LO_register, p9_PC, p9_nPC

	#Process 10 space allocation
	p10_pid: .space 4
	p10_process_name: .space 256
	p10_process_state: .space 4
	p10_registers: .space 128
	p10_HI_register: .space 4
	p10_LO_register: .space 4
	p10_PC: .space 4
	p10_nPC: .space 4
	p10_process_table_entry: .word p10_pid, p10_process_name, p10_process_state, p10_registers, p10_HI_register, p10_LO_register, p10_PC, p10_nPC

	new_line: .asciiz "\n"
	process_name_1: .asciiz "LinearSearch"
	process_name_2: .asciiz "BinarySearch"
	process_name_3: .asciiz "Collatz"
	process_name_4: .asciiz "Palindrome"
	process_table: .word p1_process_table_entry, p2_process_table_entry, p3_process_table_entry, p4_process_table_entry, p5_process_table_entry, p6_process_table_entry, p7_process_table_entry, p8_process_table_entry, p9_process_table_entry, p10_process_table_entry


.text
.globl schedule
.globl main

schedule:						#Getting current process's pid
								li $v0,21
								syscall

								move $t0, $v0

								#Loading size of the process table and saving 4 to use it in multiplication in address calculation
								li $t1, 10
								li $t6, 4

continue_scheduling:			#Calculating current_process = (current_process+1) % process_table.size() to find the
								#next available process and loading its entry's address
								addi $t0, $t0, 1
								div $t0, $t1
								mfhi $t0

								la $t2, process_table
								mult $t0, $t6
								mflo $t7
								add $t2, $t2, $t7
								lw $t3, 0($t2)
								lw $t4, 0($t3)
								
								#Adding 260 to the entry's address to reach to it's status address
								addi $t4, $t4, 260
								lw $t5, 0($t4)

								#If it is status is ready, new available process is found
								beq $t5, 1, found
								#For init process
								beq $t5, 4, found

								j continue_scheduling

found:							#Give control to the newly available process
								move $a0, $t0
								li $v0, 105
								syscall

								

main:							#First load create_init_process syscall number
								#Then load process table's address and scheduler's address
								#Then call the syscall to initialize the init process 
								li $v0, 18
								la $a0, process_table
								la $a1, schedule
								syscall

								#Set random number seed 
								li $v0, 25 
								syscall

								#Generate random number
								li $v0, 24
								syscall
								move $s4,$v0 

								#Setting immediates
								li $t1, 1
								li $t2, 2
								li $t3, 3

								#Checking if random number is 1,2 or 3
								beq $s4, $t1, Option1
								beq $s4, $t2, Option2
								beq $s4, $t3, Option3

Option0: 						#If random number is 0, first process name is loaded
								la $s7, process_name_1
		 						j create

Option1: 						#If random number is 1, second process name is loaded
								la $s7, process_name_2
		 						j create

Option2: 						#If random number is 2, third process name is loaded
								la $s7, process_name_3
		 						j create

Option3: 						#If random number is 3, fourth process name is loaded
								la $s7, process_name_4

create:							#Forking for the first child
								li $v0, 19
								syscall

								move $s0, $v0
								#Checking returned pid value
								beq $s0, $0, child1

								#Forking for the second child
								li $v0, 19
								syscall

								move $s1, $v0

								#Checking returned pid value
								beq $s1, $0, child2

								#Forking for the third child
								li $v0, 19
								syscall

								move $s2, $v0

								#Checking returned pid value
								beq $s2, $0, child3

								#Forking for the fourth child
								li $v0, 19
								syscall

								move $s3, $v0

								#Checking returned pid value
								beq $s3, $0, child4

								#Forking for the fourth child
								li $v0, 19
								syscall

								move $s4, $v0

								#Checking returned pid value
								beq $s4, $0, child5

								j exit 

child1: 						#Execing the first child with the selected process name
								move $a0,$s7
								li $v0, 20
								syscall

child2:							#Execing the second child with the selected process name
								move $a0,$s7
								li $v0, 20
								syscall

child3:							#Execing the third child with the selected process name
								move $a0,$s7
								li $v0, 20
								syscall
		
child4:							#Execing the fourth child with the selected process name
								move $a0,$s7
								li $v0, 20
								syscall

child5:							#Execing the fifth child with the selected process name
								move $a0,$s7
								li $v0, 20
								syscall

exit:							#Waiting first child's pid
								li $v0, 23
								move $a0, $s0
								syscall

								#Waiting second child's pid
								li $v0, 23
								move $a0, $s1
								syscall

								#Waiting third child's pid
								li $v0, 23
								move $a0, $s2
								syscall

								#Waiting fourth child's pid
								li $v0, 23
								move $a0, $s3
								syscall

								#Waiting fifth child's pid
								li $v0, 23
								move $a0, $s4
								syscall
		
								jr $ra