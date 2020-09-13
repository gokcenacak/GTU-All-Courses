.data
	pidList: .space 40
	linearSearch: .asciiz "LinearSearch"
	binarySearch: .asciiz "BinarySearch"
	collatz: .asciiz "Collatz"
	
.text
.globl main

main:					li $v0, 22	#initialize init process
						syscall

						li $v0, 24 #initialize random seed
						syscall

						li $s0, 0
						li $s1, 1
						li $s2, 2
						la $t0, pidList

						li $v0, 23
						syscall
						move $s3,$v0 #random number

						beq $s3, $s1, Option1
						beq $s3, $s2, Option2
		
Option0: 				la $s7, linearSearch
		 				j loop_init

Option1: 				la $s7, binarySearch
		 				j loop_init

Option2: 				la $s7, collatz
		 	
loop_init: 				li $s4, 0
						li $s5, 10

loop:					beq $s4, $s5, wait_pid_loop_init

						li $v0, 18	#fork
						syscall
						move $s6, $v0 #pid

						beq $s6, $0, exec

						sw $s6, 0($t0)
						addi $t0, $t0, 4
						addi $s4, $s4, 1
						j loop

exec:					li $v0, 19	#exec
						move $a0, $s7
						syscall

wait_pid_loop_init:     li $s4, 0
					    li $s5, 10
					    la $t0, pidList

wait_pid_loop:		    beq $s4, $s5, endmain
						lw $a0, 0($t0)
						li $v0, 20	#waitpid
						syscall
						addi $t0, $t0, 4
						addi $s4, $s4, 1
						j wait_pid_loop

 
endmain:				jr $ra