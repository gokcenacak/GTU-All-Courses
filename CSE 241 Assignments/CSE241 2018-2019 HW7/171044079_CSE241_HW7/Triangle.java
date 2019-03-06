import java.util.*;
import java.lang.*;
import java.awt.*;
/**Triangle class represents triangles.
  *Triangle class implements Shape interface's methods.
*/
public class Triangle implements Shape{

	private double sideLength;
	private	double x1;
	private	double y1;
	private	double x2;
	private	double y2;
	private	double x3;
	private	double y3;
	private	double triperimeter;
	private	double triarea;
	private	static double totalPerimeter;
	private	static double totalArea;

	    /**Triangle constructor which takes a 3 x,y coordinate and also side length
		 *@param xCoor1 x1 coordinate of the point 1 of the triangle
		 *@param yCoor1 y1 coordinate of the point 1 of the triangle
		 *@param xCoor2 x2 coordinate of the point 2 of the triangle
		 *@param yCoor2 y2 coordinate of the point 2 of the triangle
		 *@param xCoor3 x3 coordinate of the point 3 of the triangle
		 *@param yCoor3 y3 coordinate of the point 3 of the triangle
		 *@param side side of the triangle
		*/
		public Triangle(double xCoor1, double yCoor1, double xCoor2, double yCoor2, double xCoor3, double yCoor3, double side){
			setx1Coor(xCoor1);
			sety1Coor(yCoor1);
			setx2Coor(xCoor2);
			sety2Coor(yCoor2);
			setx3Coor(xCoor3);
			sety3Coor(yCoor3);
			setSideLength(side);
			triarea=area();
			triperimeter=perimeter();
			totalPerimeter+=triperimeter;
			totalArea+=triarea;
		}
		 /**Triangle constructor which takes a side length
		  *@param side side of the triangle
		 */
		public Triangle(double side){
			setSideLength(side);
			setx1Coor(side/2);
			sety1Coor(0);
			setx2Coor(0);
			sety2Coor(side*Math.sqrt(3)/2);
			setx3Coor(side);
			sety3Coor(side*Math.sqrt(3)/2);
			triarea=area();
			triperimeter=perimeter();
			totalPerimeter+=triperimeter;
			totalArea+=triarea;
		}
 		/**Default constructor
		*/		
 		public Triangle(){
			setSideLength(0);
			setx1Coor(0);
			sety1Coor(0);
			setx2Coor(0);
			sety2Coor(0);
			setx3Coor(0);
			sety3Coor(0);
			triarea=0;
			triperimeter=0;
			totalPerimeter+=triperimeter;
			totalArea+=triarea;
		}

		/**Getter for side length.
		 *@return side length.
		*/	
		public double getSideLength(){
			return sideLength;
		}
		/**Getter for x1 coordinate.
		 *@return x1 coordinate.
		*/	
		public double getx1Coor(){
			return x1;
		}
		/**Getter for y1 coordinate.
		 *@return y1 coordinate.
		*/	
		public double gety1Coor(){
			return y1;
		}
		/**Getter for x2 coordinate.
		 *@return x2 coordinate.
		*/	
		public double getx2Coor(){
			return x2;
		}
		/**Getter for y2 coordinate.
		 *@return y2 coordinate.
		*/	
		public double gety2Coor(){
			return y2;
		}
		/**Getter for x3 coordinate.
		 *@return x3 coordinate.
		*/	
		public double getx3Coor(){
			return x3;
		}
		/**Getter for y3 coordinate.
		 *@return y3 coordinate.
		*/	
		public double gety3Coor(){
			return y3;
		}

		/**Setter for side length.
		 *@param side side length to be setted.
		*/	
		public void setSideLength(double side) throws RuntimeException{
			if(side<=0){
				throw new RuntimeException("Side length cannot be 0 or negative");
			}
			sideLength=side;
		}
		/**Setter for x1.
		 *@param xCoor1 x1 value to be setted.
		*/	
		public void setx1Coor(double xCoor1)throws RuntimeException{
			if(xCoor1<0){
				throw new RuntimeException("X1 coordinate cannot be negative");
			}
			else{
				x1=xCoor1;
			}
		}
		/**Setter for y1.
		 *@param yCoor1 y1 value to be setted.
		*/	
		public void sety1Coor(double yCoor1)throws RuntimeException{
			if(yCoor1<0){
				throw new RuntimeException("Y1 coordinate cannot be negative");
			}
			else{
				y1=yCoor1;
			}
		}
		/**Setter for x2.
		 *@param xCoor2 x2 value to be setted.
		*/	
		public void setx2Coor(double xCoor2)throws RuntimeException {
			if(xCoor2<0){
				throw new RuntimeException("X2 coordinate cannot be negative");
			}
			else{
				x2=xCoor2;
			}
		}
		/**Setter for y2.
		 *@param yCoor2 y2 value to be setted.
		*/	
		public void sety2Coor(double yCoor2)throws RuntimeException {
			if(yCoor2<0){				
				throw new RuntimeException("Y2 coordinate cannot be negative");
			}
			else{
				y2=yCoor2;
			}
		}
		/**Setter for x3.
		 *@param xCoor3 x3 value to be setted.
		*/	
		public void setx3Coor(double xCoor3)throws RuntimeException {
			if(xCoor3<0){
				throw new RuntimeException("X3 coordinate cannot be negative");
			}
			else{
				x3=xCoor3;
			}
		}
		/**Setter for y3.
		 *@param yCoor3 y3 value to be setted.
		*/	
		public void sety3Coor(double yCoor3)throws RuntimeException {
			if(yCoor3<0){
				throw new RuntimeException("Y3 coordinate cannot be negative");
			}
			else{
				y3=yCoor3;
			}
		}

		
		/**Draws the triangle to a panel.
		 *@param g Graphics object used in paintComponent.
		*/
		public void draw(Graphics g){
			int [] xCoords = new int[3];
			int [] yCoords = new int[3];

			xCoords[0]=(int)x1;
			xCoords[1]=(int)x2;
			xCoords[2]=(int)x3;

			yCoords[0]=(int)y1;
			yCoords[1]=(int)y2;
			yCoords[2]=(int)y3;

			g.setColor(Color.RED);
       	 	g.drawPolygon(xCoords,yCoords,3);
		}

		/**Calculates the perimeter of the given triangle
		 *@return perimeter of the triangle
		*/
		public double perimeter(){
			return 3*sideLength;
		}
		/**Calculates the area of the given triangle
		 *@return area of the triangle
		*/
		public double area(){
			return Math.pow(sideLength,2)*Math.sqrt(3)/4;
		}
		/**Getter for perimeter of the triangle.
		 *@return perimeter of the triangle.
		*/	
		public double getTrianglePerimeter(){
			return triperimeter;
		}
		/**Getter for area of the triangle.
		 *@return area of the triangle.
		*/	
		public double getTriangleArea(){
			return triarea;
		}
		
		/**Getter for total perimeter of the triangles created so far.
		 *@return area of the perimeter area of the triangles created so far.
		*/	
		public static double getTotalPerimeter(){
			return totalPerimeter;
		}
		/**Getter for total area of the triangles created so far.
		 *@return area of the total area of the triangles created so far.
		*/	
		public static double getTotalArea(){
			return totalArea;
		}
		/**Increments triangle's coordinates by 1.
		 *@return incremented triangle.
		*/
		@Override
		public Shape increment(){
			++x1;
			++y1;
			++x2;
			++y2;
			++x3;
			++y3;
			return this;
		}
		/**Decrements triangle's coordinates by 1.
		 *@return decremented triangle.
		*/
		@Override
		public Shape decrement(){
			--x1;
			--y1;
			--x2;
			--y2;
			--x3;
			--y3;
			return this;
		}
		/**Implementation of compareTo function in Comparable interface.
		 *@param s object to be compared with the current triangle object.
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
}