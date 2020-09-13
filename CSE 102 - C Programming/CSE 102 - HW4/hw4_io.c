/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>
/*Takes values from users and assigns them to coeefficents for third degree
polynomials.*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
	double b0,b1,b2,b3;
	printf("Please enter a0,a1,a2,a3 numbers:");
	scanf("%lf",&b0);
	scanf("%lf",&b1);
	scanf("%lf",&b2);
	scanf("%lf",&b3);
	*a0=b0;
	*a1=b1;
	*a2=b2;
	*a3=b3;

	return 1;
}
/*Takes values from users and assigns them to coeefficents for fourth degree 
polynomials.*/
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){
	double b0,b1,b2,b3,b4;
	printf("Please enter a0,a1,a2,a3,a4 numbers:");
	scanf("%lf",&b0);
	scanf("%lf",&b1);
	scanf("%lf",&b2);
	scanf("%lf",&b3);
	scanf("%lf",&b4);
	*a0=b0;
	*a1=b1;
	*a2=b2;
	*a3=b3;
	*a4=b4;

	return 1;
}
/*Prints a third degree polynomial in a pretty format*/
void write_polynomial3(double a0, double a1, double a2, double a3){

	double coefficents[4]={a3,a2,a1,a0};

		for(int i=0;i<3;i++){
			if(coefficents[i]!=0){
				if(coefficents[i]==1){
					printf("x^%d",3-i);
				}
				else if(coefficents[i]==-1){
					printf("-x^%d",3-i);
				}
				else
				printf("%+.2gx^%d",coefficents[i],3-i);
			}
			
		}
		if(coefficents[3]!=0){
		printf("%+.2g",coefficents[3]);
		}
}
/*Prints a fourth degree polynomial in a pretty format*/
void write_polynomial4(double a0, double a1, double a2, double a3, double a4){

	double coefficents[5]={a4,a3,a2,a1,a0};

		for(int i=0;i<4;i++){
			if(coefficents[i]!=0){
				if(coefficents[i]==1){
					printf("x^%d",4-i);
				}
				else if(coefficents[i]==-1){
					printf("-x^%d",4-i);
				}
				else
				printf("%+.2gx^%d",coefficents[i],4-i);
			}
			
		}
		if(coefficents[4]!=0){
		printf("%+.2g",coefficents[4]);
		}
}


