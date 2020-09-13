#include <iostream>
#include <cstdlib>
#include <cmath>
#include "circle.h"
//Function-constructor implementations of "circle.h", explanatory comments are provided in "circle.h"
	using namespace std;
		double Circle :: totalPerimeter=0;
		double Circle :: totalArea=0;
		Circle::Circle(double xCoor, double yCoor, double cradius) {
			setxCoor(xCoor);
			setyCoor(yCoor);
			setRadius(cradius);
			setCirclePerimeter(cradius);
			setCircleArea(cradius);
			totalPerimeter+=perimeter;
			totalArea+=area;
		}
		//Intentionally empty
		Circle::Circle() : x(0), y(0), radius(0.0) , perimeter(0.0), area(0.0) {}

		void Circle::setxCoor(double xCoor){
			if(xCoor<0){
				cout << "x coordinate cannot be negative." << endl;
				exit(1);
			}
			else{
				x=xCoor;
			}
		}
		void Circle::setyCoor(double yCoor){
			if(yCoor<0){
				cout << "y coordinate cannot be negative." << endl;
				exit(1);
			}
			else{
				y=yCoor;
			}
		}
		void Circle::setRadius(double cradius){
			if(cradius<0){
				cout << "Radius cannot be negative." << endl;
				exit(1);
			}
			else{
				radius=cradius;
			}
		}

		void Circle::setCircleArea(double cradius){
			area=M_PI*pow(cradius,2);
		}

		void Circle::setCirclePerimeter(double cradius){
			perimeter=2*M_PI*cradius;
		}

		void Circle::input(){
			double i_radius;
			cout << "Enter radius:" << endl;
			cin >>i_radius;
			setRadius(i_radius);
			setxCoor(i_radius);
			setyCoor(i_radius);
			setCirclePerimeter(i_radius);
			setCircleArea(i_radius);
			totalPerimeter+=perimeter;
			totalArea+=area;

		}

		void Circle::draw(ofstream& file) const{
			file  << "<circle cx=\"" << x << "\" cy=\""<< y <<"\" r=\"" << radius << "\" fill=\"blue\" stroke=\"black\" stroke-width=\"0.5\"/> \n";

		}

		bool Circle::operator ==(const Circle& circle2) const{
			return (area == circle2.area);
		}
		bool Circle::operator !=(const Circle& circle2) const{
			return (area != circle2.area);
		}
		bool Circle::operator <(const Circle& circle2) const{
			return (area < circle2.area);
		}
		bool Circle::operator >(const Circle& circle2) const{
			return (area > circle2.area);
		}
		bool Circle::operator >=(const Circle& circle2) const{
			return (area >= circle2.area);
		}
		bool Circle::operator <=(const Circle& circle2) const{
			return (area <= circle2.area);
		}

		Circle Circle :: operator ++(){
			x++;
			y++;
			return Circle(x,y,radius);
		}
		Circle Circle :: operator ++(int ignored){
			double tempx=x;
			double tempy=y;
		
			x++;
			y++;
			return Circle(tempx,tempy,radius);		
		}
		Circle Circle :: operator --(){
			x--;
			y--;
			return Circle(x,y,radius);
		}
		Circle Circle :: operator --(int ignored){
			double tempx=x;
			double tempy=y;
		
			x--;
			y--;
			return Circle(tempx,tempy,radius);		
		}
		Circle Circle :: operator+(double value){
			return Circle(x,y,radius+value);
		}
		Circle Circle :: operator-(double value){
			return Circle(x,y,radius-value);
		}
	namespace{
		ostream& operator << (ostream& outputStream, const Circle& cir){
			outputStream << "X Coordinate:" << cir.getxCoor() << endl;
			outputStream << "Y Coordinate:" << cir.getyCoor() << endl ;
			outputStream << "Radius:" << cir.getRadius() << endl;
			outputStream << "Perimeter:" << cir.getCirclePerimeter() << endl;
			outputStream << "Area:" << cir.getCircleArea() << endl;

			return outputStream;
		}
	}


