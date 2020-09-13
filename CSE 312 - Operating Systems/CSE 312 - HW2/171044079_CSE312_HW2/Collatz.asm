.data
	twoDots: .asciiz ":"
	space: .asciiz " "
	newLine: .asciiz "\n"
	title: .asciiz "__________COLLATZ__________\n"

.text
.globl main

main:		li $t0, 1
			li $s1, 26
			li $s2, 2
			li $s3, 3
			li $s4, 1

			li $v0, 4     
			la $a0, title     
			syscall 

loop: 		beq $t0, $s1, end #i

			li $v0, 4     
   			la $a0, newLine     
    		syscall  

			li $v0, 1       
   			move $a0, $t0     
    		syscall  

			li $v0, 4     
   			la $a0, twoDots     
    		syscall  

  			beq $t0, 1, printOne

			move $t1, $t0
			addi $t0, $t0, 1

sequence:	
			sub $s6, $t1, $s4  
			beq $s6, 0, loop #j
			div $t1, $s2
			mfhi $s5
			beq $s5, 0, even

odd:		mult $t1, $s3
			mflo $t1
			addi $t1, $t1, 1
			j printNumber

even:		div $t1,$s2
			mflo $t1

printNumber:li $v0, 1       
   			move $a0, $t1     
    		syscall

    		li $v0, 4     
   			la $a0, space     
    		syscall  

    		j sequence

printOne:	li $v0, 1       
   			move $a0, $t0     
    		syscall

    		li $v0, 4     
   			la $a0, space     
    		syscall  
    		addi $t0, $t0, 1

    		j loop

end: 		li $v0, 21
			syscall



