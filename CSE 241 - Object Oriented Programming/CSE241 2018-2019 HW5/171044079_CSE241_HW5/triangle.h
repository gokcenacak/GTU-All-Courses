#include <iostream>
#include <fstream>
#include "shape.h"
#include "invalidLengthException.h"
#include "invalidCoordinateException.h"
using namespace std;
using namespace ShapeErer;
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
//Triangle is a concrete class derived from abstract class Shape to represent triangle.
class Triangle : public Shape{
	public:
	      //Initializes the triangle object with the given x1,y1,x2,y2,x3,y3,and a side length
		Triangle(double xCoor1, double yCoor1, double xCoor2, double yCoor2, double xCoor3, double yCoor3, double side);
		Triangle(double side);
		//Initializes the triangle object with x1,y1,x2,y2,x3,y3,side length 0
		Triangle();

		//Returns side length
		inline double getSideLength() const { return sideLength; }
		//Returns x1 coordinate
		inline double getx1Coor() const { return x1; }
		//Returns y1 coordinate
		inline double gety1Coor() const { return y1; }
		//Returns x2 coordinate
		inline double getx2Coor() const { return x2; }
		//Returns y2 coordinate
		inline double gety2Coor() const { return y2; }
		//Returns x3 coordinate
		inline double getx3Coor() const { return x3; }
		//Returns y3 coordinate
		inline double gety3Coor() const { return y3; }

		//Sets sideLength as side
		void setSideLength(double side) throw(invalidLengthException);
		//Sets x1 as xCoor1
		void setx1Coor(double xCoor1) throw(invalidCoordinateException);
		//Sets y1 as yCoor1
		void sety1Coor(double yCoor1) throw(invalidCoordinateException);
		//Sets x2 as xCoor2
		void setx2Coor(double xCoor2) throw(invalidCoordinateException);
		//Sets y2 as yCoor2
		void sety2Coor(double yCoor2) throw(invalidCoordinateException);
		//Sets x3 as xCoor3
		void setx3Coor(double xCoor3) throw(invalidCoordinateException);
		//Sets y3 as yCoor3
		void sety3Coor(double yCoor3) throw(invalidCoordinateException);

		//Inputs are taken from the user and setted to the created object, yet x1,y1,x2,y2,x3,y3 as
		//sideLength/2,0,0,sideLength*sqrt(3)/2,sideLength,sideLength*sqrt(3)/2 (sideLength is taken from user)
		void input();

		//Draws the object in to a svg file
		virtual void draw(ostream& file) const;

		//Returns perimeter
		virtual double perimeter() const;
		//Returns area
		virtual double area() const;
		//Returns shape's name
		virtual string shapeName() const;

		inline double getTrianglePerimeter() const { return triperimeter; }
		inline double getTriangleArea() const { return triarea; }
		

		//Pre and post ++/-- operator overloads 
		virtual Triangle & operator ++();
		virtual Triangle & operator ++(int ignored);
		virtual Triangle & operator --();
		virtual Triangle & operator --(int ignored);
		//Overloads for + and - operators to change dimentions
		Triangle operator+(double value);
		Triangle operator-(double value);
		//Static functions to get total area and total perimeter of the triangles that are created
		inline static double getTotalPerimeter()  { return totalPerimeter; }
		inline static double getTotalArea()  { return totalArea; }
		
		
	private:
		double sideLength;
		double x1;
		double y1;
		double x2;
		double y2;
		double x3;
		double y3;
		double triperimeter;
		double triarea;
		static double totalPerimeter;
		static double totalArea;
	
};

#endif 
