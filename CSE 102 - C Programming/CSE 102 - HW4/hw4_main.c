/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>


#include "hw4_lib.h"
#include "hw4_io.h"



/*
** Testing derivative calculations..
**
*/
void test_compare_derivatives() {
	double f(double x) { return x*x; }
	double d1(double x) { return 2.0*x; }
	double d2(double x) { return 2.0; }
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("%.15f %.15f\n",e1,e2);
}
/*To not change the document(as it was mentioned in homework document I put my*/
/*test functions in a comment line. If needed they can be used and changed.*/

/*void test_derivatives() {
	double d1,d2;
	double f(double x) { return x*x*x; }
	int res1 =derivatives(f,1.0, 0.0001, &d1, &d2);
	printf("%.4f %.4f\n",d1,d2);
}

void test_integral(){
	double f(double x) { return x*x; }
	double res2=integral(f,1,5,0.001);
	printf("%.2f\n",res2);
}
void test_integral2(){
	double f(double x, double y) { return x*y; }
	double res3=integral2(f,1,2,1,2,0.0001);
	printf("%.2f\n",res3);
}
void test_find_roots(){
	double x1,x2,x3,x4;
	double f(double x) {return x*x*x*x-10*x*x*x+35*x*x-50*x+24; }
	int res4=find_roots(f,&x1,&x2,&x3,&x4);
	printf("Roots are x1:%.2f x2:%.2f x3:%.2f x4:%.2f Total roots:%d\n",x1,x2,x3,x4,res4);
}

void test_read_polynomial3(){
	double a0,a1,a2,a3;
	int res5=read_polynomial3(&a0,&a1,&a2,&a3);
	printf("a0:%.2f a1:%.2f a2:%.2f a3:%.2f\n",a0,a1,a2,a3);
}
void test_read_polynomial4(){
	double a0,a1,a2,a3,a4;
	int res6=read_polynomial4(&a0,&a1,&a2,&a3,&a4);
	printf("a0:%.2f a1:%.2f a2:%.2f a3:%.2f a4:%.2f\n",a0,a1,a2,a3,a4);
}
void test_write_polynomial3(){
	double a0,a1,a2,a3;
	printf("Enter a0,a1,a2,a3 values:");
	scanf("%lf %lf %lf %lf",&a0,&a1,&a2,&a3);
	write_polynomial3(a0,a1,a2,a3);
}
void test_write_polynomial4(){
	double a0,a1,a2,a3,a4;
	printf("Enter a0,a1,a2,a3,a4 values:");
	scanf("%lf %lf %lf %lf %lf",&a0,&a1,&a2,&a3,&a4);
	write_polynomial4(a0,a1,a2,a3,a4);
}
*/

/*
** main function for testing the functions...
**
*/
int main(void) {
	
	test_compare_derivatives();
	/*test_derivatives();
	test_integral();
	test_integral2();
	test_find_roots();
	test_read_polynomial3();
	test_read_polynomial4();
	test_write_polynomial3();
	test_write_polynomial4();
	*/
	return (0);
} /* end main */
