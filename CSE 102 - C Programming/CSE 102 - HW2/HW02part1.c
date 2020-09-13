/*                  HW02_Gokce_Nur_Erer_171044079_part1.c					  */
/*                         Gokce Nur Erer 171044079    						  */
/*----------------------------------------------------------------------------*/
/*								DESCRIPTION									  */
/* This program takes a student count from the user and creates random grades */
/* according to that student count. Then it shows options to user to choose to*/
/* find some values among them like: he most successful, the most unsuccessful*/
/* letter grades, letter grade statistics and average of the grades			  */
/* This program exits when -1 is chosen at selection menu, and it warns user  */
/* whenever a wrong selection/count is given. PS: program takes student count */
/* between 3 and 50.														  */

#include <stdio.h>
#include <stdlib.h>

/*menu function prints out the options to choose						      */
void menu(int student_count){
	printf("\n--------------------------------------------\n");
	printf("Student Score Calculator Menu for %d Students\n",student_count);
	printf("1) Most Successful Student\n");
	printf("2) Most Unsuccessful Student\n");
	printf("3) Letter Grade Statistics\n");
	printf("4) Calculate Average\n");
	printf("5) Show all data\n");
	printf("\t\t\t Make Selection:");
}
/*letter_grade function determines the letter grade of a number 90-100 is A	  */
/*80-89 is B, 70-79 is C 60-90 is D and 0-59 is F. After finding the letter   */
/*grade it returns the character value of that letter grade      			  */
char letter_grade(int num){
	if(90<=num && num<100){
		return 'A';
	}
	if(80<=num && num<90){
		return 'B';
	}
	if(70<=num && num<80){
		return 'C';
	}
	if(60<=num && num<70){
		return 'D';
	}
	if(0<=num && num<60){
		return 'F';
	}
}

int main(){
	int student_count,i,selection,num,a=0,b=0,c=0,d=0,f=0;
	int x=0,succ_index=0,unsucc_index=0,success=0,unsuccess=101;
	double average,sum=0;

		/*Getting student count from user*/
		printf("Enter student count:");
		scanf("%d",&student_count);
		srand(40);

			/*Program will give an error message and take student_count again 
			until it is entered correctly (between 3-50)*/
			while(!(student_count>=3 && student_count<=50)){
				printf("\nNot in range!!\n");
				printf("Enter student count:");
				scanf("%d",&student_count);
				
			}
			/*Program will start working if the student_count is between 3-50*/
			if(student_count>=3 && student_count<=50){
				printf("\n");
				/*Creating random grades according to student_count*/
				for(i=0;i<student_count;i++){
					num=rand()%100;
					/*Calculating sum and average*/
					sum+=num;
					average=sum/student_count;
					/*Printing the number to screen*/
					printf("%-2d ",num);
					   /*A x variable is incremented because this program prints
					   10 grades per line and x holds the student count for that 
					   time and if x is divisible by 10 it jumps to next line to 
					   print*/
						x++;
						if(x%10==0){
							printf("\n");
						}
						/*This if statement decides if the number is bigger than
						that current successful student and if it is, it changes
						the value of the successful.*/
						if(success<num){
							success=num;
							succ_index=x;
						}
						/*This if statement decides if the number is smaller or
						equal to that current unsuccessful student and if it is,
						it changes the value of the unsuccessful.*/			
						if(num<=unsuccess){
							unsuccess=num;
							unsucc_index=x;
						}
						/*These statements are used to calculate the total of 
						students at each letter grade*/
						if(letter_grade(num)=='A'){
							a++;
						}
						if(letter_grade(num)=='B'){
							b++;
						}
						if(letter_grade(num)=='C'){
							c++;
						}
						if(letter_grade(num)=='D'){
							d++;
						}
						if(letter_grade(num)=='F'){
							f++;
						}
				}
			/*Printing the menu and getting the selection from user*/
			menu(student_count);
			scanf("%d",&selection);
			/*According to selection it prints the most successful student for 1
			,prints the most unsuccessful student for 2, prints the letter grade
			statistics for 3,prints average on 4 and prints all the information
			from above at 5, it exits the program when user enters -1 and it 
			informs the user if none of the selections above is selected and 
			runs the menu and selection again like at all the selection except
			-1.*/
			while(selection!=-1){
				switch(selection){
					case 1: printf("\nMost Successful Student:\n");
							printf("Index: %d\n",succ_index);
							printf("Score: %d\n",success);
							printf("Letter Grade: %c\n",letter_grade(success));
							selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;

					case 2:	printf("\nMost Unsuccessful Student:\n");
			 				printf("Index: %d\n",unsucc_index);
							printf("Score: %d\n",unsuccess);
							printf("Letter Grade: %c\n",letter_grade(unsuccess));
						 	selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;

					case 3: printf("\n%d students got letter grade 'A'\n",a);
							printf("%d students got letter grade 'B'\n",b);
							printf("%d students got letter grade 'C'\n",c);
							printf("%d students got letter grade 'D'\n",d);
							printf("%d students got letter grade 'F'\n",f);
							selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;

					case 4:	printf("\nThe average score of %d students is: %.2f",student_count,average);
							selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;

					case 5: printf("\nMost Successful Student:\n");
							printf("Index: %d\n",succ_index);
							printf("Score: %d\n",success);
							printf("Letter Grade: %c\n",letter_grade(success));
							printf("\nMost Unsuccessful Student:\n");
			 				printf("Index: %d\n",unsucc_index);
							printf("Score: %d\n",unsuccess);
							printf("Letter Grade: %c\n",letter_grade(unsuccess));
							printf("\n%d students got letter grade 'A'\n",a);
							printf("%d students got letter grade 'B'\n",b);
							printf("%d students got letter grade 'C'\n",c);
							printf("%d students got letter grade 'D'\n",d);
							printf("%d students got letter grade 'F'\n",f);
							printf("\nThe average score of %d students is: %.2f",student_count,average);
							selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;

					default:printf("False Selection!!\n");
							selection=-1;
							menu(student_count);
							scanf("%d",&selection);
							break;
						}
			
					}
			}
	return 0;
}
