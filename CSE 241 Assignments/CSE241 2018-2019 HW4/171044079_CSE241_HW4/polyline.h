#ifndef POLYLINE_H_
#define POLYLINE_H_

#include <iostream>
#include "polygon.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
using namespace std;
using namespace polygonNamespace;
	class PolyLine{
		
		public:
			//Constructors
			PolyLine(const vector<Polygon::Point2D> points);
			PolyLine(Rectangle rect);
			PolyLine(Triangle tri);
			PolyLine(Circle cir);
			PolyLine(Polygon::Point2D point);
			PolyLine(Polygon poly);
			PolyLine();
			//Polygon getter
			inline Polygon getPolygon() { return polylinePolygon; }
			//Overload for << operator
			friend ostream& operator <<(ostream& outputStream, PolyLine& polyline);
			//Overload for == operator
			bool operator ==(const PolyLine& otherPolyLine) const;
			//Overload for + operator
			const PolyLine operator+(const PolyLine& otherPolyLine) const;
		private:
			Polygon polylinePolygon;
	};

#endif
