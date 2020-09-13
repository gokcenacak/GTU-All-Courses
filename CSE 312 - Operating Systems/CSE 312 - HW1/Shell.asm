.data
	newLine: .asciiz "\n"
	space: .asciiz "\n"
	shellPrompt: .asciiz "SPIMOS:~ "
	exit: .asciiz "exit\n"
	command: .space 256

.text
.globl main

main:	li $v0, 4       
		la $a0, shellPrompt     
		syscall 

		li $v0, 8       
		la $a0, command
		li $a1, 256     
		syscall 

		la $a1,exit

cmploop:
	    lb      $t2,0($a0)                   
	    lb      $t3,0($a1)                   
	    bne     $t2,$t3,runcommand              

	    beq     $t2,$zero,exitshell             

	    addi    $a0,$a0,1                  
	    addi    $a1,$a1,1                   
	    j       cmploop

runcommand:	li $v0, 18 
			la $a0, command      
			syscall 

			j main

exitshell: jr $ra