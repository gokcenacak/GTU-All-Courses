/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>
/*Used trapezoidal sums to calculate integral from given start and ending points*/
double integral(double f(double x), double xs, double xe, double delta){
	double integral=0.0;
	
		for(double i=xs;i<xe;i=i+delta){
			integral+=(delta*(1.0/2.0)*(f(i)+f(i+delta)));
		}
	
	return integral;
}
/*Used (x,1) to take trapezoidal sums for x then used (1,y) to take the		  */
/*trapezoidal sums for y then multiplication of it gives the double integral  */
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){
	double integralx=0.0;
	double integraly=0.0;
	double result=0.0;
	int n=0.0;

		n=(ye-ys)/delta;
	
		for(double i=xs;i<xe;i=i+delta){
			integralx+=(delta*0.5*(f(i,1)+f(i+delta,1)));
			
		}
		for(double i=ys;i<ye;i=i+delta){
			integraly+=(delta*0.5*(f(1,i)+f(1,i+delta)));
			
		}
		result=integralx*integraly;
			
	return result;
	
}
/*Calculating derivatives from the formula provided in homework document.	  */
/*Returns 0 if something is wrong at calculating if not returns 1			  */
int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	if(eps!=0){
	*d1=(f(x+eps)-f(x-eps))/(2*eps);
	*d2=(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);

	return 1;
	}
	else 
		return -1;
}
/*Compares derivatives calculated from the previous function "derivatives" and*/
/*The functions provided the actual derivatives which are d1 and d2 and return*/
/*the erro values to their addresses returns 1 if its successful              */
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	double der1,der2;
	derivatives(f,x,eps,&der1,&der2);
	if(der1-d1(x)<0){
		*e1=d1(x)-der1;
	}
	if(der1-d1(x)>=0){
		*e1=der1-d1(x);
	}
	if(der2-d2(x)<0){
		*e2=d2(x)-der2;
	}
	if(der2-d2(x)>=0){
		*e2=der2-d2(x);
	}
	return 1;
}
/*Uses bisection method to find roots. If valid points for range entered it   */
/*calculates the root between that range, if the points are not valid it sends*/
/*failure message, the roots which are not found stays at 0.0 and function	  */
/*returns the root number*/

int find_roots(double f(double x), double *x1, double *x2, double *x3, double *x4){
double a;
	double b;
	double c;
	double d;
	double e;
	int middle;
	int count=0;
	*x1=0.0;
	*x2=0.0;
	*x3=0.0;
	*x4=0.0;
	double roots[4]={*x1,*x2,*x3,*x4};


	printf("Please enter a and b values as ranges to find x1:");
	scanf("%lf %lf",&a,&b);
	if(f(a)*f(b)<0){
		while(b-a>=0){
		roots[0]=(a+b)/2;
			if(f(roots[0])==0){
				*x1=roots[0];
				count++;
				break;
			}	
			else if(f(a)*f(roots[0])<0){
				b=roots[0];
			}
			else {
				a=roots[0];
			}
		} 

	}
	else printf("There is no root in the range of a and b.\n");
	
	printf("Please enter the b(the b you entered before) and c values as ranges to find x2:");
	scanf("%lf %lf",&b,&c);
	if(f(b)*f(c)<0){
		while(c-b>=0){
			roots[1]=(c+b)/2;
				if(f(roots[1])==0){
					*x2=roots[1];
					count++;
					break;
				}	
				else if(f(b)*f(roots[1])<0){
					c=roots[1];
				}
				else {
					b=roots[1];
				}
		}
	}
	else printf("There is no root in the range of b and c.\n");

printf("Please enter the c(the c you entered before) and d values as ranges to find x3:");
	scanf("%lf %lf",&c,&d);
	if(f(c)*f(d)<0){
		while(d-c>=0){
			roots[2]=(c+d)/2;
				if(f(roots[2])==0){
					*x3=roots[2];
					count++;
					break;
				}	
				else if(f(c)*f(roots[2])<0){
					d=roots[2];
				}
				else {
					c=roots[2];
				}
		}
	}
	else printf("There is no root in the range of c and d.\n");

printf("Please enter the d(the d you entered before) and e values as ranges to find x4:");
	scanf("%lf %lf",&d,&e);
	if(f(d)*f(e)<0){
		while(e-d>=0){
			roots[3]=(e+d)/2;
				if(f(roots[3])==0){
					*x4=roots[3];
					count++;
					break;
				}	
				else if(f(d)*f(roots[3])<0){
					e=roots[3];
				}
				else {
					d=roots[3];
				}
		}
	}
	else printf("There is no root in the range of d and e.\n");

	return count;
	
}



