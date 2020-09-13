#include <fstream>
using namespace std;
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
class Rectangle{
	public:
	      //Initializes the rectangle object with the given x,y coordinates and width,height
		Rectangle(double xCoor, double yCoor, double width, double height);
		//Initializes the rectangle object with x,y coordinates as 0,0 and width and height as 0,0.
		Rectangle();
		//Returns width
		inline double getWidth() const { return width; }
		//Returns height
		inline double getHeight() const { return height; }
		//Returns x coordinate
		inline double getxCoor() const { return x; }
		//Returns y coordinate
		inline double getyCoor() const { return y; }
		//Setting width to rwidth
		void setWidth(double rwidth);
		//Setting height  to rheight
		void setHeight(double rheight);
		//Setting x coordinate to xCoor
		void setxCoor(double xCoor);
		//Setting y coordinate to yCoor
		void setyCoor(double yCoor);
		//Inputs are taken from the user and setted to the created object, yet x and y coordinates are set to 0,0
		void input();
		//Prints the contents of the object
		void output() const;
		//Draws the rectangle object to a svg file
		void draw(ofstream& file) const;
		
	private:
		double width;
		double height;
		double x;
		double y;
	
};

#endif
