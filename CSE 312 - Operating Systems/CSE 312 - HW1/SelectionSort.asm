.data
	list: .word 5, 4, 6, 1, 2, 3, 10, 7, 4
	size: .word 9
	newLine: .asciiz "\n"
	space: .asciiz " "
	sortedPrompt: .asciiz "The sorted list is: "
	unsortedPrompt: .asciiz "The unsorted list is: "


.text
.globl main

main: 				la $s0, list
					lw $s1, size
					subu $s2, $s1, 1
					li $s3, 4

		  			li $t0, 0
		  			li $v0, 4       
		  			la $a0, unsortedPrompt     
		  			syscall 

unsortedprintLoop:	sub $t1, $t0, $s2 #i
					bgtz $t1, loopinit
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
					j unsortedprintLoop

loopinit:  			li $v0, 4       
		  			la $a0, newLine     
		  			syscall 
					li $t0,0

loop:				sub $t1, $t0, $s2 #i
					bgez $t1, endLoop
					move $t2, $t0 #min_index
					addi $t3, $t0, 1 #j

innerloop: 			sub $t4 $s1, $t3
					mult $t3, $s3
					mflo $v1
					add $v1, $v1, $s0

					blez $t4, endInnerLoop

					mult $t3, $s3
					li $t5, 0
					mflo $t5 #arr[j] address
					add $t5, $t5, $s0
					mult $t2, $s3
					li $t6, 0
					mflo $t6 #arr[min_index] address
					add $t6, $t6, $s0

					lw $t7, 0($t5) #arr[j]
					lw $t8, 0($t6) #arr[min_index]


					sub $t9, $t8, $t7
					blez $t9, ifFailed
					move $t2, $t3
					addi $t3,$t3,1

					j innerloop

ifFailed:			addi $t3,$t3,1
					j innerloop

endInnerLoop:		mult $t0, $s3
					mflo $s4
					add $s4, $s4, $s0
					lw $s5, 0($s4)

					mult $t2, $s3
					mflo $t6 #arr[min_index] address
					add $t6, $t6, $s0

					lw $t8, 0($t6) #arr[min_index]
					addi $t0, $t0, 1

					sw $s5, 0($t6)
					sw $t8, 0($s4)


					j loop

endLoop : 			li $t0, 0
				  	li $v0, 4       
				  	la $a0, sortedPrompt     
				  	syscall 

printLoop:			sub $t1, $t0, $s2 #i
				  	bgtz $t1, endMain
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
				  	j printLoop

endMain:  			li $v0, 4       
		  			la $a0, newLine     
		  			syscall 
		  			jr $ra