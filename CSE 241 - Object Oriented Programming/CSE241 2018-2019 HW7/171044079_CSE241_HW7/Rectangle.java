import java.util.*;
import java.awt.*;
import java.lang.*;
/**Rectangle class represents rectangles.
  *Rectangle class implements Shape interface's methods.
*/
public class Rectangle implements Shape{
	private double width;
	private	double height;
	private	double x;
	private	double y;
	private	double rectarea;
	private	double rectperimeter;
	private	static double totalPerimeter=0;
	private	static double totalArea=0;

	/**Rectangle constructor which takes a x,y coordinate and also width and height
	 *@param xCoor x coordinate of the left top corner of the rectangle
	 *@param yCoor y coordinate of the left top corner of the rectangle
	 *@param rwidth width of the rectangle
	 *@param rheight height of the rectangle
	*/
	public Rectangle(double xCoor, double yCoor, double rwidth, double rheight){
		setxCoor(xCoor);
		setyCoor(yCoor);
		setWidth(rwidth);
		setHeight(rheight);
		rectarea=area();
		rectperimeter=perimeter();
		totalPerimeter+=rectarea;
		totalArea+=rectperimeter;
	}
	/**Setter for x coordinate.
      *@param xCoor x coordinate to be setted.
	*/
	public void setxCoor(double xCoor) throws RuntimeException{
		if(xCoor<0){
			throw new RuntimeException("You cannot enter a negative number as a x coordinate");
		}
		else{
			x=xCoor;
		}
	}
	/**Setter for y coordinate.
      *@param yCoor y coordinate to be setted.
	*/
	public void setyCoor(double yCoor)throws RuntimeException{
		if(yCoor<0){
			throw new RuntimeException("You cannot enter a negative number as a y coordinate");
		}
		else{
			y=yCoor;
		}
	}
	/**Setter for width.
      *@param rwidth width to be setted.
	*/
	public void setWidth(double rwidth){
		if(rwidth<=0){
			throw new RuntimeException("You cannot enter 0 or a negative number as a width");
		}
		else{
			width=rwidth;
		}
	}
	/**Setter for height.
      *@param rheight height to be setted.
	*/
	public void setHeight(double rheight) throws RuntimeException{
		if(rheight<=0){
			throw new RuntimeException("You cannot enter 0 or a negative number as a height");
		}
		else{
			height=rheight;
		}
	}
	/**Draws the rectangle to a panel.
	 *@param g Graphics object used in paintComponent.
	*/
	public void draw(Graphics g){
		g.setColor(Color.RED);
        g.drawRect((int)this.x,(int)this.y,(int)this.width,(int)this.height);
	}
	/**Increments rectangle's coordinates by 1.
	 *@return incremented rectangle.
	*/
	public Shape increment(){
		++x;
		++y;
		return this;
	}
	/**Decrements rectangle's coordinates by 1.
	 *@return decremented rectangle.
	*/
	public Shape decrement(){
		--x;
		--y;
		return this;
	}
	/**Calculates the area of the given rectangle
	 *@return area of the rectangle
	*/
	public double area(){
		return width*height;
	}
	/**Calculates the perimeter of the given rectangle
	 *@return perimeter of the rectangle
	*/
	public double perimeter(){
		return 2*(width+height);
	}
	/**Getter for x coordinate.
	 *@return x coordinate.
	*/	
	public double getxCoor(){
		return this.x;
	}
	/**Getter for y coordinate.
	 *@return y coordinate.
	*/	
	public double getyCoor(){
		return this.y;
	}
	
	/**Getter for width.
	 *@return width.
	*/	
	public double getWidth(){
		return this.width;
	}
	/**Getter for height.
	 *@return height.
	*/	
	public double getHeight(){
		return this.height;
	}
	/**Implementation of compareTo function in Comparable interface.
	 *@param s object to be compared with the current rectangle object.
	*/
	@Override
	public int compareTo(Object s){
		if(s instanceof Rectangle){
			Rectangle r =(Rectangle)s;
			return (Double.valueOf(this.area()).compareTo(r.area()));
		}
		else if(s instanceof Triangle){
			Triangle t =(Triangle)s;
			return (Double.valueOf(this.area()).compareTo(t.area()));
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
}