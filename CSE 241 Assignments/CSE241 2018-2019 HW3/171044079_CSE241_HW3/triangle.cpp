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
		setTrianglePerimeter(side);
		setTriangleArea(side);
		totalPerimeter+=perimeter;
		totalArea+=area;
	}

	Triangle::Triangle() : x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),sideLength(0.0), perimeter(0.0), area(0.0){}

	void Triangle::setSideLength(double side){
		sideLength=side;
	}
	void Triangle::setx1Coor(double xCoor1){
		if(xCoor1<0){
			cout << "x1 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			x1=xCoor1;
		}
	}
	void Triangle::sety1Coor(double yCoor1){
		if(yCoor1<0){
			cout << "y1 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			y1=yCoor1;
		}
	}
	void Triangle::setx2Coor(double xCoor2){
		if(xCoor2<0){
			cout << "x2 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			x2=xCoor2;
		}
	}
	void Triangle::sety2Coor(double yCoor2){
		if(yCoor2<0){
			cout << "y2 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			y2=yCoor2;
		}
	}
	void Triangle::setx3Coor(double xCoor3){
		if(xCoor3<0){
			cout << "x3 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			x3=xCoor3;
		}
	}
	void Triangle::sety3Coor(double yCoor3){
		if(yCoor3<0){
			cout << "y3 coordinate cannot be negative." << endl;
			exit(1);
		}
		else{
			y3=yCoor3;
		}
	}
	void Triangle::setTrianglePerimeter(double side) {
		perimeter=3*side;
	}
	void Triangle::setTriangleArea(double side) {
		area=pow(side,2)*sqrt(3)/4;
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
		setTrianglePerimeter(i_sideLength);
		setTriangleArea(i_sideLength);
		totalPerimeter+=perimeter;
		totalArea+=area;

	}

	void Triangle::draw(ofstream& file) const{
		file << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
	}

	bool Triangle::operator ==(const Triangle& triangle2) const{
		return (area == triangle2.area);
	}
	bool Triangle::operator !=(const Triangle& triangle2) const{
		return (area != triangle2.area);
	}
	bool Triangle::operator <(const Triangle& triangle2) const{
		return (area < triangle2.area);
	}
	bool Triangle::operator >(const Triangle& triangle2) const{
		return (area > triangle2.area);
	}
	bool Triangle::operator >=(const Triangle& triangle2) const{
		return (area >= triangle2.area);
	}
	bool Triangle::operator <=(const Triangle& triangle2) const{
		return (area <= triangle2.area);
	}

	Triangle Triangle :: operator ++(){
		x1++;
		y1++;
		x2++;
		y2++;
		x3++;
		y3++;
		return Triangle(x1,y1,x2,y2,x3,y3,sideLength);
	}
	Triangle Triangle :: operator ++(int ignored){
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
		return Triangle(tempx1,tempy1,tempx2,tempy2,tempx3,tempy3,sideLength);		
	}
	Triangle Triangle :: operator --(){
		x1--;
		y1--;
		x2--;
		y2--;
		x3--;
		y3--;
		return Triangle(x1,y1,x2,y2,x3,y3,sideLength);	
	}
	Triangle Triangle :: operator --(int ignored){
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
		return Triangle(tempx1,tempy1,tempx2,tempy2,tempx3,tempy3,sideLength);		
	}
	//MINOR BUG:When it is thought as a main container + operator makes x2 value negative so the program exits.
	Triangle Triangle :: operator+(double value){
		return Triangle(x1,y1,x2-value,y2+value,x3+value,y2+value,sideLength+value);
	}
	Triangle Triangle :: operator-(double value){
		return Triangle(x1,y1,x2+value,y2-value,x3-value,y2-value,sideLength-value);
	}

	ostream& operator <<(ostream& outputStream, const Triangle& tri){
		outputStream << "X1 Coordinate:" << tri.getx1Coor() << endl;
		outputStream << "Y1 Coordinate:" << tri.gety1Coor() << endl;
		outputStream << "X2 Coordinate:" << tri.getx2Coor() << endl;
		outputStream << "Y2 Coordinate:" << tri.gety2Coor() << endl;
		outputStream << "X3 Coordinate:" << tri.getx3Coor() << endl;
		outputStream << "Y3 Coordinate:" << tri.gety3Coor() << endl;
		outputStream << "Side Length:" << tri.getSideLength() << endl;
	}



