.data
	pidList: .space 24
	linearSearch: .asciiz "LinearSearch"
	binarySearch: .asciiz "BinarySearch"
	collatz: .asciiz "Collatz"
	
.text
.globl main

main:							li $v0, 22	#initialize init process
								syscall

								li $v0, 24 #initialize random seed
								syscall

								li $s0, 0
								li $s1, 1
								li $s2, 2

								la $t2, pidList

								li $v0, 23
								syscall
								move $s3,$v0 #random number

								beq $s3, $s1, Option1
								beq $s3, $s2, Option2
		
Option0: 						la $s7, linearSearch
		 						j loop_init_first_process_type

Option1: 						la $s7, binarySearch
		 						j loop_init_first_process_type

Option2: 						la $s7, collatz
		 
loop_init_first_process_type:	li $t0, 0
								li $t1, 3

loop_first_process_type:		beq $t0, $t1, second_random_number
								li $v0, 18	#fork
								syscall

								move $s5, $v0

								beq $v0, $0, exec_first_process_type
								sw $s5, 0($t2)
								addi $t0, $t0, 1
								addi $t2, $t2, 4
								j loop_first_process_type

exec_first_process_type:		li $v0, 19	#exec
								move $a0, $s7
								syscall

second_random_number:			li $s0, 0
								li $s1, 1
								li $s2, 2
								li $v0, 23
								syscall
								move $s3,$v0 #random number

								beq $s3, $s1, Option1_second_number
								beq $s3, $s2, Option2_second_number
									
Option0_second_number: 			la $s7, linearSearch
		 						j loop_init_second_process_type

Option1_second_number: 			la $s7, binarySearch
		 						j loop_init_second_process_type
		 						
Option2_second_number: 			la $s7, collatz
		 
loop_init_second_process_type:	li $t0, 0
								li $t1, 3

loop_second_process_type:		beq $t0, $t1, wait_pid_loop_init
								li $v0, 18	#fork
								syscall

								move $s5, $v0

								beq $v0, $0, exec_second_process_type
								sw $s5, 0($t2)
								addi $t0, $t0, 1
								addi $t2, $t2, 4
								j loop_second_process_type

exec_second_process_type:		li $v0, 19	#exec
								move $a0, $s7
								syscall

wait_pid_loop_init:    			li $s4, 0
					   			li $s5, 6
					   			la $t2, pidList
					   
wait_pid_loop:		   			beq $s4, $s5, endmain
					   			lw $a0, 0($t2)
					   			li $v0, 20	#waitpid
					   			syscall
					   			addi $t2, $t2, 4
					   			addi $s4, $s4, 1
					   			j wait_pid_loop

 
endmain:						jr $ra