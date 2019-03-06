import java.util.*;
import java.lang.*;
import java.awt.*;
/**Circle class represents circles.
  *Circle class implements Shape interface's methods.
*/
public class Circle implements Shape{
	private double radius;
	private	double x;
	private	double y;
	private	double cirarea;
	private	double cirperimeter;
	private	static double totalPerimeter=0;
	private	static double totalArea=0;

	/**Circle constructor which takes a x,y coordinate and a radius.
	 *@param xCoor x coordinate of the center of the circle
	 *@param yCoor y coordinate of the center of the circle
	 *@param cradius radius of the circle
	*/
	public Circle(double xCoor, double yCoor, double cradius){
		setxCoor(xCoor);
		setyCoor(yCoor);
		setRadius(cradius);
		cirarea=area();
		cirperimeter=perimeter();
		totalPerimeter+=cirperimeter;
		totalArea+=cirarea;
	}
	/**Default constructor*/
	public Circle(){
		setxCoor(0);
		setyCoor(0);
		setRadius(0);
		cirarea=0;
		cirperimeter=0;
		totalPerimeter+=cirperimeter;
		totalArea+=cirarea;
	}
	/**Getter for radius.
	  *@return radius of the circle
	*/	
	public double getRadius(){
		return radius;
	}
	/**Getter for x coordinate.
	  *@return x coordinate of the center of the circle
	*/	
	public double getxCoor(){
		return x;
	}
	/**Getter for y coordinate.
	  *@return y coordinate of the center of the circle
	*/	
	public double getyCoor(){
		return y;
	}
	/**Getter for the area of the circle.
	  *@return area of the circle
	*/	
	public double getArea(){
		return cirarea;
	}
	/**Getter for the perimeter of the circle.
	  *@return perimeter of the circle
	*/	
	public double getPerimeter(){
		return cirperimeter;
	}
	/**Getter for the total perimeter of the circles created so far.
	  *@return total perimeter of the circles created so far.
	*/	
	public static double getTotalPerimeter(){
		return totalPerimeter;
	}
	/**Getter for the total areas of the circles created so far.
	  *@return total area of the circles created so far.
	*/	
	public static double getTotalArea(){
		return totalArea;
	}
	/**Setter for the x coordinate of the center of the circle.
	  *@param xCoor x coordinate value to be setted.
	*/	
	public void setxCoor(double xCoor)throws RuntimeException{
		if(xCoor<0){
			throw new RuntimeException("You cannot enter a negative number as a x coordinate");
		}
		else{
			x=xCoor;
		}
	}
	/**Setter for the y coordinate of the center of the circle.
	  *@param yCoor y coordinate value to be setted.
	*/	
	public void setyCoor(double yCoor) throws RuntimeException{
		if(yCoor<0){
			throw new RuntimeException("You cannot enter a negative number as a y coordinate");
		}
		else{
			y=yCoor;
		}
	}
	/**Setter for the radius of the circle.
	  *@param cradius radius value to be setted.
	*/	
	public void setRadius(double cradius)throws RuntimeException{
		if(cradius<=0){
			throw new RuntimeException("You cannot enter 0 or a negative number as a radius");
		}
		else{
			radius=cradius;
		}
	}
	/**Calculates the area of the given circle
	  *@return area of the circle
	*/
	public double area(){
		return Math.PI*Math.pow(radius,2);
	}
	/**Calculates the perimeter of the given circle
	  *@return perimeter of the circle
	*/
	public double perimeter(){
		return 2*Math.PI*radius;
	}
	/**Increments circle's coordinates by 1.
	  *@return incremented circle.
	*/
	@Override
	public Shape increment(){
		++x;
		++y;
		return this;
	}
	/**Decrements circle's coordinates by 1.
	  *@return decremented circle.
	*/
	@Override
	public Shape decrement(){
		--x;
		--y;
		return this;
	}
	/**Implementation of compareTo function in Comparable interface.
	  *@param s object to be compared with the current circle object.
	*/
	@Override
	public int compareTo(Object s){
		if(s instanceof Triangle){
			Triangle t =(Triangle)s;
			return (Double.valueOf(this.area()).compareTo(t.area()));
		}
		else if(s instanceof Rectangle){
			Rectangle r =(Rectangle)s;
			return (Double.valueOf(this.area()).compareTo(r.area()));
		}
		else if(s instanceof Circle){
			Circle c =(Circle)s;
			return (Double.valueOf(this.area()).compareTo(c.area()));
		}
		else if(s instanceof ComposedShape){
			ComposedShape c =(ComposedShape)s;
			return (Double.valueOf(this.area()).compareTo(c.area()));
		}
		else if(s instanceof PolygonDyn){
			PolygonDyn pd =(PolygonDyn)s;
			return (Double.valueOf(this.area()).compareTo(pd.area()));
		}
		else if(s instanceof PolygonVect){
			PolygonVect pv =(PolygonVect)s;
			return (Double.valueOf(this.area()).compareTo(pv.area()));
		}
		else
			return -1;
	}

	/**Draws the circle to a panel.
	  *@param g Graphics object used in paintComponent.
	*/
	public void draw(Graphics g){
			g.setColor(Color.RED);
       	 	g.drawOval((int)(this.x-radius),(int)(this.y-radius),(int)this.radius*2,(int)this.radius*2);
	}
}