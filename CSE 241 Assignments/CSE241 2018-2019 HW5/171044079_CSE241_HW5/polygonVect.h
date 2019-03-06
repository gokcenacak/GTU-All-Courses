#include <iostream>
#include "polygon.h"
#include <string>

#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_

using namespace std;
using namespace ShapeErer;

namespace polygonNamespace{
	//PolygonVect is a concrete class derived by Polygon abstract class.
	//It stores points in a STL vector.
	class PolygonVect : public Polygon{
		public:
			//Constructors 
			PolygonVect(Rectangle rect);
			PolygonVect(Triangle tri);
			PolygonVect(Circle cir);
			PolygonVect();
			PolygonVect(const vector<Point2D> points);
			
			//Pre and post ++/-- overloads
			virtual PolygonVect & operator++();
			virtual PolygonVect & operator--();
			virtual PolygonVect & operator++(int ignored);
			virtual PolygonVect & operator--(int ignored);

			//Function that returns points as a vector
			virtual vector<Polygon::Point2D> getPoints() const;

			//Returns area of a polygonVect
			virtual double area() const;

			//Returns perimeter of a polygonVect
			virtual double perimeter() const;

			//Draws a polygonVect to a svg file
			virtual void draw(ostream& file) const;

			//Returns shape's name
			virtual string shapeName() const;
		
		private:
			vector<Polygon::Point2D> pointVect;
		
	};
}

#endif
