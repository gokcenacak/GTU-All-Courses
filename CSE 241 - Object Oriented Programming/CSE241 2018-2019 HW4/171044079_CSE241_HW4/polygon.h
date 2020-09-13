#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <vector>
using namespace std;

namespace polygonNamespace{
	class Polygon{
		
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
		//Constructors
		Polygon(const vector<Point2D> points);
		Polygon(Rectangle rect);
		Polygon(Triangle tri);
		Polygon(Circle cir);
		Polygon(Point2D point);
		Polygon();
		//Big three (Copy constructor, = overload, destructor)
		Polygon(const Polygon& polygon);
		Polygon& operator =(const Polygon& otherPolygon);
		~Polygon();
		//Getters
		inline int getVerticeNum() const { return verticeNum; }
		Point2D * getPointVector() const { return pointVector; }
		//Overloads for certain operators
		bool operator ==(const Polygon& otherPolygon) const;
		const Polygon operator+(const Polygon& otherPolygon) const;
		Point2D& operator[](int num) ;
		friend ostream& operator <<(ostream& outputStream, Polygon& polygon);
		
	private:
		Point2D *pointVector;
		int verticeNum;
	};
}

#endif
