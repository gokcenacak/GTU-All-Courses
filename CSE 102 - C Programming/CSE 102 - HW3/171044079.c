/*                              171044079.c									  */
/*                       Gökçe Nur Erer 171044079							  */
/*								HOMEWORK-03									  */
/*							    DESCRIPTION									  */
/*The objective of this program is to implement a program which contains some */
/*sub-programs like horse racing game, count occurrence and triangle of 	  */
/*sequences.																  */
/*This code includes time.h and stdlib.h for creating random numbers and 	  */
/*math.h to calculate powers of some numbers.								  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Function prototypes so that main function can use them.					  */
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void menu();

int main(){
	srand(time(NULL));
	menu();

return 0;
}

/*Menu is the function where user chooses which sub-program they want to use  */
/*Unless 0 is entered the menu appears again, when 0 is entered the program   */
/*exits. And if the user enters one of the valid choices this function starts */
/*executing the selected sub-program.										  */
void menu(){
	int choice;
		do{
			printf("1.Horse Racing Game\n");
			printf("2.Occurance Counter\n");
			printf("3.Triangle of Sequences\n");
			printf("0.Exit\n");
			scanf("%d",&choice);
		  }
		while(choice!=0 && (choice>3 || choice<0));

		switch(choice){
			case 1: horseRacingGame();
					break;
			case 2: countOccurrence();
					break;
			case 3: triangleOfSequences();
					break;
			default: break;
		}
}
/*This function gets a number from user between a given minimum and maximum   */
/*values.																	  */
int getInt(int mini, int maxi){
	int num;
	scanf("%d",&num);
		while(!(num>=mini && num<=maxi)){
			printf("Not in range! Try again:\n");
			scanf("%d",&num);
		}
	return num;
} 
/*This function creates a random number between a given minimum and maximum*/
int numberGeneratorBetweenRange(int min, int max){
	int num;
	num=min+rand()%(max-1-(min-1)+1);

	return num;
}
/*This function is the horse racing game. First of all it creates a random 	  */
/*racing horse number, then asks user to enter a horse number of their choice.*/
/*This function uses number generator function to create time values for every*/
/*horse and then prints these time values. Then function find the winner horse*/
/*and checks if user managed to find the right horse or not. If not failure   */
/*message is given, if user found the winner horse it gives a success message.*/
/*If all horses ran at the same time, function considers user the winner      */
void horseRacingGame(){
	int num_of_horses,horse_no,time,winner_time=21,winner_index=0,x=0,count=0;
	num_of_horses=numberGeneratorBetweenRange(3,5);
	printf("Number of Horse:%d\n",num_of_horses);
	printf("Horse Number:");
	horse_no=getInt(1,num_of_horses);
	printf("Racing starts..\n");

		for(int i=0;i<num_of_horses;i++){
			printf("Horse %d:",i+1);
			time=numberGeneratorBetweenRange(10,20);
			x++;
				for(int j=1;j<=time;j++){
					printf("-");
				}
			printf("\n");

			if(winner_time==time){
				count++;
			}
			if(winner_time>time){
				winner_time=time;
				winner_index=x;
			}
		}

		if(winner_index==horse_no){
			printf("You win! Winner is Horse %d.\n\n",horse_no);		
			
		}
		else if(count==num_of_horses-1){
			printf("You win! Winner is Horse %d.\n\n",horse_no);		
		}
		else	
			printf("You lose! Winner is Horse %d.\n\n",winner_index);
		
		menu();
}
/*This function is used to find the occurrences of some number in another     */
/*number. It first gets the number values from the user, then it calculates   */
/*their digit number. According to the digit numbers, this function checks    */
/*the search_num on big_num by checking enough last digits of big_num then it */
/*divides the big_num to 10 to check the rest of the occurences. Then it      */
/*prints out the value.														  */
void countOccurrence(){
	int big_num,search_num,temp,temp1;
	int s_digit_number=0,count=0,b_digit_number=0;

	printf("Big Number:");
	big_num=getInt(0,2147483647);

	printf("Search Number:");
	search_num=getInt(0,2147483647);

	temp1=big_num;
	temp = search_num;

		while(temp!=0){
			temp=temp/10;
			s_digit_number++;
		}

		while(temp1!=0){
			temp1=temp1/10;
			b_digit_number++;
		}

		for(int i=0;i<b_digit_number;i++){
			if((big_num%(int)pow(10,s_digit_number))==search_num){
				count++;

			}
			big_num=big_num/10;
		}	
		printf("Occurence:%d\n\n",count);
		menu();	
}
/*This function prints out a triangle by some random created number between */
/*2,10 as a row number. And it prints the numbers like n, n+n, n+n+n...*/
void triangleOfSequences(){
	int sum=0,num;
 	num=numberGeneratorBetweenRange(2,10);
	printf("\n");
		for(int i=1;i<=num;i++){
			for(int j=1; j<=i ;j++){
				sum+=i;
				printf("%d ",sum);
			}
		sum=0;
		printf("\n");
	}
	printf("\n");
	menu();
}


