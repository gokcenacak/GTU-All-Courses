#include <fstream>
using namespace std;
#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle{
	public:
	      //Initializes the triangle object with the given x1,y1,x2,y2,x3,y3,and a side length
		Triangle(double xCoor1, double yCoor1, double xCoor2, double yCoor2, double xCoor3, double yCoor3, double side);
		//Initializes the triangle object with x1,y1,x2,y2,x3,y3,side length 0
		Triangle();

		//Returns side length
		inline double getSideLength() const { return sideLength; }
		//Returns x1 coordinate
		inline double getx1Coor() const { return x1; }
		//Returns y1 coordinate
		inline double gety1Coor() const { return y1; }
		//Returns x2 coordinate
		inline double getx2Coor() const { return x2; }
		//Returns y2 coordinate
		inline double gety2Coor() const { return y2; }
		//Returns x3 coordinate
		inline double getx3Coor() const { return x3; }
		//Returns y3 coordinate
		inline double gety3Coor() const { return y3; }

		//Sets sideLength as side
		void setSideLength(double side);
		//Sets x1 as xCoor1
		void setx1Coor(double xCoor1);
		//Sets y1 as yCoor1
		void sety1Coor(double yCoor1);
		//Sets x2 as xCoor2
		void setx2Coor(double xCoor2);
		//Sets y2 as yCoor2
		void sety2Coor(double yCoor2);
		//Sets x3 as xCoor3
		void setx3Coor(double xCoor3);
		//Sets y3 as yCoor3
		void sety3Coor(double yCoor3);

		//Inputs are taken from the user and setted to the created object, yet x1,y1,x2,y2,x3,y3 as
		//sideLength/2,0,0,sideLength*sqrt(3)/2,sideLength,sideLength*sqrt(3)/2 (sideLength is taken from user)
		void input();
		//Prints the contents of the object
		void output() const;
		//Draws the object in to a svg file
		void draw(ofstream& file) const;
		
	private:
		double sideLength;
		double x1;
		double y1;
		double x2;
		double y2;
		double x3;
		double y3;
	
};

#endif 
