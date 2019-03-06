#include <iostream>
#include <fstream>
#include "shape.h"
#include "invalidLengthException.h"
#include "invalidCoordinateException.h"
using namespace std;
using namespace ShapeErer;
#ifndef CIRCLE_H_
#define CIRCLE_H_
//Circle is a concrete class derived from abstract class Shape to represent circles.
class Circle : public Shape{
	public:
	      //Initializes the rectangle object with the given x,y coordinates and width,height
		Circle(double xCoor, double yCoor, double cradius);
		//Default constructor
		Circle();
		//Returns radius
		inline double getRadius() const { return radius; }
		//Returns x coordinate
		inline double getxCoor() const { return x; }
		//Returns y coordinate
		inline double getyCoor() const { return y; }
		//Getting area
		inline double getArea() const { return cirarea; }
		//Getting perimeter
		inline double getPerimeter() const { return cirperimeter; }
		//Sets radius as cradius
		void setRadius(double cradius) throw(invalidLengthException);
		//Sets x as xCoor
		void setxCoor(double xCoor)  throw(invalidCoordinateException);
		//Sets y as yCoor
		void setyCoor(double yCoor) throw(invalidCoordinateException);

		
		//Returns area
		virtual double area() const;
		//Returns perimeter
		virtual double perimeter() const;
		//Returns shape's name
		virtual string shapeName() const;
		
		//Pre and post ++/-- operator overloads
		virtual Circle & operator ++();
		virtual Circle & operator ++(int ignored);
		virtual Circle & operator --();
		virtual Circle & operator --(int ignored);

		//Overloads for + and - operators to change dimentions
		Circle operator+(double value);
		Circle operator-(double value);
		
		//Static functions to get total area and total perimeter of the circles that are created
		inline static double getTotalPerimeter()  { return totalPerimeter; }
		inline static double getTotalArea()  { return totalArea; }
		
		//Inputs are taken from the user and setted to the created object, yet x,y are set to be
		//radius and radius
		void input();
		//Draws the circle object to a svg file
		virtual void draw(ostream& file) const;
		
	private:
		double radius;
		double x;
		double y;
		double cirarea;
		double cirperimeter;
		static double totalPerimeter;
		static double totalArea;
	
};

#endif
