.data
	list: .word 3, 4, 3, 9, 7, 4, 1, 2
	targetNumber: .word 9
	size: .word 8
	indexPrompt: .asciiz "\nTarget number found at index: "
	arrayPrompt: .asciiz "Given array is: "
	targetNumberPrompt: .asciiz "\nTarget number is: "
	newLine: .asciiz "\n"
	space: .asciiz " "
	title: .asciiz "__________LINEAR SEARCH__________\n"
	

.text
.globl main

main:				#Printing title
					li $v0, 4     
   					la $a0, title     
    				syscall 
    				#Loading the list and immediates
					la $t0, list
					li $t2, 0
					lw $t3,size
					lw $t4, targetNumber
					#Printing the array prompt
					li $v0, 4       
					la $a0, arrayPrompt     
					syscall 

arrayprintloop:		#Printing the array
					beq $t2, $t3, targetNumberPrint
					li $v0, 1 
					lw $a0, 0($t0)
					syscall 
					#Printing space
					li $v0, 4       
					la $a0, space     
					syscall 
					#Increments for the array and the loop
					addi $t0, $t0, 4
					addi $t2, $t2, 1
					j arrayprintloop

targetNumberPrint:  #Printing target number prompt
					li $v0, 4       
					la $a0, targetNumberPrompt     
					syscall
					#Printing target number 
					li $v0, 1 
					lw $a0, targetNumber
					syscall 

loopinit: 			#Setting list address and immediates
					la $t0, list
					li $t2, 0
					lw $t3,size
					lw $t4, targetNumber
		
					#Looping in array
loop:				beq $t2, $t3, endMain
					lw $t1, 0($t0)

					#Checking if number is matching with the current number
					beq $t1, $t4, numberFound

					#New index address calculation
					addi $t0, $t0, 4

					#Counter
					addi $t2, $t2, 1
					j loop
		
numberFound:		#Printing the indexPrompt
					li $v0, 4       
		    		la $a0, indexPrompt     
		    		syscall 

					#Printing the number
					li $v0, 1       
		   			move $a0, $t2     
		    		syscall 
		    		#Printing new line
		    		li $v0, 4       
		    		la $a0, newLine     
		    		syscall  
		    		
endMain: 			#Process exit syscall
					li $v0, 22
					syscall
