#include <iostream>
#include <vector>
#include <cmath>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"
using namespace std;
using namespace ShapeErer;
namespace polygonNamespace{
		//Setters for Point2D 
		void Polygon :: Point2D :: setX(double xCoor){
			x=xCoor;
		}
		void Polygon :: Point2D :: setY(double yCoor){
			y=yCoor;
		}
		Polygon :: Point2D :: Point2D(double x,double y){
			setX(x);
			setY(y);
		}
		string Polygon::shapeName() const{
			return "Polygon";
		}
}


