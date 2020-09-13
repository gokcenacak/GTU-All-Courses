.data
	twoDots: .asciiz ":"
	space: .asciiz " "
	newLine: .asciiz "\n"
	title: .asciiz "__________COLLATZ__________\n"

.text
.globl main

main:		#Setting immediates
			li $t0, 25
			li $s1, 0
			li $s2, 2
			li $s3, 3
			li $s4, 1

			#Printing the title
			li $v0, 4     
			la $a0, title     
			syscall 

loop: 		beq $t0, $s1, end

			#Printing newline
			li $v0, 4     
   			la $a0, newLine     
    		syscall  

    		#Printing the integer
			li $v0, 1       
   			move $a0, $t0     
    		syscall  

    		#Printing :
			li $v0, 4     
   			la $a0, twoDots     
    		syscall  

    		#1's print is different so if number is 1 jumps to printOne
  			beq $t0, 1, printOne

  			#Putting number to a temp to calculate the sequence
			move $t1, $t0
			#Decrement by 1 for loop
			sub $t0, $t0, 1

sequence:	sub $s6, $t1, $s4  
			beq $s6, 0, loop
			#Checking if the number is even or odd
			div $t1, $s2
			mfhi $s5
			beq $s5, 0, even

odd:		#If odd multiply by 3 and add 1
			mult $t1, $s3
			mflo $t1
			addi $t1, $t1, 1
			j printNumber

even:		#If even divide by 2
			div $t1,$s2
			mflo $t1

printNumber: #Print the number
			li $v0, 1       
   			move $a0, $t1     
    		syscall
    		#Print a space
    		li $v0, 4     
   			la $a0, space     
    		syscall  

    		j sequence

printOne:	#Print the number
			li $v0, 1       
   			move $a0, $t0     
    		syscall
    		#Print a space
    		li $v0, 4     
   			la $a0, space     
    		syscall  
    		sub $t0, $t0, 1

    		j loop

end: 		#Process exit syscall
			li $v0, 22
			syscall




