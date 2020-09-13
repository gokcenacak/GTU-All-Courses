.data
	linearSearch: .asciiz "LinearSearch"
	binarySearch: .asciiz "BinarySearch"
	collatz: .asciiz "Collatz"
	
.text
.globl main

main:	li $v0, 22	#initialize init process
		syscall

		li $v0, 18	#fork
		syscall

		move $s5, $v0

		beq $v0, $0, child1

		li $v0, 18	#fork
		syscall

		move $s4, $v0

		beq $v0, $0, child2

		li $v0, 18	#fork
		syscall

		move $s3, $v0

		beq $v0, $0, child3
		j l1
		
child1:	li $v0, 19	#exec
		la $a0, linearSearch
		syscall

child2: li $v0, 19	#exec
		la $a0, binarySearch
		syscall

child3: li $v0, 19	#exec
		la $a0, collatz
		syscall

l1 : 	li $v0, 20	#waitpid
		move $a0, $s5
		syscall

		li $v0, 20	#waitpid
		move $a0, $s4
		syscall

		li $v0, 20	#waitpid
		move $a0, $s3
		syscall

endmain:	jr $ra