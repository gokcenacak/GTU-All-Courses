#include <iostream>
#include <cstdlib>
#include "rectangle.h"

//Function-constructor implementations of "rectangle.h", explanatory comments are provided in "rectangle.h"

	double Rectangle :: totalPerimeter=0;
	double Rectangle :: totalArea=0;
	Rectangle::Rectangle(double xCoor, double yCoor, double rwidth, double rheight) {
		setxCoor(xCoor);
		setyCoor(yCoor);
		setWidth(rwidth);
		setHeight(rheight);
		rectarea=area();
		rectperimeter=perimeter();
		totalPerimeter+=rectarea;
		totalArea+=rectperimeter;
	}

	//Intentionally empty
	Rectangle::Rectangle() : x(0), y(0), width(0.0), height(0.0) , rectarea(1.0), rectperimeter(1.0){}

	void Rectangle::setxCoor(double xCoor) throw(invalidCoordinateException){
		if(xCoor<0){
			throw invalidCoordinateException();
		}
		else{
			x=xCoor;
		}
	}
	void Rectangle::setyCoor(double yCoor) throw(invalidCoordinateException){
		if(yCoor<0){
			throw invalidCoordinateException();
		}
		else{
			y=yCoor;
		}
	}
	void Rectangle::setWidth(double rwidth) throw(invalidLengthException){
		if(rwidth<=0){
			throw invalidLengthException();
		}
		else{
			width=rwidth;
		}
	}
	void Rectangle::setHeight(double rheight) throw(invalidLengthException){
		if(rheight<=0){
			throw invalidLengthException();
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
		setxCoor(1);
		setyCoor(1);
		rectarea=area();
		rectperimeter=perimeter();
		totalPerimeter+=rectperimeter;
		totalArea+=rectarea;
	
	}

	void Rectangle::draw(ostream& file) const{
		file << "<rect x=\"" << x << "\" y=\""<< y <<"\" width=\"" << width << "\" height=\"" << height << "\" fill=\"red\" stroke-width=\"0.5\" stroke=\"black\"/>";
	}

	
	//MINOR BUG: These operators post ++,-- cause dangling pointer at some situations but couldn't be done any other way.
	Rectangle & Rectangle :: operator ++(){
		x++;
		y++;
		return *this;
	}
	Rectangle & Rectangle :: operator ++(int ignored){
		double tempx=x;
		double tempy=y;
		
		x++;
		y++;
		Rectangle * rectp=new Rectangle(tempx,tempy,width,height);
		return *rectp;		
	}
	Rectangle & Rectangle :: operator --(){
		x--;
		y--;
		return *this;
	}
	Rectangle & Rectangle :: operator --(int ignored){
		double tempx=x;
		double tempy=y;
		
		x--;
		y--;
		Rectangle * rectp=new Rectangle(tempx,tempy,width,height);
		return *rectp;		
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


	double Rectangle::area() const{
		return width*height;
	}
	double Rectangle::perimeter() const{
		return 2*(width+height);
	}
	
	string Rectangle::shapeName() const{
		return "Rectangle";
	}
	
	



