.data
	list: .word 3, 4, 3, 9, 7, 4, 1, 2
	targetNumber: .word 9
	size: .word 8
	indexPrompt: .asciiz "\nTarget number found at index: "
	arrayPrompt: .asciiz "Given array is: "
	targetNumberPrompt: .asciiz "\nTarget number is: "
	newLine: .asciiz "\n"
	space: .asciiz " "

.text
.globl main

main:				la $t0, list
					li $t2, 0
					lw $t3,size
					lw $t4, targetNumber

					li $v0, 4       
					la $a0, arrayPrompt     
					syscall 

arrayprintloop:		beq $t2, $t3, targetNumberPrint
					li $v0, 1 
					lw $a0, 0($t0)
					syscall 

					li $v0, 4       
					la $a0, space     
					syscall 
			
					addi $t0, $t0, 4
					addi $t2, $t2, 1
					j arrayprintloop

targetNumberPrint:  li $v0, 4       
					la $a0, targetNumberPrompt     
					syscall 
					li $v0, 1 
					lw $a0, targetNumber
					syscall 

loopinit: 			la $t0, list
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
		    		
endMain: 			jr   $ra