#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "shape.h"
#include <vector>
#include <cmath>
using namespace std;
using namespace ShapeErer;
namespace polygonNamespace{
	//Polygon is an abstract class derived by abstract class Shape to represent polygons.
	class Polygon : public Shape{
		
	public:
		//Inner class point2D for representing points
		class Point2D{
			public:
				Point2D(double x=0.0,double y=0.0);
				inline double getX() const { return x; }
				inline double getY() const { return y; }
				void setX(double xCoor);
				void setY(double yCoor);
				
			private:
				double x;
				double y;
		};
		//Pure virtual area to calculate area at the derived classes
		virtual double area() const =0;
		//Pure virtual perimeter to calculate perimeter at the derived classes
		virtual double perimeter() const=0;
		//Pure virtual pre and post ++/-- operator overloads
		virtual Polygon & operator++()=0;
		virtual Polygon & operator--()=0;
		virtual Polygon & operator++(int ignored)=0;
		virtual Polygon & operator--(int ignored)=0;
		//Pure virtual draw to draw the polygon to an svg file 
		virtual void draw(ostream& file) const = 0;
		//Returns shape's name as Polygon
		virtual string shapeName() const;
		//A function to get points as a vector
		virtual vector<Point2D> getPoints() const = 0;
	};
}

#endif
