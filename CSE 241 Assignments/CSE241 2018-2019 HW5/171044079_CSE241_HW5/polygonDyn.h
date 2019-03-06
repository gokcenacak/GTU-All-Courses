#include <iostream>
#include "polygon.h"
#include <string>

#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

using namespace std;
using namespace ShapeErer;

namespace polygonNamespace{
	//PolygonDyn is a concrete class derived by Polygon abstract class.
	//It stores points in a dynamic array.
	class PolygonDyn : public Polygon{
		public:
			//Constructors
			PolygonDyn(Rectangle rect);
			PolygonDyn(Triangle tri);
			PolygonDyn(Circle cir);
			PolygonDyn();
			PolygonDyn(const vector<Point2D> points);

			//Pre and post ++/-- overloads 
			virtual PolygonDyn & operator++();
			virtual PolygonDyn & operator--();
			virtual PolygonDyn & operator++(int ignored);
			virtual PolygonDyn & operator--(int ignored);

			//Function that returns points as a vector
			virtual vector<Polygon::Point2D> getPoints() const;

			//Returns area
			virtual double area() const;

			//Returns perimeter
			virtual double perimeter() const;

			//Draws a polygonDyn to a svg file
			virtual void draw(ostream& file) const;

			//Returns shape's name
			virtual string shapeName() const;

			//Big three
			~PolygonDyn();
			PolygonDyn(const PolygonDyn& polygonDyn);
			PolygonDyn& operator =(const PolygonDyn& otherPolygonDyn);

		private:
			Polygon::Point2D * pointVect;
			int verticeNum;
		
	};
}

#endif
