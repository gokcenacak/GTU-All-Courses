#include <iostream>
#include <cstdlib>
#include <cmath>
#include "triangle.h"
//Function-constructor implementations of "triangle.h", explanatory comments are provided in "triangle.h"
using namespace std;

	Triangle::Triangle(double xCoor1, double yCoor1, double xCoor2, double yCoor2, double xCoor3, double yCoor3, double side){
		setx1Coor(xCoor1);
		sety1Coor(yCoor1);
		setx2Coor(xCoor2);
		sety2Coor(yCoor2);
		setx3Coor(xCoor3);
		sety3Coor(yCoor3);
		setSideLength(side);
	}

	Triangle::Triangle() : x1(0.0),y1(0.0),x2(0.0),y2(0.0),x3(0.0),y3(0.0),sideLength(0.0) {}

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
	//These are for testing purposes has to be deleted later on.
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

	}
	void Triangle::output() const{
		cout << "x1:" << x1 << endl;
		cout << "y1:" << y1 << endl;
		cout << "x2:" << x2 << endl;
		cout << "y2:" << y2 << endl;
		cout << "x3:" << x3 << endl;
		cout << "y3:" << y3 << endl;
		cout << "Side Length:" << sideLength << endl;
	}

	void Triangle::draw(ofstream& file) const{
		file << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
	}






