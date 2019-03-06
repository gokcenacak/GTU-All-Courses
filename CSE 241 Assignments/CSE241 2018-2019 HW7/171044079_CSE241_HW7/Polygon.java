import java.util.*;
import java.lang.*;
import java.awt.*;

/**Polygon abstract class is representing Polygons
  *Polygon is an abstract class which implements Shape interface's methods.
*/

public abstract class Polygon implements Shape{

		/**Inner class point2D for representing points*/
		public class Point2D{
				private double x;
				private double y;
				/**Point2D constructor that takes x and y value
				  *@param x x coordinate
				  *@param y y coordinate
				*/
				public Point2D(double x,double y){
					setX(x);
					setY(y);
				}
				/**Point2D default constructor 
				*/
				public Point2D(){
					setX(0.0);
					setY(0.0);
				}
				/**Getter for x coordinate of the point
				  *@return x coordinate of the point
				*/
				public double getX(){ 
					return x;
				}
				/**Getter for y coordinate of the point
				  *@return y coordinate of the point
				*/
				public double getY(){
					return y;
				}
				/**Setter for x coordinate of the point
				  *@param xCoor x coordinate of the point
				*/
				public void setX(double xCoor){
					x=xCoor;
				}
				/**Setter for y coordinate of the point
				  *@param yCoor y coordinate of the point
				*/
				public void setY(double yCoor){
					y=yCoor;
				}
				
		}

		/**Calculates the area of the given polygon
		  *@return area of the polygon
		*/
		public abstract double area();
		/**Calculates the perimeter of the given polygon
		  *@return perimeter of the polygon
		*/
		public abstract double perimeter();
		/**Increments polygon point's coordinates by 1.
		  *@return incremented polygon.
		*/
		public abstract Shape increment();
		/**Decrements polygon point's coordinates by 1.
		  *@return decremented polygon.
		*/
		public abstract Shape decrement();
		/**Implementation of compareTo function in Comparable interface.
		  *@param s object to be compared with the current polygon object.
		*/
		public abstract int compareTo(Object s);
		/**Draws the polygon to a panel.
		  *@param g Graphics object used in paintComponent.
		*/ 
		public abstract void draw(Graphics g);
		public abstract ArrayList<Point2D> getPoints();
}