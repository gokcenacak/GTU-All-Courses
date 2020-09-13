 .data
	space		: .asciiz " "
	startNumberPrompt: .asciiz "Enter the first number:\n"
	endNumberPrompt: .asciiz "Enter the second number:\n"
	divisibleByPrompt: .asciiz "Show numbers divisible by:\n"
	newLine : .asciiz "\n"

.text
.globl main

main:   		#Loading the numbers to registers
				#lw $t1, startNumber
				#lw $t2, endNumber
				#lw $t3, divisibleBy

				li $v0, 4       
        		la $a0, startNumberPrompt     
        		syscall         
				#Read the first integer
				li $v0, 5       
       			move $a0, $t1     
        		syscall  
        		move $t1, $v0

        		li $v0, 4       
        		la $a0, endNumberPrompt     
        		syscall         
				#Read the second integer
				li $v0, 5       
       			move $a0, $t1     
        		syscall  
        		move $t2, $v0

        		li $v0, 4       
        		la $a0, divisibleByPrompt    
        		syscall         
				#Read the dividing number integer
				li $v0, 5       
       			move $a0, $t1     
        		syscall  
        		move $t3, $v0



				#Storing return address of main procedure to stack 
				subu $sp, 4			
				sw	 $ra, 0($sp)		

				#Looping from the first number to the last number to execute isDivisible
loop:			jal isDivisible
				beq $t1, $t2, endMain
				addi $t1,$t1,1
				j loop

				#Loading from stack to get the return address of main procedure 
endMain:		lw   $ra, 0($sp)		
				addu $sp, $sp, 4

				li $v0, 4       
        		la $a0, newLine     
        		syscall    

				jr   $ra				

isDivisible:	#Storing return address of isDivisible procedure to stack 
				subu $sp, 4			
				sw	 $ra, 0($sp)
				#Getting remainder from hi register		
				div $t1, $t3
				mfhi $t0
				bne $t0, 0, endIsDivisible
				jal showNumber

				#Loading from stack to get the return address of isDivisible procedure 
endIsDivisible:	lw   $ra, 0($sp)		
				addu $sp, $sp, 4	
				jr   $ra				

showNumber: 	#Storing return address of showNumber procedure to stack 
				subu $sp, 4			
				sw	 $ra, 0($sp)		

				#Printing the number
				li $v0, 1       
       			move $a0, $t1     
        		syscall  

        		#Printing space
        		li $v0, 4       
        		la $a0, space    
        		syscall         

				#Loading from stack to get the return address of showNumber procedure 
        		lw   $ra, 0($sp)		
				addu $sp, $sp, 4	
				jr   $ra				
