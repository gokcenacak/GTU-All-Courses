import java.util.*;
import java.awt.Graphics;
import java.lang.*;
/**Shape interface represents geometric shapes like circle,triangle,rectangle,polygons etc. in general
  *Shape interface extends from Comparable interface
*/
public interface Shape extends Comparable{
	/**Calculates the area of the given shape
	 *@return area of the shape
	*/
	double area();
	/**Calculates the perimeter of the given shape
	 *@return perimeter of the shape.
	*/
	double perimeter();
	/**Increments shape coordinates by 1.
	 *@return incremented shape.
	*/
	Shape increment();
	/**Decrements shape coordinates by 1.
	 *@return incremented shape.
	*/
	Shape decrement();
	/**Draws the shape to a panel.
	 *@param g Graphics object used in paintComponent.
	*/
	//This method will be called from the paintComponent meThod of a JPanel object.
	void draw(Graphics g);
	/**Implementation of compareTo function in Comparable interface.
	 *@param s object to be compared with the current shape object.
	*/
	int compareTo(Object s);
}