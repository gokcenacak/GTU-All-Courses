#include <iostream>
#include <cstdlib>
#include <cmath>
#include "circle.h"
//Function-constructor implementations of "circle.h", explanatory comments are provided in "circle.h"
using namespace std;
	double Circle :: totalPerimeter=0;
	double Circle :: totalArea=0;
	Circle::Circle(double xCoor, double yCoor, double cradius) {
		setxCoor(xCoor);
		setyCoor(yCoor);
		setRadius(cradius);
		cirarea=area();
		cirperimeter=perimeter();
		totalPerimeter+=cirperimeter;
		totalArea+=cirarea;
	}
	//Intentionally empty
	Circle::Circle() : x(0), y(0), radius(1.0), cirarea(0.0), cirperimeter(0.0){}

	void Circle::setxCoor(double xCoor) throw(invalidCoordinateException){
		if(xCoor<0){
			throw invalidCoordinateException();
		}
		else{
			x=xCoor;
		}
	}
	void Circle::setyCoor(double yCoor) throw(invalidCoordinateException){
		if(yCoor<0){
			throw invalidCoordinateException();
		}
		else{
			y=yCoor;
		}
	}
	void Circle::setRadius(double cradius) throw(invalidLengthException){
		if(cradius<0){
			throw invalidLengthException();
		}
		else{
			radius=cradius;
		}
	}

	double Circle::area() const{
		return M_PI*pow(radius,2);
	}

	double Circle::perimeter() const{
		return 2*M_PI*radius;
	}
	string Circle::shapeName() const{
		return "Circle";
	}

	void Circle::input(){
		double i_radius;
		cout << "Enter radius:" << endl;
		cin >>i_radius;
		setRadius(i_radius);
		setxCoor(i_radius);
		setyCoor(i_radius);
		cirarea=area();
		cirperimeter=perimeter();
		totalPerimeter+=cirperimeter;
		totalArea+=cirarea;

	}

	void Circle::draw(ostream& file) const{
		file  << "<circle cx=\"" << x << "\" cy=\""<< y <<"\" r=\"" << radius << "\" fill=\"blue\" stroke=\"black\" stroke-width=\"0.5\"/> \n";

	}

	
	Circle & Circle :: operator ++(){
		x++;
		y++;
		return *this;
	}
	Circle & Circle :: operator ++(int ignored){
		double tempx=x;
		double tempy=y;
		x++;
		y++;
		Circle * cirp=new Circle(tempx,tempy,radius);
		return *cirp;	
	}
	Circle & Circle :: operator --(){
		x--;
		y--;
		return *this;
	}
	Circle & Circle :: operator --(int ignored){
		double tempx=x;
		double tempy=y;
		x--;
		y--;
		Circle * cirp=new Circle(tempx,tempy,radius);
		return *cirp;		
	}
	Circle Circle :: operator+(double value){
		return Circle(x,y,radius+value);
	}
	Circle Circle :: operator-(double value){
		return Circle(x,y,radius-value);
	}

	



