#include <iostream>
#include <cstdlib>
#include <cmath>
#include "triangle.h"
//Function-constructor implementations of "triangle.h", explanatory comments are provided in "triangle.h"
using namespace std;
	double Triangle :: totalPerimeter=0;
	double Triangle :: totalArea=0;
	Triangle::Triangle(double xCoor1, double yCoor1, double xCoor2, double yCoor2, double xCoor3, double yCoor3, double side){
		setx1Coor(xCoor1);
		sety1Coor(yCoor1);
		setx2Coor(xCoor2);
		sety2Coor(yCoor2);
		setx3Coor(xCoor3);
		sety3Coor(yCoor3);
		setSideLength(side);
		triarea=area();
		triperimeter=perimeter();
		totalPerimeter+=triperimeter;
		totalArea+=triarea;
	}
	Triangle::Triangle(double side){
		setSideLength(side);
		setx1Coor(side/2);
		sety1Coor(0);
		setx2Coor(0);
		sety2Coor(side*sqrt(3)/2);
		setx3Coor(side);
		sety3Coor(side*sqrt(3)/2);
		triarea=area();
		triperimeter=perimeter();
		totalPerimeter+=triperimeter;
		totalArea+=triarea;
	}

	Triangle::Triangle() : x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),sideLength(1.0){}

	void Triangle::setSideLength(double side) throw(invalidLengthException){
		if(side<=0){
			throw invalidLengthException();
		}
		sideLength=side;
	}
	void Triangle::setx1Coor(double xCoor1) throw(invalidCoordinateException){
		if(xCoor1<0){
			throw invalidCoordinateException();
		}
		else{
			x1=xCoor1;
		}
	}
	void Triangle::sety1Coor(double yCoor1) throw(invalidCoordinateException){
		if(yCoor1<0){
			throw invalidCoordinateException();
		}
		else{
			y1=yCoor1;
		}
	}
	void Triangle::setx2Coor(double xCoor2) throw(invalidCoordinateException){
		if(xCoor2<0){
			throw invalidCoordinateException();
		}
		else{
			x2=xCoor2;
		}
	}
	void Triangle::sety2Coor(double yCoor2) throw(invalidCoordinateException){
		if(yCoor2<0){
			throw invalidCoordinateException();
		}
		else{
			y2=yCoor2;
		}
	}
	void Triangle::setx3Coor(double xCoor3) throw(invalidCoordinateException){
		if(xCoor3<0){
			throw invalidCoordinateException();
		}
		else{
			x3=xCoor3;
		}
	}
	void Triangle::sety3Coor(double yCoor3) throw(invalidCoordinateException){
		if(yCoor3<0){
			throw invalidCoordinateException();
		}
		else{
			y3=yCoor3;
		}
	}
	double Triangle::perimeter() const{
		return 3*sideLength;
	}
	double Triangle::area() const {
		return pow(sideLength,2)*sqrt(3)/4;
	}
	string Triangle::shapeName() const{
		return "Triangle";
	}
	void Triangle::input(){
		double i_sideLength;

		cout << "Side Length:";
		cin >> i_sideLength;
		setSideLength(i_sideLength);
		setx1Coor(i_sideLength/2);
		sety1Coor(0);
		setx2Coor(0);
		sety2Coor(i_sideLength*sqrt(3)/2);
		setx3Coor(i_sideLength);
		sety3Coor(i_sideLength*sqrt(3)/2);
		totalPerimeter+=perimeter();
		totalArea+=area();

	}

	void Triangle::draw(ostream& file) const{
		file << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
	}

	
	Triangle & Triangle :: operator ++(){
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		return *this;
	}
	Triangle & Triangle :: operator ++(int ignored){
		double tempx1=x1;
		double tempy1=y1;
		double tempx2=x2;
		double tempy2=y2;
		double tempx3=x3;
		double tempy3=y3;
		
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		Triangle * trip= new Triangle(tempx1,tempy1,tempx2,tempy2,tempx3,tempy3,sideLength);
		return *trip;		
	}
	Triangle & Triangle :: operator --(){
		x1--;
		y1--;
		x2--;
		y2--;
		x3--;
		y3--;
		return *this;
	}
	Triangle & Triangle :: operator --(int ignored){
		double tempx1=x1;
		double tempy1=y1;
		double tempx2=x2;
		double tempy2=y2;
		double tempx3=x3;
		double tempy3=y3;
		
		x1--;
		y1--;
		x2--;
		y2--;
		x3--;
		y3--;
		Triangle * trip = new Triangle(tempx1,tempy1,tempx2,tempy2,tempx3,tempy3,sideLength);	
		return *trip;	
	}
	//MINOR BUG:When it is thought as a main container + operator makes x2 value negative so the program exits.
	Triangle Triangle :: operator+(double value){
		return Triangle(x1,y1,x2-value,y2+value,x3+value,y2+value,sideLength+value);
	}
	Triangle Triangle :: operator-(double value){
		return Triangle(x1,y1,x2+value,y2-value,x3-value,y2-value,sideLength-value);
	}





