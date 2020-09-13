#include <iostream>
#include <cstdlib>
#include "circle.h"
//Function-constructor implementations of "circle.h", explanatory comments are provided in "circle.h"
using namespace std;

	Circle::Circle(double xCoor, double yCoor, double cradius) {
		setxCoor(xCoor);
		setyCoor(yCoor);
		setRadius(cradius);
	}
	//Intentionally empty
	Circle::Circle() : x(0), y(0), radius(0.0) {}

	void Circle::setxCoor(double xCoor){
		if(xCoor<0){
			cout << "x coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			x=xCoor;
		}
	}
	void Circle::setyCoor(double yCoor){
		if(yCoor<0){
			cout << "y coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			y=yCoor;
		}
	}
	void Circle::setRadius(double cradius){
		if(cradius<0){
			cout << "Radius cannot be negative." << endl;
			exit(1);
		}
		else{
			radius=cradius;
		}
	}
	void Circle::input(){
		double i_radius;
		cout << "Enter radius:" << endl;
		cin >>i_radius;
		setRadius(i_radius);
		setxCoor(i_radius);
		setyCoor(i_radius);

	}
	void Circle::output() const{
		cout << "X:" << x << endl;
		cout << "Y:" << y << endl;
		cout << "Radius:" << radius << endl;	

	}

	void Circle::draw(ofstream& file) const{
		file  << "<circle cx=\"" << x << "\" cy=\""<< y <<"\" r=\"" << radius << "\" fill=\"blue\" stroke=\"black\" stroke-width=\"0.5\"/> \n";

	}


