/*HW02_Gokce_Nur_Erer_171044079_part2.c*/
/*Written by: Gokce Nur Erer*/
/*		              			DESCRIPTION                                   */
/*The objective of this program is to take a number from the user (which is in*/
/*the range of 23-98760)and printing that numbers digits starting from fifth  */
/*fifth digit to first digit.												  */
												  
#include <stdio.h>
/*digit_number is the function that calculates the digit number of a given    */
/*integer number and returns it											      */
int digit_number(int num){
	int digit_number=0;
		
		while(num!=0){
			num=num/10;
			digit_number++;
		}
	return digit_number;
}

int main(){

	int num,first_digit,second_digit,third_digit,fourth_digit,fifth_digit;

	/*Taking the number from the user										  */
	printf("Enter the number:");
	scanf("%d",&num);

	/*The digit calculations should only happen when the number is in the     */
	/* range of 23<num<98760 according to the homework assignment document.   */

	if(num>=23&&num<=98760){
    /*Digits are found by using powers of ten for dividing the actual number  */
	/*and getting those result's remainder by 10 	   						  */
		first_digit=num%10;
		second_digit=(num/10)%10;
		third_digit=(num/100)%10;
		fourth_digit=(num/1000)%10;
		fifth_digit=(num/10000)%10;
	/*The number of the digits are important at printing the result so to     */
	/*overcome the problem of printing digits that are not existing, these if */
	/*statements are used to do printing according to their digit value 	  */			
		if(digit_number(num)==5){
			printf("\nThe fifth digit is:%d\n",fifth_digit);
			printf("The fourth digit is:%d\n",fourth_digit);
			printf("The third digit is:%d\n",third_digit);
			printf("The second digit is:%d\n",second_digit);
			printf("The first digit is:%d\n",first_digit);
		}
		if(digit_number(num)==4){
			printf("\nThe fourth digit is:%d\n",fourth_digit);
			printf("The third digit is:%d\n",third_digit);
			printf("The second digit is:%d\n",second_digit);
			printf("The first digit is:%d\n",first_digit);
		}
		if(digit_number(num)==3){
			printf("\nThe third digit is:%d\n",third_digit);
			printf("The second digit is:%d\n",second_digit);
			printf("The first digit is:%d\n",first_digit);
		}
		if(digit_number(num)==2){
			printf("\nThe second digit is:%d\n",second_digit);
			printf("The first digit is:%d\n",first_digit);
		}
	}

return 0;
}
