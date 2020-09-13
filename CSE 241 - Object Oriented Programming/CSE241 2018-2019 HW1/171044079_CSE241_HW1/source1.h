//source1.h created by Gökçe Nur Erer 
//CSE 241 Object Oriented Programming HW #1
//This file includes the function implementations of the functions that are usedin 171044079_main.cpp 
#include <fstream>
using namespace std;

enum class Shape { Rectangle, Triangle, Circle };
#ifndef CPP_HW1_H_
#define CPP_HW1_H_

void main_frame(double con_main_width, double con_main_height,ofstream& outputStream);

void main_container (Shape s, double con_main_height, double con_main_width, double con_main_radius, double con_main_tri_side,ofstream& outputStream);

void get_attribute(Shape s,double& width, double& height , double& tri_side, double& radius);

Shape shape_selection(char c);

void circleInRectangle(double main_c_width,double main_c_height,double small_shape_radius,ofstream& outputStream);

void triangleInRectangle(double main_c_width,double main_c_height,double small_shape_triside,ofstream& outputStream);

void rectangleInRectangle(double main_c_width,double main_c_height,double small_shape_width,double small_shape_height,ofstream& outputStream);

void rectangleInCircle(double main_c_radius, double small_shape_width, double small_shape_height, ofstream& outputStream);

void triangleInCircle(double main_c_radius, double small_shape_triside, ofstream &outputStream);

void circleInCircle(double main_c_radius, double small_shape_radius, ofstream &outputStream);

void rectangleInTriangle(double main_c_triside, double small_shape_width, double small_shape_height, ofstream &outputStream);

void circleInTriangle(double main_c_triside,double small_shape_radius,ofstream& outputStream);

void triangleInTriangle(double main_c_triside,double small_shape_triside,ofstream& outputStream);

void calculate_fitting(Shape con_shape, Shape smallShape, double main_c_width, double main_c_height, double main_c_radius, double main_c_triside, ofstream& outputStream,double small_shape_radius,double small_shape_width, double small_shape_height, double small_shape_triside);

void closeFile(ofstream& outputStream);

#endif /*CPP_HW1_H_*/
