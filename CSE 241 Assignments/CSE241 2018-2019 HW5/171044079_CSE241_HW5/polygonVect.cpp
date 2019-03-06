#include "polygonVect.h"

using namespace std;
using namespace ShapeErer;

namespace polygonNamespace{
	//Constructor that takes a rectangle, calculates the points with rectangle values and pushes all the values to the inner vector variable pointVect
	PolygonVect::PolygonVect(Rectangle rect) {
		pointVect.push_back(Point2D(rect.getxCoor(),rect.getyCoor()));
		pointVect.push_back(Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()));
		pointVect.push_back(Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()+rect.getHeight()));
		pointVect.push_back(Point2D(rect.getxCoor(),rect.getyCoor()+rect.getHeight()));

	}
	//Constructor that takes a triangle, calculates the points with triangle values and pushes all the values to the inner vector variable pointVect
	PolygonVect::PolygonVect(Triangle tri) {
		pointVect.push_back(Point2D(tri.getx1Coor(),tri.gety1Coor()));
		pointVect.push_back(Point2D(tri.getx2Coor(),tri.gety2Coor()));
		pointVect.push_back(Point2D(tri.getx3Coor(),tri.gety3Coor()));
	}
	//Constructor that takes a circle, calculates the points with circle values and pushes all the values to the inner vector variable pointVect
	PolygonVect::PolygonVect(Circle cir) {
		for(int i=0;i<100;++i){
			pointVect.push_back(Point2D(cir.getxCoor()+cir.getRadius()*cos(i*2*M_PI/100),cir.getyCoor()+cir.getRadius()*sin(i*2*M_PI/100)));
		}
	}
	//Constructor that takes a vector of points, pushes all the values to the inner vector variable pointVect
	PolygonVect::PolygonVect(const vector<Polygon::Point2D> points) {
		for(int i=0;i<points.size();++i){
			pointVect.push_back(points[i]);
		}
	}
	//Default constructor pushes one point which is 0,0 into the pointVect vector
	PolygonVect::PolygonVect(){
		pointVect.push_back(Point2D(0,0));
	}
	//Pre increment: Increments all x and y values by one and returns the incremented value
	PolygonVect & PolygonVect::operator++(){
		for(int i=0;i<pointVect.size();++i){
			pointVect[i].setX(pointVect[i].getX()+1);
			pointVect[i].setY(pointVect[i].getY()+1);
		}
		return *this;
	}
	//Pre decrement: Decrements all x and y values by one and returns the decremented value
	PolygonVect & PolygonVect::operator--(){
		for(int i=0;i<pointVect.size();++i){
			pointVect[i].setX(pointVect[i].getX()-1);
			pointVect[i].setY(pointVect[i].getY()-1);
		}
		return *this;
	}
	//Post increment: Increments all x and y values by one and returns the not-incremented value
	PolygonVect & PolygonVect::operator++(int ignored){
		vector<Polygon::Point2D> temp;
		for(int i=0;i<pointVect.size();++i){
			temp.push_back(pointVect[i]);
		}

		for(int i=0;i<pointVect.size();++i){
			pointVect[i].setX(pointVect[i].getX()+1);
			pointVect[i].setY(pointVect[i].getY()+1);
		}
		PolygonVect * pvptr = new PolygonVect(temp);
		return *pvptr;
	}
	//Post decrement: Decrements all x and y values by one and returns the not-decremented value
	PolygonVect & PolygonVect::operator--(int ignored){
		vector<Polygon::Point2D> temp;
		for(int i=0;i<pointVect.size();++i){
			temp.push_back(pointVect[i]);
		}

		for(int i=0;i<pointVect.size();++i){
			pointVect[i].setX(pointVect[i].getX()-1);
			pointVect[i].setY(pointVect[i].getY()-1);
		}
		PolygonVect * pvptr = new PolygonVect(temp);
		return *pvptr;
	}
	//Calculating area of a polygon respect to their points
	double PolygonVect::area() const{
		double a=0;
		for(int i=0;i<pointVect.size()-1;++i){
			a+=pointVect[i].getX()*pointVect[i+1].getY()-pointVect[i+1].getX()*pointVect[i].getY();
		}
		a+=pointVect[pointVect.size()-1].getX()*pointVect[0].getY()-pointVect[0].getX()*pointVect[pointVect.size()-1].getY();
		a=abs(a/2);
		
		return a;
	}
	//Calculating perimeter of a polygon by calculating the length between its points
	double PolygonVect::perimeter() const{
		double p=0;
		double difx,dify;
		for(int i=1;i<pointVect.size();++i){
			difx=pointVect[i].getX()-pointVect[i-1].getX();
			dify=pointVect[i].getY()-pointVect[i-1].getY();
			p+=sqrt(abs(pow(difx,2)+pow(dify,2)));
		}
		difx=pointVect[pointVect.size()-1].getX()-pointVect[0].getX();
		dify=pointVect[pointVect.size()-1].getY()-pointVect[0].getY();
		p+=sqrt(abs(pow(difx,2)+pow(dify,2)));

		return p;
	}
	//Returns the inner variable pointVect
	vector<Polygon::Point2D> PolygonVect::getPoints() const{
		return pointVect;
	}
	//Draws a polygonDyn
	void PolygonVect::draw(ostream& file) const{
		file << "<polygon points=\"";

		for(int i=0; i<pointVect.size();++i){

			file << pointVect[i].getX() << "," << pointVect[i].getY() << " ";
		} 
		file << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
	}
	//Returns shape's name
	string PolygonVect::shapeName() const {
		return "PolygonVect";
	}
}
