import java.util.*;
import java.lang.*;
import java.awt.*;
/**PolygonVect class is representing Polygons which holds the point by array list.
  *PolygonVect is a class which extends from Polygon which implements Shape interface's methods, so does this class.
*/
public class PolygonVect extends Polygon{
	private ArrayList<Polygon.Point2D> pointVect = new ArrayList<Polygon.Point2D>();

	/**Constructor that takes a rectangle, calculates the points with rectangle values and adds all the values to the array list variable pointVect
	  *@param rect rectangle to be converted to a polygonvect.
	*/
	public PolygonVect(Rectangle rect) {
		pointVect.add(new Point2D(rect.getxCoor(),rect.getyCoor()));
		pointVect.add(new Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()));
		pointVect.add(new Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()+rect.getHeight()));
		pointVect.add(new Point2D(rect.getxCoor(),rect.getyCoor()+rect.getHeight()));

	}
	/**Constructor that takes a triangle, calculates the points with triangle values and adds all the values to the array list variable pointVect
	  *@param tri triangle to be converted to a polygonvect.
	*/
	public PolygonVect(Triangle tri) {
		pointVect.add(new Point2D(tri.getx1Coor(),tri.gety1Coor()));
		pointVect.add(new Point2D(tri.getx2Coor(),tri.gety2Coor()));
		pointVect.add(new Point2D(tri.getx3Coor(),tri.gety3Coor()));
	}
	/**Constructor that takes a circle, calculates the points with circle values and adds all the values to the array list variable pointVect
	  *@param cir circle to be converted to a polygonvect.
	*/
	public PolygonVect(Circle cir) {
		for(int i=0;i<100;++i){
			pointVect.add(new Point2D(cir.getxCoor()+cir.getRadius()*Math.cos(i*2*Math.PI/100),cir.getyCoor()+cir.getRadius()*Math.sin(i*2*Math.PI/100)));
		}
	}
	/**Constructor that takes a array list of points, adds all the values to the array list variable pointVect
	  *@param points array list of points.
	*/
	public PolygonVect(ArrayList<Polygon.Point2D> points) {
		for(int i=0;i<points.size();++i){
			pointVect.add(points.get(i));
		}
	}
	/**Default constructor pushes one point which is 0,0 into the pointVect vector*/
	public PolygonVect(){
		pointVect.add(new Point2D(0,0));
	}

	//Returns the inner variable pointVect
	public ArrayList<Polygon.Point2D> getPoints(){
		return pointVect;
	}
	/**Draws the polygonvect to a panel.
	  *@param g Graphics object used in paintComponent.
	*/ 
	public void draw(Graphics g){
		int [] xCoords = new int[pointVect.size()];
		int [] yCoords = new int[pointVect.size()];

		for(int i=0;i<xCoords.length;++i){
			xCoords[i]=(int)pointVect.get(i).getX();
			yCoords[i]=(int)pointVect.get(i).getY();
		}

		g.setColor(Color.RED);
       	g.drawPolygon(xCoords,yCoords,pointVect.size());
        //g.fillPolygon(xCoords,yCoords,3);
		
	}
	/**Increments polygonvect points's coordinates by 1.
		  *@return incremented polygonvect.
	*/
	public PolygonVect increment(){
		for(int i=0;i<pointVect.size();++i){
			pointVect.get(i).setX(pointVect.get(i).getX()+1);
			pointVect.get(i).setY(pointVect.get(i).getY()+1);
		}
		return this;
	}
	/**Decrements polygonvect points's coordinates by 1.
		  *@return decremented polygonvect.
	*/
	public PolygonVect decrement(){
		for(int i=0;i<pointVect.size();++i){
			pointVect.get(i).setX(pointVect.get(i).getX()-1);
			pointVect.get(i).setY(pointVect.get(i).getY()-1);
		}
		return this;
	}

	/**Calculates the area of the given polygonvect
		  *@return area of the polygonvect
	*/
	public double area(){
		double a=0.0;
		for(int i=0;i<pointVect.size()-1;++i){
			a+=pointVect.get(i).getX()*pointVect.get(i+1).getY()-pointVect.get(i+1).getX()*pointVect.get(i).getY();
		}
		a+=pointVect.get(pointVect.size()-1).getX()*pointVect.get(0).getY()-pointVect.get(0).getX()*pointVect.get(pointVect.size()-1).getY();
		a=Math.abs(a/2.0);
		
		return a;
	}
	/**Calculates the perimeter of the given polygonvect
		  *@return perimeter of the polygonvect
	*/
	public double perimeter(){
		double p=0.0;
		double difx,dify;
		for(int i=1;i<pointVect.size();++i){
			difx=pointVect.get(i).getX()-pointVect.get(i-1).getX();
			dify=pointVect.get(i).getY()-pointVect.get(i-1).getY();
			p+=Math.sqrt(Math.abs(Math.pow(difx,2)+Math.pow(dify,2)));
		}
		difx=pointVect.get(pointVect.size()-1).getX()-pointVect.get(0).getX();
		dify=pointVect.get(pointVect.size()-1).getY()-pointVect.get(0).getY();
		p+=Math.sqrt(Math.abs(Math.pow(difx,2)+Math.pow(dify,2)));

		return p;
	}
	/**Implementation of compareTo function in Comparable interface.
	  *@param s object to be compared with the current polygonvect object.
	*/
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