#include <iostream>
#include <fstream>
#include "shape.h"
#include "invalidLengthException.h"
#include "invalidCoordinateException.h"
using namespace std;
using namespace ShapeErer;
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
//Rectangle is a concrete class derived from abstract class Shape to represent rectangle.
class Rectangle : public Shape{
	public:
	      //Initializes the rectangle object with the given x,y coordinates and width,height
		Rectangle(double xCoor, double yCoor, double width, double height);
		//Initializes the rectangle object with x,y coordinates as 0,0 and width and height as 0,0.
		Rectangle();
		//Returns width
		inline double getWidth() const { return width; }
		//Returns height
		inline double getHeight() const { return height; }
		//Returns x coordinate
		inline double getxCoor() const { return x; }
		//Returns y coordinate
		inline double getyCoor() const { return y; }
		//Getting area
		inline double getArea() const { return rectarea; }
		//Getting perimeter
		inline double getPerimeter() const { return rectperimeter; }
		//Setting width to rwidth
		void setWidth(double rwidth) throw(invalidLengthException);
		//Setting height  to rheight
		void setHeight(double rheight) throw(invalidLengthException);
		//Setting x coordinate to xCoor
		void setxCoor(double xCoor) throw(invalidCoordinateException);
		//Setting y coordinate to yCoor
		void setyCoor(double yCoor) throw(invalidCoordinateException);
		//Inputs are taken from the user and setted to the created object, yet x and y coordinates are set to 0,0
		void input();
		//Draws the rectangle object to a svg file
		virtual void draw(ostream& file) const;

		//Returns area 
		virtual double area() const;
		//Returns perimeter
		virtual double perimeter() const;
		//Returns shape's name
		virtual string shapeName() const;

		//Pre and post ++/-- operator overloads 
		virtual Rectangle & operator ++();
		virtual Rectangle & operator ++(int ignored);
		virtual Rectangle & operator --();
		virtual Rectangle & operator --(int ignored);

		//Overloads for + and - operators to change dimentions
		Rectangle operator+(double value);
		Rectangle operator-(double value);
		//Static functions to get total area and total perimeter of the rectangles that are created
		inline static double getTotalPerimeter()  { return totalPerimeter; }
		inline static double getTotalArea()  { return totalArea; }
		
		
	private:
		double width;
		double height;
		double x;
		double y;
		double rectarea;
		double rectperimeter;
		static double totalPerimeter;
		static double totalArea;
	
};

#endif
