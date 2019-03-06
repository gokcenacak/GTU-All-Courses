#include <iostream>
#include <cstdlib>
#include "rectangle.h"
//Function-constructor implementations of "rectangle.h", explanatory comments are provided in "rectangle.h"
using namespace std;

	Rectangle::Rectangle(double xCoor, double yCoor, double rwidth, double rheight) {
		setxCoor(xCoor);
		setyCoor(yCoor);
		setWidth(rwidth);
		setHeight(rheight);
	}

	//Intentionally empty
	Rectangle::Rectangle() : x(0), y(0), width(0.0), height(0.0) {}

	void Rectangle::setxCoor(double xCoor){
		if(xCoor<0){
			cout << "x coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			x=xCoor;
		}
	}
	void Rectangle::setyCoor(double yCoor){
		if(yCoor<0){
			cout << "y coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			y=yCoor;
		}
	}
	void Rectangle::setWidth(double rwidth){
		if(rwidth<0){
			cout << "Width cannot be negative." << endl;
			exit(1);
		}
		else{
			width=rwidth;
		}
	}
	void Rectangle::setHeight(double rheight){
		if(rheight<0){
			cout << "Height cannot be negative." << endl;
			exit(1);
		}
		else{
			height=rheight;
		}
	}

	void Rectangle::input(){
		double i_width,i_height;
		cout << "Enter width:" << endl;
		cin >>i_width;
		setWidth(i_width);
		cout << "Enter height:" << endl;
		cin >>i_height;
		setHeight(i_height);
		setxCoor(0);
		setyCoor(0);
	
	}
	void Rectangle::output() const{
		cout << "X:" << x << endl;
		cout << "Y:" << y << endl;
		cout << "Width:" << width << endl;	
		cout << "Height:" << height << endl;
	}
	void Rectangle::draw(ofstream& file) const{
		file << "<rect x=\"" << x << "\" y=\""<< y <<"\" width=\"" << width << "\" height=\"" << height << "\" fill=\"red\" stroke-width=\"0.5\" stroke=\"black\"/>";
	}


