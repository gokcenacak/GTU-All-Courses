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

main: 				li $v0, 4     
   					la $a0, title     
    				syscall 
					li $t0, 0
					la $s0, list
					lw $s2, size
					li $s3, 4
					subu $s2, $s2, 1
		  			li $v0, 4       
		  			la $a0, arrayPrompt     
		  			syscall 

arrayprintLoop:	    sub $t1, $t0, $s2 #i
					bgtz $t1, printtargetnumber
					mult $t0, $s3
					mflo $t2
					add $t2, $t2, $s0

					li $v0, 1 
			  		lw $a0, 0($t2)
					syscall 

					li $v0, 4       
					la $a0, space     
					syscall 

					addi $t0, $t0, 1
					j arrayprintLoop

printtargetnumber:  li $v0, 4       
		  			la $a0, targetNumberPrompt     
		  			syscall 

		  			li $v0, 1 
			  		lw $a0, targetNumber
					syscall 

					li $v0, 4       
					la $a0, newLine     
					syscall 


loopinit:			li $s0,2
				  	li $s1,4
				  	lw $s3, targetNumber

				  	#start index
				  	li $t0,0

				  	#end index 
				  	lw $t1,size
				  	subu $t1, $t1, 1

loop: 				sub $t8, $t0, $t1
				  	bgtz $t8, endMain
				  	la, $s2, list

				  	#middle index
				  	sub $t2, $t1, $t0
				  	div $t2,$s0
				  	mflo $t2
				  	add $t2, $t2, $t0

				  	#address of the middle index
				  	mult $t2, $s1
				  	mflo $t4
				  	add $t5, $s2, $t4
				  	
				  	#value at the middle index
				  	lw $t6, 0($t5)
				  	sub $t7, $t6, $s3

				  	beq $t7, 0, found
				  	bltz $t7, checkRight
				  	bgtz $t7, checkLeft


found: 				li $v0, 4       
			       	la $a0, indexPrompt     
			       	syscall 

				   	li $v0, 1       
				   	move $a0, $t2     
			       	syscall 
			       	li $v0, 4       
					la $a0, newLine     
					syscall 
			       	j endMain

checkLeft: 			subu $t1, $t2, 1
		   			j loop

checkRight: 		addi $t0, $t2, 1
					j loop

endMain:   			li $v0, 21
					syscall

					