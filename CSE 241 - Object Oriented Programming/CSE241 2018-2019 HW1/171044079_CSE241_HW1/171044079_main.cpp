//171044079_main.cpp created by Gökçe Nur Erer 
//CSE 241 Object Oriented Programming HW #1
//This file includes the main function implementation of the program.
//Uses the functions that are implemented and defined in source.cpp and source.h

#include <iostream>
#include <fstream> 
#include <cmath>
#include "source1.h"
using namespace std;

int main(){
	double con_main_height , con_main_width, con_main_radius, con_main_tri_side, small_shape_radius, small_shape_tri_side, small_shape_width, small_shape_height;
	char main_shape_select,small_shape_select;
	Shape con_shape,smallShape;
	ofstream outputStream;

	//Selection and drawing of the main container
	cout << "Please enter the main container shape (R, C, T):" ;
	cin >> main_shape_select;
	//User input checking
		while(main_shape_select!='R' && main_shape_select!='r' && main_shape_select!='C' && main_shape_select!='c' && main_shape_select!='T' && main_shape_select!='t'){
			cout << "Try again (R,C,T):";
			cin >> main_shape_select;

		}
	//Deciding the shape
	con_shape=shape_selection(main_shape_select);
	//Getting attributes
	get_attribute(con_shape,con_main_width,con_main_height,con_main_tri_side,con_main_radius);
	//Drawing of the very background	
	main_frame(con_main_width,con_main_height,outputStream);
	//Drawing of the main container shape
	main_container(con_shape,con_main_height,con_main_width,con_main_radius,con_main_tri_side,outputStream);

	//Selection and drawing of the small shape
	cout << "-----------------------------\n";
	cout << "Please enter the small shape:";
	cin >> small_shape_select;

		while(small_shape_select!='R' && small_shape_select!='r' && small_shape_select!='C' && small_shape_select!='c' && small_shape_select!='T' && small_shape_select!='t'){
			cout << "Try again (R,C,T):";
			cin >> small_shape_select;
		}

	//Deciding the small shape
		smallShape=shape_selection(small_shape_select);
	//Getting attributes
	get_attribute(smallShape,small_shape_width,small_shape_height,small_shape_tri_side,small_shape_radius);
	//Calculating the result
	calculate_fitting(con_shape,smallShape,con_main_width,con_main_height,con_main_radius,con_main_tri_side,outputStream,small_shape_radius,small_shape_width,small_shape_height,small_shape_tri_side);
	//Closing the svg file
	closeFile(outputStream);

	return 0;
}
