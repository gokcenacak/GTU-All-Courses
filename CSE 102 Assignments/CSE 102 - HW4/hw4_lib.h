/*
** hw4_io.h:
**
** The header file declaring library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#ifndef _HW4_LIB_H_
#define _HW4_LIB_H_


double integral(double f(double x), double xs, double xe, double delta);


double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta);


int derivatives(double f(double a), double x, double eps, double * d1, double * d2);


int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2);


int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4);


#endif
