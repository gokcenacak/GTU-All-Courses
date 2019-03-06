.data

read_file: .asciiz "input_hw1.txt"
buffer: .space 256
zero: .asciiz "zero"
one: .asciiz "one"
two: .asciiz "two"
three: .asciiz "three"
four: .asciiz "four"
five: .asciiz "five"
six: .asciiz "six"
seven: .asciiz "seven"
eight: .asciiz "eight"
nine: .asciiz "nine"
zeroupper: .asciiz "Zero"
oneupper: .asciiz "One"
twoupper: .asciiz "Two"
threeupper: .asciiz "Three"
fourupper: .asciiz "Four"
fiveupper: .asciiz "Five"
sixupper: .asciiz "Six"
sevenupper: .asciiz "Seven"
eightupper: .asciiz "Eight"
nineupper: .asciiz "Nine"

.text

main:
	#opening the file
	li $v0, 13
	la $a0,read_file
	li $a1,0
	li $a2,0
	syscall
	move $s6,$v0 #saving the file address

	#reading from file
	li $v0, 14
	move $a0,$s6
	la $a1,buffer
	li $a2,256
	syscall

	jal number_check

	#closing the file
 	li   $v0, 16      
 	move $a0, $s6      
 	syscall 
	
	#Closing the program
	li $v0,10
	syscall

number_check:
	addi $t0, $zero ,0

	loop:
		lb $s0,buffer($t0)
		beq $s0,$zero,end_loop #loop until it is null character
		beq $s0,'0',zeroprint
		beq $s0,'1',oneprint
		beq $s0,'2',twoprint
		beq $s0,'3',threeprint
		beq $s0,'4',fourprint
		beq $s0,'5',fiveprint
		beq $s0,'6',sixprint
		beq $s0,'7',sevenprint
		beq $s0,'8',eightprint
		beq $s0,'9',nineprint
		addi $t0,$t0,1 # loop increment
		
	    print:
	  	li $v0,11 #printing the character
		move $a0,$s0
		syscall
		j loop

	end_loop: 
		jr $ra

			zeroprint:  
						addi $t1,$t0,-1 #i-1
	   					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    			
	   					#checks if i+1 is a number
   	   					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck0
           	       	       isNextNumCheck0: bge $s1,'0',print
           	       	       
           					#checks if i-1 is a number      
           					lb $s4,buffer($t1)
           					ble $s4,'9',isPrevNumCheck0
           		       isPrevNumCheck0: bge $s4,'0',print
           		       
           					#Checks if the number is at the beginning of the sentence
          					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck0
  	    		  	   upperCheck0: beq $s3,'.',upperzero
  	    		  	   
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
  	  					#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	   					beq $s1,'.',endOfSentenceCheck0
  	    					j lowerzero
  	    		   endOfSentenceCheck0: beq $s2,' ',lowerzero
  	    					j print
  	    					
           	    			 	#Printing "zero"
	   	    		     lowerzero: li $v0,4 
      	    					la $a0,zero
           					syscall
            					j loop
            					
            	    				#Printing "Zero"
            	     		     upperzero: li $v0,4 
      	    					la $a0,zeroupper
            					syscall
            					j loop
            
			oneprint:  
 						addi $t1,$t0,-1
          					addi $t0,$t0,1 # loop increment
	  					addi $t2,$t0,1
	  					addi $t3,$t1,-1 #i-2
	  					
	  					#Checks if i+1 is a number
            					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck1
           		       isNextNumCheck1: bge $s1,'0',print
  	
  	  					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck1
           		       isPrevNumCheck1: bge $s4,'0',print
  	  
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	   					beq $s4,' ',upperCheck1
  	    			   upperCheck1: beq $s3,'.',upperone
  	    
  	      	    				#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    					
  	      	  				#checks if i+1 is a . and i+2 a blank to check the end of the sentence
  	   					lb $s2,buffer($t2)
  	   					beq $s1,'.',endOfSentenceCheck1
  	    					j lowerone
  	    		   endOfSentenceCheck1: beq $s2,' ',lowerone
  	    					j print
             
             					#Printing "one"
	   			      lowerone: li $v0,4 
      	   				        la $a0,one
            					syscall
            					j loop
            					
            					#Printing "One"
          			      upperone: li $v0,4 
      	    				        la $a0,oneupper
                			        syscall
            				        j loop
       
            
			twoprint:   		
						addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	   					addi $t3,$t1,-1 #i-2
	   					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck2
           		       isNextNumCheck2: bge $s1,'0',print
           
           					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck2
           		       isPrevNumCheck2: bge $s4,'0',print
           
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck2
  	    			   upperCheck2: beq $s3,'.',uppertwo
  	    
  	   					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
						#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck2
  	    					j lowertwo
  	    		   endOfSentenceCheck2: beq $s2,' ',lowertwo
  	    					j print
           
          					#Printing "two"
	    			      lowertwo: li $v0,4 
      	   					la $a0,two
           					syscall
              					j loop
              					
            					#Printing "Two"
           			      uppertwo: li $v0,4 
      	   					la $a0,twoupper
            					syscall
            					j loop
            
			threeprint: 		addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	   					addi $t3,$t1,-1 #i-2
	   					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck3
           		       isNextNumCheck3: bge $s1,'0',print
           
            					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck3
           		       isPrevNumCheck3: bge $s4,'0',print
           
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck3
  	    			   upperCheck3: beq $s3,'.',upperthree
  	    
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
						#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck3
  	    					j lowerthree
  	    		   endOfSentenceCheck3: beq $s2,' ',lowerthree
  	    					j print

						#Printing "three"
	    			    lowerthree: li $v0,4 
      	    					la $a0,three
            					syscall
            					j loop
            					
            					#Printing "three"
            			    upperthree: li $v0,4 
      	    					la $a0,threeupper
            					syscall
            					j loop
   
            
			fourprint: 
 	    					addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck4
           		       isNextNumCheck4: bge $s1,'0',print
           
           					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
           					ble $s4,'9',isPrevNumCheck4
           		       isPrevNumCheck4: bge $s4,'0',print
          			
          			 		#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck4
  	    			   upperCheck4: beq $s3,'.',upperfour
  	    			   
  	   				 	#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
						#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck4
  	   					j lowerfour
  	    					endOfSentenceCheck4:beq $s2,' ',lowerfour
  	    					j print
  	    					
          					#printing "four"
	    			     lowerfour: li $v0,4 
      	    					la $a0,four
            					syscall
            					j loop
            					
                      				#printing "Four"
            			     upperfour: li $v0,4 
      	    					la $a0,fourupper
            					syscall
            					j loop
	
	    
			fiveprint:  
   	   			 		addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	   					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck5
           		       isNextNumCheck5: bge $s1,'0',print
           					
            					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck5
            		       isPrevNumCheck5: bge $s4,'0',print
                      
                     				#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck5
  	    			   upperCheck5: beq $s3,'.',upperfive
  	    
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print
  	    
  	    					#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
						beq $s1,'.',endOfSentenceCheck5
  	    					j lowerfive
  	    		   endOfSentenceCheck5: beq $s2,' ',lowerfive
  	    					j print
          					
          					#Printing "five"
	    			      lowerfive:li $v0,4 
      	   					la $a0,five
            					syscall
            					j loop
            
            					#Printing "Five"
            			     upperfive: li $v0,4 
      	    					la $a0,fiveupper
            					syscall
            					j loop
	
            
			sixprint:   
    						addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck6
           		       isNextNumCheck6: bge $s1,'0',print
           
             					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck6
           		       isPrevNumCheck6: bge $s4,'0',print
           
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck6
  	    			   upperCheck6: beq $s3,'.',uppersix
  	    
						#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
  	    					#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck6
  	    					j lowersix
  	    		   endOfSentenceCheck6: beq $s2,' ',lowersix
  	    					j print

						#Printing "six"
	    			      lowersix: li $v0,4 
      	    					la $a0,six
            					syscall
            					j loop
            					#Printing "Six"
            			      uppersix: li $v0,4 
      	    					la $a0,sixupper
            					syscall
            					j loop
            
			sevenprint: 
    						addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck7
           		       isNextNumCheck7: bge $s1,'0',print
           
             					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck7
           		       isPrevNumCheck7: bge $s4,'0',print
           
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck7
  	   		 	   upperCheck7: beq $s3,'.',upperseven
  	    
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
						#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck7
  	    					j lowerseven
  	    		   endOfSentenceCheck7: beq $s2,' ',lowerseven
  	    					j print

           					#Printing "seven"
	    			    lowerseven: li $v0,4 
      	    					la $a0,seven
						syscall
            					j loop
            					
                       				#Printing "Seven"
            			    upperseven: li $v0,4 
      	    					la $a0,sevenupper
            					syscall
            					j loop
            
			eightprint: 
  	    					addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck8
           		       isNextNumCheck8: bge $s1,'0',print
           
             					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck8
           		       isPrevNumCheck8: bge $s4,'0',print
           
           
						#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck8
  	    			   upperCheck8: beq $s3,'.',uppereight
  	    
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
  	    					#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck8
  	    					j lowereight
  	    		   endOfSentenceCheck8: beq $s2,' ',lowereight
  	    					j print

          					#Printing "eight"
	    			    lowereight: li $v0,4 
      	    					la $a0,eight
            					syscall
            					j loop
            					
                      				#Printing "Eight"
           			    uppereight: li $v0,4 
      	    					la $a0,eightupper
            					syscall
            					j loop
            
			nineprint:  
	   					addi $t1,$t0,-1 #i-1
	    					addi $t0,$t0,1 # loop increment i+1
	    					addi $t2,$t0,1 #i+2
	    					addi $t3,$t1,-1 #i-2
	    					
	    					#checks if i+1 is a number
   	    					lb $s1,buffer($t0)
            					ble $s1,'9',isNextNumCheck9
           		       isNextNumCheck9: bge $s1,'0',print
           
             					#checks if i-1 is a number      
            					lb $s4,buffer($t1)
            					ble $s4,'9',isPrevNumCheck9
           		       isPrevNumCheck9: bge $s4,'0',print
           
           					#Checks if the number is at the beginning of the sentence
           					lb $s3,buffer($t3)
  	    					beq $s4,' ',upperCheck9
  	    			   upperCheck9: beq $s3,'.',uppernine
  	    
  	    					#Checks if i-1 has a ., if so it doesn't print the word, prints the character
  	    					beq $s4,'.',print 
  	    
  	    					#checks if i+1 is a . and i+2 a blank to check the end of the sentence
 	    					lb $s2,buffer($t2)
  	    					beq $s1,'.',endOfSentenceCheck9
  	    					j lowernine
  	    		   endOfSentenceCheck9: beq $s2,' ',lowernine
  	    					j print

          					#Printing "nine"
	    			     lowernine: li $v0,4 
      	    					la $a0,nine
            					syscall
            					j loop
            					
            					#Printing "Nine"
            			     uppernine: li $v0,4 
      	    					la $a0,nineupper
            					syscall
            					j loop


