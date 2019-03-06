#include <iostream>
#include <cstdlib>
#include "rectangle.h"
//Function-constructor implementations of "rectangle.h", explanatory comments are provided in "rectangle.h"
using namespace std;
	double Rectangle :: totalPerimeter=0;
	double Rectangle :: totalArea=0;
	Rectangle::Rectangle(double xCoor, double yCoor, double rwidth, double rheight) {
		setxCoor(xCoor);
		setyCoor(yCoor);
		setWidth(rwidth);
		setHeight(rheight);
		setRectanglePerimeter(rwidth,rheight);
		setRectangleArea(rwidth,rheight);
		totalPerimeter+=perimeter;
		totalArea+=area;
	}

	//Intentionally empty
	Rectangle::Rectangle() : x(0), y(0), width(0.0), height(0.0), perimeter(0.0), area(0.0) {}

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

	void Rectangle::setRectanglePerimeter(double rwidth, double rheight){
		perimeter=2*(rwidth+rheight);
	}
	void Rectangle::setRectangleArea(double rwidth, double rheight){
		area=rwidth*rheight;
	}
	void Rectangle::input(){
		double i_width,i_height;
		cout << "Enter width:" << endl;
		cin >>i_width;
		setWidth(i_width);
		cout << "Enter height:" << endl;
		cin >>i_height;
		setHeight(i_height);
		setxCoor(1);
		setyCoor(1);
		setRectanglePerimeter(i_width,i_height);
		setRectangleArea(i_width,i_height);
		totalPerimeter+=perimeter;
		totalArea+=area;
	
	}

	void Rectangle::draw(ofstream& file) const{
		file << "<rect x=\"" << x << "\" y=\""<< y <<"\" width=\"" << width << "\" height=\"" << height << "\" fill=\"red\" stroke-width=\"0.5\" stroke=\"black\"/>";
	}

	bool Rectangle::operator ==(const Rectangle& rectangle2) const{
		return (area == rectangle2.area);
	}
	bool Rectangle::operator !=(const Rectangle& rectangle2) const{
		return (area != rectangle2.area);
	}
	bool Rectangle::operator <(const Rectangle& rectangle2) const{
		return (area < rectangle2.area);
	}
	bool Rectangle::operator >(const Rectangle& rectangle2) const{
		return (area > rectangle2.area);
	}
	bool Rectangle::operator >=(const Rectangle& rectangle2) const{
		return (area >= rectangle2.area);
	}
	bool Rectangle::operator <=(const Rectangle& rectangle2) const{
		return (area <= rectangle2.area);
	}

	Rectangle Rectangle :: operator ++(){
		x++;
		y++;
		return Rectangle(x,y,width,height);
	}
	Rectangle Rectangle :: operator ++(int ignored){
		double tempx=x;
		double tempy=y;
		
		x++;
		y++;
		return Rectangle(tempx,tempy,width,height);		
	}
	Rectangle Rectangle :: operator --(){
		x--;
		y--;
		return Rectangle(x,y,width,height);
	}
	Rectangle Rectangle :: operator --(int ignored){
		double tempx=x;
		double tempy=y;
		
		x--;
		y--;
		return Rectangle(tempx,tempy,width,height);		
	}

	Rectangle Rectangle :: operator+(double value){
		return Rectangle(x,y,width+value,height+value);
	}
	Rectangle Rectangle :: operator-(double value){
		if(width-value>=0 && height-value >=0)
			return Rectangle(x,y,width-value,height-value);
		else
			cout << "Warning! New sizes are less than 0.";
			exit(1);
	}

	ostream& operator <<(ostream& outputStream, const Rectangle& rect){
		outputStream << "X Coordinate:" << rect.getxCoor() << endl;
		outputStream << "Y Coordinate:" << rect.getyCoor() << endl;
		outputStream << "Width:" << rect.getWidth() << endl;
		outputStream << "Height:" << rect.getHeight() << endl;
		outputStream << "Area:" << rect.getRectangleArea() << endl;
		outputStream << "Perimeter:" << rect.getRectanglePerimeter() << endl;
	}









