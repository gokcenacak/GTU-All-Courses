#include <fstream>
using namespace std;
#ifndef CIRCLE_H_
#define CIRCLE_H_
class Circle{
	public:
	      //Initializes the rectangle object with the given x,y coordinates and width,height
		Circle(double xCoor, double yCoor, double cradius);
		//Initializes the circle object with x,y coordinates as 0,0 and radius as 0.
		Circle();
		//Returns radius
		inline double getRadius() const { return radius; }
		//Returns x coordinate
		inline double getxCoor() const { return x; }
		//Returns y coordinate
		inline double getyCoor() const { return y; }
		//Sets radius as cradius
		void setRadius(double cradius);
		//Sets x as xCoor
		void setxCoor(double xCoor);
		//Sets y as yCoor
		void setyCoor(double yCoor);

		//Inputs are taken from the user and setted to the created object, yet x,y are set to be
		//radius and radius
		void input();
		//Prints the contents of the object
		void output() const;
		//Draws the circle object to a svg file
		void draw(ofstream& file) const;
		
	private:
		double radius;
		int x;
		int y;
	
};

#endif
