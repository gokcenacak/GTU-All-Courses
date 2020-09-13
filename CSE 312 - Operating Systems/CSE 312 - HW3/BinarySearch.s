.data
	list: .word 2, 6, 7, 8, 9, 10, 12
	targetNumber: .word 12
	size: .word 7
	indexPrompt: .asciiz "Target number found at index: "
	newLine: .asciiz "\n"
	space: .asciiz " "
	arrayPrompt: .asciiz "Given array is: "
	targetNumberPrompt: .asciiz "\nTarget Number is: "
	title: .asciiz "__________BINARY SEARCH__________\n"


.text
.globl main

main: 				#Printing title
					li $v0, 4     
   					la $a0, title     
    				syscall 
    				#Setting immediates
					li $t0, 0
					la $s0, list
					lw $s2, size
					li $s3, 4

					subu $s2, $s2, 1
					#Printing array prompt
		  			li $v0, 4       
		  			la $a0, arrayPrompt     
		  			syscall 

arrayprintLoop:	    #Printing the array
					sub $t1, $t0, $s2 
					bgtz $t1, printtargetnumber
					mult $t0, $s3
					mflo $t2
					add $t2, $t2, $s0
					#Printing the number
					li $v0, 1 
			  		lw $a0, 0($t2)
					syscall 
					#Printing the space
					li $v0, 4       
					la $a0, space     
					syscall 
					#Incrementing by 1 for the loop
					addi $t0, $t0, 1
					j arrayprintLoop

printtargetnumber:  #Printing target number prompt
					li $v0, 4       
		  			la $a0, targetNumberPrompt     
		  			syscall 
		  			#Print target number
		  			li $v0, 1 
			  		lw $a0, targetNumber
					syscall 
					#Print newline
					li $v0, 4       
					la $a0, newLine     
					syscall 


loopinit:			#Setting immediates
					li $s0,2
				  	li $s1,4
				  	lw $s3, targetNumber

				  	#Start index
				  	li $t0,0

				  	#End index 
				  	lw $t1,size
				  	subu $t1, $t1, 1

loop: 				sub $t8, $t0, $t1
				  	bgtz $t8, endMain
				  	la, $s2, list

				  	#Calculating middle index
				  	sub $t2, $t1, $t0
				  	div $t2,$s0
				  	mflo $t2
				  	add $t2, $t2, $t0

				  	#Calculating address of the middle
				  	mult $t2, $s1
				  	mflo $t4
				  	add $t5, $s2, $t4
				  	
				  	#Getting the value at the middle index
				  	lw $t6, 0($t5)
				  	sub $t7, $t6, $s3

				  	#If subtraction value is 0 than the number is found
				  	beq $t7, 0, found
				  	#If subtraction value is less than 0 the number must be looked in right
				  	bltz $t7, checkRight
				  	#If the subtraction value is bigger than 0 the number must be looked in left
				  	bgtz $t7, checkLeft


found: 				#Printing index prompt
					li $v0, 4       
			       	la $a0, indexPrompt     
			       	syscall 
			       	#Printing index
				   	li $v0, 1       
				   	move $a0, $t2     
			       	syscall 
			       	#Printing newline
			       	li $v0, 4       
					la $a0, newLine     
					syscall 
			       	j endMain

checkLeft: 			#Decrement by one to check left
					subu $t1, $t2, 1
		   			j loop

checkRight: 		#Increment by one to check right
					addi $t0, $t2, 1
					j loop

endMain:   			#Process exit syscall
					li $v0, 22
					syscall


					