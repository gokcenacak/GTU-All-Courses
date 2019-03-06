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


		//Sets perimeter
		void setCirclePerimeter(double cradius);
		//Sets area
		void setCircleArea(double cradius);
		//Gets perimeter
		inline double getCirclePerimeter() const { return perimeter; }
		//Gets area
		inline double getCircleArea() const { return area; }
		//Overloads for comparing two circles respect to their areas
		bool operator ==(const Circle& circle2) const;
		bool operator !=(const Circle& circle2) const;
		bool operator <(const Circle& circle2) const;
		bool operator >(const Circle& circle2) const;
		bool operator >=(const Circle& circle2) const;
		bool operator <=(const Circle& circle2) const;
		//Overloads for increment and decrement operators to change positions
		Circle operator ++();
		Circle operator ++(int ignored);
		Circle operator --();
		Circle operator --(int ignored);
		//Overloads for + and - operators to change dimentions
		Circle operator+(double value);
		Circle operator-(double value);
		//Overload for printing a circle object to the screen
		friend ostream& operator <<(ostream& outputStream, const Circle& cir);
		//Static functions to get total area and total perimeter of the circles that are created
		inline static double getTotalPerimeter()  { return totalPerimeter; }
		inline static double getTotalArea()  { return totalArea; }
		
		//Inputs are taken from the user and setted to the created object, yet x,y are set to be
		//radius and radius
		void input();
		//Draws the circle object to a svg file
		void draw(ofstream& file) const;
		
	private:
		double radius;
		int x;
		int y;
		double perimeter;
		double area;
		static double totalPerimeter;
		static double totalArea;
	
};

#endif
