import java.util.*;
import java.lang.*;
import java.awt.*;
/**PolygonDyn class is representing Polygons which holds the point by dynamic array.
  *PolygonDyn is a class which extends from Polygon which implements Shape interface's methods, so does this class.
*/
public class PolygonDyn extends Polygon{
	private int verticeNum;
	private Polygon.Point2D pointVect[];
	/**Constructor that takes a array list of points, creates a new dynamic array and puts the values from the vector to the dynamic array
	  *@param points array list of points
	*/

	public PolygonDyn(ArrayList<Polygon.Point2D> points){
		pointVect=new Polygon.Point2D[points.size()];
		for(int i=0;i<points.size();++i){
			pointVect[i]=points.get(i);
		}
		verticeNum=points.size();
	}
	/**Constructor that takes a rectangle, creates a new dynamic array and calculates the coordinates from rectangle values and puts them
	into the dynamic array.
	  *@param rect rectangle to be converted to a polygondyn.
	*/
	public PolygonDyn(Rectangle rect){
		pointVect=new Polygon.Point2D[4];
		pointVect[0]=new Polygon.Point2D(rect.getxCoor(),rect.getyCoor());
		pointVect[1]=new Polygon.Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor());
		pointVect[3]=new Polygon.Point2D(rect.getxCoor(),rect.getyCoor()+rect.getHeight());
		pointVect[2]=new Polygon.Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()+rect.getHeight());
		verticeNum=4;
	
	}
	/**Constructor that takes a triangle, creates a new dynamic array and calculates the coordinates from triangle values and puts them
	into the dynamic array.
	  *@param tri triangle to be converted to a polygondyn.
	*/
	public PolygonDyn(Triangle tri){
		pointVect=new Polygon.Point2D[3];
		pointVect[0]=new Polygon.Point2D(tri.getx1Coor(),tri.gety1Coor());
		pointVect[1]=new Polygon.Point2D(tri.getx2Coor(),tri.gety2Coor());
		pointVect[2]=new Polygon.Point2D(tri.getx3Coor(),tri.gety3Coor());
		verticeNum=3;
			
	}
	/**Constructor that takes a circle, creates a new dynamic array and calculates the coordinates from circle values and puts them
	into the dynamic array.
	*@param cir circle to be converted to a polygondyn.
	*/
	public PolygonDyn(Circle cir){
		pointVect=new Polygon.Point2D[100];
		for(int i=0;i<100;++i){
			pointVect[i]=new Polygon.Point2D(cir.getxCoor()+cir.getRadius()*Math.cos(i*2*Math.PI/100),cir.getyCoor()+cir.getRadius()*Math.sin(i*2*Math.PI/100));
		}

		verticeNum=100;
	}
	/**Default constructor, initializes only a single point which is 1,1 into the dynamic array.*/
	public PolygonDyn(){
		pointVect=new Polygon.Point2D[1];
		pointVect[0]=new Polygon.Point2D(0,0);
		verticeNum=1;	
	}
	/**Increments polygondyn point's coordinates by 1.
		  *@return incremented polygondyn.
	*/
	public Shape increment(){
		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()+1);
			pointVect[i].setY(pointVect[i].getY()+1);
		}
		return this;
	}
	/**Decrements polygondyn point's coordinates by 1.
		  *@return decremented polygondyn.
	*/
	public Shape decrement(){
		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()-1);
			pointVect[i].setY(pointVect[i].getY()-1);
		}
		return this;
	}
	/**Calculates the area of the given polygondyn
		  *@return area of the polygondyn
	*/
	public double area(){
		double a=0.0;
		for(int i=0;i<pointVect.length-1;++i){
			a+=pointVect[i].getX()*pointVect[i+1].getY()-pointVect[i+1].getX()*pointVect[i].getY();
		}
		a+=pointVect[pointVect.length-1].getX()*pointVect[0].getY()-pointVect[0].getX()*pointVect[pointVect.length-1].getY();
		a=Math.abs(a/2.0);
		
		return a;
	}
	/**Calculates the perimeter of the given polygondyn
		  *@return perimeter of the polygondyn
	*/
	public double perimeter(){
		double p=0.0;
		double difx,dify;
		for(int i=1;i<verticeNum;++i){
			difx=pointVect[i].getX()-pointVect[i-1].getX();
			dify=pointVect[i].getY()-pointVect[i-1].getY();
			p+=Math.sqrt(Math.abs(Math.pow(difx,2)+Math.pow(dify,2)));
		}
		difx=pointVect[verticeNum-1].getX()-pointVect[0].getX();
		dify=pointVect[verticeNum-1].getY()-pointVect[0].getY();
		p+=Math.sqrt(Math.abs(Math.pow(difx,2)+Math.pow(dify,2)));

		return p;
	}
	public ArrayList<Polygon.Point2D> getPoints(){
		ArrayList <Polygon.Point2D> points = new ArrayList<Polygon.Point2D>();
		
		for(int i=0;i<verticeNum;++i){
			points.add(pointVect[i]);
		}
		return points;
	}
	/**Draws the polygondyn to a panel.
	  *@param g Graphics object used in paintComponent.
	*/ 
	public void draw(Graphics g){
		int [] xCoords = new int[pointVect.length];
		int [] yCoords = new int[pointVect.length];

		for(int i=0;i<xCoords.length;++i){
			xCoords[i]=(int)pointVect[i].getX();
			yCoords[i]=(int)pointVect[i].getY();
		}

		g.setColor(Color.RED);
       	g.drawPolygon(xCoords,yCoords,pointVect.length);
		
	}
	/**Implementation of compareTo function in Comparable interface.
	  *@param s object to be compared with the current polygondyn object.
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