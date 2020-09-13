#include "polygonDyn.h"

using namespace std;	
using namespace ShapeErer;

namespace polygonNamespace{
	//Constructor that takes a vector of points, creates a new dynamic array and puts the values from the vector to the dynamic array
	PolygonDyn :: PolygonDyn(const vector<Polygon::Point2D> points){
		pointVect=new Point2D[points.size()];
		for(int i=0;i<points.size();++i){
			pointVect[i]=points[i];
		}
		verticeNum=points.size();
	}
	//Constructor that takes a rectangle, creates a new dynamic array and calculates the coordinates from rectangle values and puts them
	//into the dynamic array.
	PolygonDyn :: PolygonDyn(Rectangle rect){
		pointVect=new Point2D[4];
		pointVect[0]=Point2D(rect.getxCoor(),rect.getyCoor());
		pointVect[1]=Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor());
		pointVect[3]=Point2D(rect.getxCoor(),rect.getyCoor()+rect.getHeight());
		pointVect[2]=Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()+rect.getHeight());
		verticeNum=4;
	
	}
	//Constructor that takes a triangle, creates a new dynamic array and calculates the coordinates from triangle values and puts them
	//into the dynamic array.
	PolygonDyn :: PolygonDyn(Triangle tri){
		pointVect=new Point2D[3];
		pointVect[0]=Point2D(tri.getx1Coor(),tri.gety1Coor());
		pointVect[1]=Point2D(tri.getx2Coor(),tri.gety2Coor());
		pointVect[2]=Point2D(tri.getx3Coor(),tri.gety3Coor());
		verticeNum=3;
			
	}
	//Constructor that takes a circle, creates a new dynamic array and calculates the coordinates from circle values and puts them
	//into the dynamic array.
	PolygonDyn :: PolygonDyn(Circle cir){
		pointVect=new Point2D[100];
		for(int i=0;i<100;++i){
			pointVect[i]=Point2D(cir.getxCoor()+cir.getRadius()*cos(i*2*M_PI/99),cir.getyCoor()+cir.getRadius()*sin(i*2*M_PI/99));
		}
		verticeNum=100;
	}
	//Default constructor, initializes only a single point which is 1,1 into the dynamic array.
	PolygonDyn :: PolygonDyn(){
		pointVect=new Point2D[1];
		pointVect[0]=Point2D(0,0);
		verticeNum=1;	
	}
	//Pre increment: Increments all x and y values by one and returns the incremented value
	PolygonDyn & PolygonDyn::operator++(){
		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()+1);
			pointVect[i].setY(pointVect[i].getY()+1);
		}
		return *this;
	}
	//Pre decrement: Decrements all x and y values by one and returns the decremented value
	PolygonDyn & PolygonDyn::operator--(){
		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()-1);
			pointVect[i].setY(pointVect[i].getY()-1);
		}
		return *this;
	}
	//Post increment: Increments all x and y values by one and returns the not-incremented value
	PolygonDyn & PolygonDyn::operator++(int ignored){
		vector<Polygon::Point2D> temp;
		for(int i=0;i<verticeNum;++i){
			temp.push_back(pointVect[i]);
		}

		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()+1);
			pointVect[i].setY(pointVect[i].getY()+1);
		}
		PolygonDyn * pdptr = new PolygonDyn(temp);
		return *pdptr;
	}
	//Post decrement: Decrements all x and y values by one and returns the not-decremented value
	PolygonDyn & PolygonDyn::operator--(int ignored){
		vector<Polygon::Point2D> temp;
		for(int i=0;i<verticeNum;++i){
			temp.push_back(pointVect[i]);
		}

		for(int i=0;i<verticeNum;++i){
			pointVect[i].setX(pointVect[i].getX()-1);
			pointVect[i].setY(pointVect[i].getY()-1);
		}
		PolygonDyn * pdptr = new PolygonDyn(temp);
		return *pdptr;
	}
	//Calculating area of a polygon respect to their points
	double PolygonDyn::area() const{
		double a=0;
		for(int i=0;i<verticeNum-1;++i){
			a+=pointVect[i].getX()*pointVect[i+1].getY()-pointVect[i+1].getX()*pointVect[i].getY();
		}
		a+=pointVect[verticeNum-1].getX()*pointVect[0].getY()-pointVect[0].getX()*pointVect[verticeNum-1].getY();
		a=abs(a/2);
		
		return a;
	}
	//Calculating perimeter of a polygon by calculating the length between its points
	double PolygonDyn::perimeter() const{
		double p=0;
		double difx,dify;
		for(int i=1;i<verticeNum;++i){
			difx=pointVect[i].getX()-pointVect[i-1].getX();
			dify=pointVect[i].getY()-pointVect[i-1].getY();
			p+=sqrt(abs(pow(difx,2)+pow(dify,2)));
		}
		difx=pointVect[verticeNum-1].getX()-pointVect[0].getX();
		dify=pointVect[verticeNum-1].getY()-pointVect[0].getY();
		p+=sqrt(abs(pow(difx,2)+pow(dify,2)));

		return p;
	}
	//Converts dynamic array into a vector and returns it
	vector<Polygon::Point2D> PolygonDyn::getPoints() const{
		vector <Polygon::Point2D> points;
		
		for(int i=0;i<verticeNum;++i){
			points.push_back(pointVect[i]);
		}
		return points;
	}
	//Draws a polygonDyn
	void PolygonDyn::draw(ostream& file) const{

		file << "<polygon points=\"";

		for(int i=0; i<verticeNum;++i){

			file << getPoints()[i].getX() << "," << getPoints()[i].getY() << " ";
		} 
		file << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
	}

	//Big three 
	//Destructor
	PolygonDyn::~PolygonDyn(){
		delete [] pointVect;
	}
	//Copy Constructor
	PolygonDyn :: PolygonDyn(const PolygonDyn& polygonDyn){
			pointVect=new Point2D[polygonDyn.verticeNum];
			for(int i=0;i<polygonDyn.verticeNum;++i){
				pointVect[i]=polygonDyn.getPoints()[i];
			}
			verticeNum=polygonDyn.verticeNum;
	}
	//Assignment Operator
	PolygonDyn& PolygonDyn :: operator =(const PolygonDyn& otherPolygonDyn){
		if(this==&otherPolygonDyn){
			return *this;
		}
		else{
			delete [] pointVect;
			pointVect=new Point2D[otherPolygonDyn.verticeNum];
			verticeNum=otherPolygonDyn.verticeNum;
			for(int i=0;i<verticeNum;++i){
				pointVect[i]=otherPolygonDyn.getPoints()[i];
			}
			return *this;
		}
	}
	//Returns shape name
	string PolygonDyn::shapeName() const{
		return "PolygonDyn";
	}
}






