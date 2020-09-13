#include <iostream>
#include <vector>
#include <cmath>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"
using namespace std;

namespace polygonNamespace{
		//Setters for Point2D 
		void Polygon :: Point2D :: setX(double xCoor){
			x=xCoor;
		}
		void Polygon :: Point2D :: setY(double yCoor){
			y=yCoor;
		}
		Polygon :: Point2D :: Point2D(double x,double y){
			setX(x);
			setY(y);
		}
 		//Constructors for polygon
		Polygon :: Polygon(const vector<Polygon::Point2D> points){
			pointVector=new Point2D[points.size()];
			for(int i=0;i<points.size();++i){
				pointVector[i]=points[i];
			}
			verticeNum=points.size();
		}
		Polygon :: Polygon(Rectangle rect){
			pointVector=new Point2D[4];
			pointVector[0]=Point2D(rect.getxCoor(),rect.getyCoor());
			pointVector[1]=Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor());
			pointVector[3]=Point2D(rect.getxCoor(),rect.getyCoor()+rect.getHeight());
			pointVector[2]=Point2D(rect.getxCoor()+rect.getWidth(),rect.getyCoor()+rect.getHeight());
			verticeNum=4;
	
		}
		Polygon :: Polygon(Triangle tri){
			pointVector=new Point2D[3];
			pointVector[0]=Point2D(tri.getx1Coor(),tri.gety1Coor());
			pointVector[1]=Point2D(tri.getx2Coor(),tri.gety2Coor());
			pointVector[2]=Point2D(tri.getx3Coor(),tri.gety3Coor());
			verticeNum=3;
			
		}
		Polygon :: Polygon(Circle cir){
			pointVector=new Point2D[100];
			verticeNum=100;

			for(int i=0;i<verticeNum;++i){
				pointVector[i]=Point2D(cir.getxCoor()+cir.getRadius()*cos(i*2*M_PI/99),cir.getyCoor()+cir.getRadius()*sin(i*2*M_PI/99));
			}
		}
		Polygon :: Polygon(Point2D point){
			pointVector=new Point2D[1];
			verticeNum=1;
			pointVector[0]=point;
			cout << "WARNING! Point added in point array but one point does not create a polygon.\n";
			
		}
		Polygon :: Polygon(){
			pointVector=new Point2D[1];
			verticeNum=1;
			pointVector[0]=Point2D(0,0);
			
		}
		//BIG THREE
		Polygon :: Polygon(const Polygon& polygon){
			pointVector=new Point2D[polygon.getVerticeNum()];
			for(int i=0;i<polygon.getVerticeNum();++i){
				pointVector[i]=polygon.getPointVector()[i];
			}
			verticeNum=polygon.getVerticeNum();

		}
		Polygon& Polygon :: operator =(const Polygon& otherPolygon){
			if(this==&otherPolygon){
				return *this;
			}
			else{
				delete [] pointVector;
				pointVector=new Point2D[otherPolygon.getVerticeNum()];
				verticeNum=otherPolygon.getVerticeNum();
				for(int i=0;i<verticeNum;++i){
					pointVector[i]=otherPolygon.getPointVector()[i];
				}
				return *this;
			}
			

		}
		Polygon :: ~Polygon(){
			delete [] pointVector;
		}
		//Overload for == operator
		bool Polygon :: operator ==(const Polygon& otherPolygon) const{
			if(verticeNum!=otherPolygon.getVerticeNum()){
				return false;
			}
			else{
				if(verticeNum>=otherPolygon.getVerticeNum()){
					for(int i=0;i<verticeNum;++i){
						if((pointVector[i].getX()!=otherPolygon.getPointVector()[i].getX()) || (pointVector[i].getY()!=otherPolygon.getPointVector()[i].getY()))
							return false;
					}
					return true;
				}
				else{
					for(int i=0;i<otherPolygon.getVerticeNum();++i){
						if((pointVector[i].getX()!=otherPolygon.getPointVector()[i].getX()) || (pointVector[i].getY()!=otherPolygon.getPointVector()[i].getY()))
							return false;
					}
					return true;
				}
			}
		}
		//Overload for + operator
		const Polygon Polygon :: operator+(const Polygon& otherPolygon) const{
			vector<Point2D> temp;
			for(int i=0;i<verticeNum;++i){
				temp.push_back(pointVector[i]);
			}
			for(int i=0;i<otherPolygon.getVerticeNum();++i){
				temp.push_back(otherPolygon.getPointVector()[i]);
			}
			return Polygon(temp);
		}
		//Overload for [] operator
		Polygon::Point2D& Polygon::operator[](int num){
			if(num>=verticeNum){
				cout << "There is no such index in this polygon.." << endl;
			}
			else
				return pointVector[num];
			
		}
		//Overload for << operator
		ostream& operator <<(ostream& outputStream, Polygon& polygon){
			
			outputStream << "<polygon points=\"";

			for(int i=0; i<polygon.getVerticeNum();++i){
				outputStream << polygon[i].getX() << "," << polygon[i].getY() << " ";
			} 
			outputStream << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
		}
}


