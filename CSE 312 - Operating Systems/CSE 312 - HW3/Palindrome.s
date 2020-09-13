.data
	word101: .space 32
	user_input: .space 32

	prompt_is_palindrome: .asciiz ": Palindrome\n"
	prompt_not_palindrome: .asciiz ": Not Palindrome\n"
	seperator: .asciiz ": "
	user_prompt: .asciiz "Do you want to continue (y/n)?\n"
	word_prompt: .asciiz "Please enter the last word:\n"
	wrong_input: .asciiz "Wrong input please enter y or n!\n"
	goodbye_prompt: .asciiz "Goodbye...\n"
	yes: .byte 'y'
	no: .byte 'n'
	end_line: .asciiz "\n"

	word1:  .asciiz "anna"
	word2:  .asciiz "kayak"
	word3:  .asciiz "Mom"
	word4:  .asciiz "Madam"
	word5:  .asciiz "Noon"
	word6:  .asciiz "Wow"
	word7:  .asciiz "Ada"
	word8:  .asciiz "Abba"
	word9:  .asciiz "Level"
	word10: .asciiz "Radar"
	word11: .asciiz "Sport"
	word12: .asciiz "Happy"
	word13: .asciiz "Available"
	word14: .asciiz "Noone"
	word15: .asciiz "Football"
	word16: .asciiz "Operating"
	word17: .asciiz "Systems"
	word18: .asciiz "Homework"
	word19: .asciiz "Three"
	word20: .asciiz "Busy"
	word21: .asciiz "Stressed"
	word22: .asciiz "Good"
	word23: .asciiz "Luck"
	word24: .asciiz "Failure"
	word25: .asciiz "Success"
	word26: .asciiz "Impossible"
	word27: .asciiz "Kernel"
	word28: .asciiz "Flavor"
	word29: .asciiz "Palindrome"
	word30: .asciiz "Collatz"
	word31: .asciiz "Input"
	word32: .asciiz "Output"
	word33: .asciiz "Hesitate"
	word34: .asciiz "Cat"
	word35: .asciiz "Dog"
	word36: .asciiz "Alan"
	word37: .asciiz "Turing"
	word38: .asciiz "Computer"
	word39: .asciiz "Keyboard"
	word40: .asciiz "Mouse"
	word41: .asciiz "Hedgehog"
	word42: .asciiz "Fox"
	word43: .asciiz "Bunny"
	word44: .asciiz "Penguin"
	word45: .asciiz "Long"
	word46: .asciiz "Short"
	word47: .asciiz "Fat"
	word48: .asciiz "Thin"
	word49: .asciiz "Rich"
	word50: .asciiz "Poor"
	word51: .asciiz "Coffee"
	word52: .asciiz "Tea"
	word53: .asciiz "Series"
	word54: .asciiz "Phone"
	word55: .asciiz "Cafe"
	word56: .asciiz "Vaccination"
	word57: .asciiz "Doctor"
	word58: .asciiz "Nurse"
	word59: .asciiz "Corona"
	word60: .asciiz "Bored"
	word61: .asciiz "Number"
	word62: .asciiz "Words"
	word63: .asciiz "Picture"
	word64: .asciiz "Hoping"
	word65: .asciiz "To"
	word66: .asciiz "Get"
	word67: .asciiz "High"
	word68: .asciiz "From"
	word69: .asciiz "This"
	word70: .asciiz "Assignment"
	word71: .asciiz "Worked"
	word72: .asciiz "Really"
	word73: .asciiz "Hard"
	word74: .asciiz "On"
	word75: .asciiz "It"
	word76: .asciiz "Thanks"
	word77: .asciiz "Have"
	word78: .asciiz "Safe"
	word79: .asciiz "And"
	word80: .asciiz "Healthy"
	word81: .asciiz "Days"
	word82: .asciiz "Car"
	word83: .asciiz "Bus"
	word84: .asciiz "Motorcycle"
	word85: .asciiz "Holiday"
	word86: .asciiz "Exams"
	word87: .asciiz "Projects"
	word88: .asciiz "Gebze"
	word89: .asciiz "Technical"
	word90: .asciiz "University"
	word91: .asciiz "Pencils"
	word92: .asciiz "Notebooks"
	word93: .asciiz "Papers"
	word94: .asciiz "Students"
	word95: .asciiz "Teachers"
	word96: .asciiz "Vacation"
	word97: .asciiz "Close"
	word98: .asciiz "To"
	word99: .asciiz "Finish"
	word100: .asciiz "Dictionary"

	

	dictionary: .word word1, word2, word3, word4, word5, word6, word7, word8, word9, word10, word11, word12, word13, word14, word15, word16, word17, word18, word19, word20, word21, word22, word23, word24, word25, word26, word27, word28, word29, word30, word31, word32, word33, word34, word35, word36, word37, word38, word39, word40, word41, word42, word43, word44, word45, word46, word47, word48, word49, word50, word51, word52, word53, word54, word55, word56, word57, word58, word59, word60, word61, word62, word63, word64, word65, word66, word67, word68, word69, word70, word71, word72, word73, word74, word75, word76, word77, word78, word79, word80, word81, word82, word83, word84, word85, word86, word87, word88, word89, word90, word91, word92, word93, word94, word95, word96, word97, word98, word99, word100

.text
.globl main

get_str_length:				#Stack pointer and return address adjustments
							sub $sp, $sp,4
							sw $ra, 0($sp)
							#Setting length to 0
							li $t5, 0
							move $t0, $a0

get_str_length_loop:		#Get the character
							lb $t1, 0($t0) 
							#Check if null character is reached
							beq $t1, $zero, return_str_length 
							#Checking if new line character is reached
							beq $t1, '\n', return_str_length
							#Get the next character's address
							addi $t0, $t0, 1
							#Increment length
							addi $t5, $t5, 1
							j get_str_length_loop

return_str_length: 			#Move length to return register
							move $v0, $t5
							#Stack pointer and return address adjustments
							lw $ra, 0($sp)
							addi $sp, $sp, 4
							jr $ra 


is_palindrome:				#Stack pointer and return address adjustments
							sub $sp, $sp, 8 #Allocating space in stack
							sw  $ra 0($sp) #Save the return address
							sw  $a0 4($sp) #Save argument

							#Call get length
							jal get_str_length

							#Saving string length
							move $t0, $v0

							#Get back the argument from stack
							lw $a0 4($sp)
							#Save the string's address in a temp register
							move $t1, $a0
							#Assuming its a palindrome and setting the return value to 1
							li $v0, 1
							#Set counter to 0
							li $t2, 0
							#Calculating the middle index of the string
							div $t3, $t0, 2
							#Add 1 if string length is even
							addi $t3, $t3, 1 

is_palindrome_loop:			beq $t2, $t3, return_is_palindrome
							#Get the character from left
							lb $t4, 0($t1)
							#Calculating the index of the other character which will be compared with the character from the left
							sub $t5, $t0, $t2 
							subu $t5, $t5, 1
							#Calculating the address by adding index to string's starting address
							add $t6, $t5, $a0 
							#Get the other character from right
							lb $t7, 0($t6)

							#Checking if the character from the left is a lowercased character
							bge $t4, 97, check_right_case
							#If not make it lowercase
							addi $t4, $t4, 32

check_right_case:			#Checking if the character from the right is a lowercased character
							bge $t7, 97, continue_comparison
							#If not make it lowercase
							addi $t7, $t7, 32

continue_comparison:		#If the characters are equal continue
							beq $t4, $t7, continue_palindrome_loop
							#Else, it is not a palindrome and setting the return value to 0
							li $v0, 0 
							j return_is_palindrome

continue_palindrome_loop:	#Increment counters
							addi $t2, $t2, 1
							addi $t1, $t1, 1
							j is_palindrome_loop

return_is_palindrome:		#Load back return address
							lw $ra 0($sp)
							#Free stack
							addi $sp, $sp, 8 
							jr $ra


clear_newline:				#Stack pointer and return address adjustments
							sub $sp, $sp,4
							sw $ra, 0($sp)

							move $t0, $a0

loop_clear_newline:			#Get the character
							lb $t1, 0($t0)
							#Check if null character is reached
							beq $t1, $zero, return_clear_newline
							#Get next character's address
							addi $t0, $t0, 1
							#Check if current character is new line
							bne $t1, '\n', loop_clear_newline
							#If it is put a null instead of it
							subu $t0, $t0, 1
							li $t2, 0
							sb $t2, 0($t0)
							addi $t0,$t0, 1
							j loop_clear_newline

return_clear_newline:		#Stack pointer and return address adjustments
							lw $ra, 0($sp)
							addi $sp, $sp, 4
							jr $ra

main:						#Stack pointer and return address adjustments
							subu $sp, $sp, 4
							sw $ra, 0($sp)
							#Setting up immediates and setting up dictonary address
							la $s0, dictionary
							li $s1, 1
							li $s2, 101

loop:						#If 100 words are printed jump to user input asking
							beq $s1,$s2, ask_user
							
							#Printing number
							li $v0,1			
							move $a0, $s1
							syscall

							#Printing :
							li $v0,4			
							la $a0, seperator
							syscall

							#Printing the word
							li $v0,4			
							lw $a0, 0($s0)
							syscall

							#Calling is palindrome
							jal is_palindrome

							#Checking if return value is 1
							beq $v0, 1, print_is_palindrome

							#If it is 0 print not palindrome
							li $v0, 4
							la $a0, prompt_not_palindrome
							syscall
							j continue

print_is_palindrome:		#If it is 1 print is palindrome
							li $v0, 4			
							la $a0, prompt_is_palindrome
							syscall

continue:					#Increment counters
							addi $s0, $s0, 4
							addi $s1, $s1, 1

							j loop
							

ask_user:					#Print user prompt
							li $v0,4
							la $a0, user_prompt
							syscall

							#Get y or n from user
							li $v0, 8
							la $a0, user_input
							li $a1, 32
							syscall
							#Getting string length of the input
							jal get_str_length
							move $t5, $v0
							#Checking if entered input has a length of 1, if not jump to false input
							bne $t5, 1, false_input

							la $a0,user_input
							#Getting and checking the user input if it is y get the string from user, if n exit
							lb $v0, 0($a0)
							beq $v0, 'y', get_string
							beq $v0, 'n', exit

false_input:				#Print wrong input prompt and jump to asking input to user again
							li $v0,4			
							la $a0, wrong_input
							syscall

							j ask_user

get_string:					#Print word asking prompt to user
							li $v0,4
							la $a0, word_prompt
							syscall

							#Get string input from user
							li $v0, 8
							la $a0, word101
							li $a1, 32
							syscall							

							#Printing number
							li $v0,1
							move $a0, $s2
							syscall

							#Printing :
							li $v0,4			
							la $a0, seperator
							syscall

							la $a0, word101
							#Clearing newlines in the user entered word
							jal clear_newline

							#Printing the user entered word
							li $v0,4
							syscall

							la $a0, word101

							#Check if word is a palindrome
							jal is_palindrome

							beq $v0, 1, user_input_is_palindrome

							#If it is not a palindrome print "not palindrome"
							li $v0, 4			
							la $a0, prompt_not_palindrome
							syscall

							j exit

user_input_is_palindrome:	#If it is not a palindrome print "palindrome"
							li $v0, 4
							la $a0, prompt_is_palindrome
							syscall

exit:						#Print goodbye prompt
							li $v0, 4 
							la $a0, goodbye_prompt
							syscall

							#Stack pointer and return address adjustments
							lw $ra, 0($sp)
							addi $sp, $sp, 4

							#Process exit system call
							li $v0, 22
							syscall


