#include "polyline.h"

		//All these constructors create a polygon object according to their parameters and assign it to the member variable which is a polygon.
		PolyLine::PolyLine(const vector<Polygon::Point2D> points){
			polylinePolygon=Polygon(points);
		}
		PolyLine::PolyLine(Rectangle rect){
			polylinePolygon=Polygon(rect);
		}
		PolyLine::PolyLine(Triangle tri){
			polylinePolygon=Polygon(tri);
		}
		PolyLine::PolyLine(Circle cir){
			polylinePolygon=Polygon(cir);
		}
		PolyLine::PolyLine(Polygon::Point2D point){
			polylinePolygon=Polygon(point);
		}
		PolyLine::PolyLine(Polygon poly){
			polylinePolygon=poly;
		}
		PolyLine::PolyLine(){
			polylinePolygon=Polygon();
		}
		//Overload for << operator to write to a svg file
		ostream& operator <<(ostream& outputStream, PolyLine& polyline){
			
			outputStream << "<polyline points=\"";

			for(int i=0; i<polyline.getPolygon().getVerticeNum();++i){
				outputStream << polyline.getPolygon()[i].getX() << "," << polyline.getPolygon()[i].getY() << " ";
			} 
			outputStream << "\" fill=\"none\" stroke=\"black\" stroke-width=\"2.0\" /> \n";
		}
		//Overload for == for comparing 2 polylines
		bool PolyLine::operator ==(const PolyLine& otherPolyLine) const{
			if(polylinePolygon==otherPolyLine.polylinePolygon){
				return true;
			}
			else
				return false;
		}
		//Overload for + for adding 2 polylines
		const PolyLine PolyLine::operator+(const PolyLine& otherPolyLine) const{
			Polygon p=polylinePolygon+otherPolyLine.polylinePolygon;
			return PolyLine(p);
		}
	
