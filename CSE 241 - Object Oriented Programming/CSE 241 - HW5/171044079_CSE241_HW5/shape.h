#include <iostream>
#include <vector>
#include <string>
#ifndef SHAPE_H_
#define SHAPE_H_
using namespace std;
namespace ShapeErer{
	class Shape{
		public:
			//Pure virtual function area to calculate area
			virtual double area() const =0;
			//Pure virtual function perimeter to calculate perimeter
			virtual double perimeter() const=0;
			//Pure virtual pre and post ++/-- operator overloads to increase and decrease coordinates
			//in derived classes
			virtual Shape & operator++()=0;
			virtual Shape & operator--()=0;
			virtual Shape & operator++(int ignored)=0;
			virtual Shape & operator--(int ignored)=0;
			//Comparison overload operators for class Shape using area function to compare shapes
			bool operator==(const Shape & compared);
			bool operator!=(const Shape & compared);
			bool operator<(const Shape & compared);
			bool operator>(const Shape & compared);
			bool operator<=(const Shape & compared);
			bool operator>=(const Shape & compared);
			//Pure virtual function draw to draw the derived classes from shape class
			virtual void draw(ostream& file) const = 0;
			//Global << operator uses draw function to draw the shapes to an svg file
			friend ostream& operator << (ostream& file, const Shape&s);
			//Pure virtual function shapeName to get derived shape's name
			virtual string shapeName() const = 0;
	};	
}

#endif
