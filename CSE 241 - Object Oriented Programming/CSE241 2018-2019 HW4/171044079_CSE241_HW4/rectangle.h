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
		//Draws the rectangle object to a svg file
		void draw(ofstream& file) const;

		//Setting perimeter
		void setRectanglePerimeter(double rwidth, double rheight);
		//Setting area
		void setRectangleArea(double rwidth, double rheight);
		//Getting perimeter
		inline double getRectanglePerimeter() const { return perimeter; }
		//Getting area
		inline double getRectangleArea() const { return area; }
		//== != < > <= >=  overloads for comparing two rectangles respect to their areas
		bool operator ==(const Rectangle& rectangle2) const;
		bool operator !=(const Rectangle& rectangle2) const;
		bool operator <(const Rectangle& rectangle2) const;
		bool operator >(const Rectangle& rectangle2) const;
		bool operator >=(const Rectangle& rectangle2) const;
		bool operator <=(const Rectangle& rectangle2) const;
		//Overloads for increment and decrement operators to change positions
		Rectangle operator ++();
		Rectangle operator ++(int ignored);
		Rectangle operator --();
		Rectangle operator --(int ignored);
		//Overloads for + and - operators to change dimentions
		Rectangle operator+(double value);
		Rectangle operator-(double value);
		//Static functions to get total area and total perimeter of the rectangles that are created
		inline static double getTotalPerimeter()  { return totalPerimeter; }
		inline static double getTotalArea()  { return totalArea; }
		//Overload for printing a rectangle object to the screen
		friend ostream& operator <<(ostream& outputStream, const Rectangle& rect);
		
	private:
		double width;
		double height;
		double x;
		double y;
		double perimeter;
		double area;
		static double totalPerimeter;
		static double totalArea;
	
};

#endif
