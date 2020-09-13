#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "polygon.h"
#include "polygonDyn.h"
#include "polygonVect.h"
#include "composedShape.h"
#include "globalFunc.h"
#include "invalidLengthException.h"
#include "invalidCoordinateException.h"
using namespace std;
using namespace ShapeErer;
using namespace polygonNamespace;

int main(){
	Rectangle r(0,0,100,100);
	Rectangle r1(0,0,10,10);	
	Circle c(20,20,20);
	Circle c1(6,6,6);
	Triangle t(30);
	Triangle t1(200);
	ComposedShape cs(r,t);
	ComposedShape cs1(r,c);
	
	ofstream file,file1,file2,file3,file4,file5,file6;
	file.open("composedShapeExample.svg");
	file1.open("polygonDynExample.svg");
	file2.open("polygonVectExample.svg");
	file3.open("printPolyExample.svg");
	file4.open("rectangleExample.svg");
	file5.open("triangleExample.svg");
	file6.open("circleExample.svg");

	cout << "\nTesting of comparison operators of class Shape with a rectangle and a triangle\n";
	if(r1==t1){
		cout << "These two shapes are equal" << endl;
	}
	if(t<c){
		cout << "First shape is smaller than second shape" << endl;
	}
	if(t>c){
		cout << "First shape is bigger than second shape" << endl;
	}
	if(r1>=t1){
		cout << "First shape is bigger or equal to second shape" << endl;
	}
	if(r1<=t1){
		cout << "First shape is smaller or equal to second shape" << endl;
	}
	cout << endl << "Printing of a composed shape... check composedShapeExample.svg file, composedShape's draw uses printAll function, also tests << operator for shape" << endl;
	cs.optimalFit();
	file << cs;
	file << "</svg>";

	cout  << endl << "Testing of polygonDyn...check polygonVectExample.svg" << endl;
	file1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";
	PolygonDyn pd(r);
	cout << "Perimeter of the polygon:" << pd.perimeter() << endl;
	cout << "Area of the polygon:" << pd.area() << endl;
	file1 << pd;

	cout  << endl << "Testing of polygonVect...check polygonVectExample.svg" << endl;
	file2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";
	PolygonVect pv(t1);
	cout << "Perimeter of the polygon:" << pv.perimeter() << endl;
	cout << "Area of the polygon:" << pv.area() << endl;
	file2 << pv;

	cout  << endl << "Testing sorting.." << endl;

	vector<Shape *> sh;
	sh.push_back(&r);
	sh.push_back(&c);
	sh.push_back(&t);
	
	cout  << endl << "Before sorting.." << endl;
	for(int i=0;i<sh.size();++i){
			cout << "Area:" << sh[i]->area() << " Shape Name:" << sh[i]->shapeName()<< endl;
	}
	cout  << endl << "After sorting.." << endl;

	vector<Shape *> testSort = sortShapes(sh);

	for(int i=0;i<testSort.size();++i){
		cout << "Area:" << testSort[i]->area() << " Shape Name:" << testSort[i]->shapeName() << endl;
	}
	file3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";
	cout << "\nTesting of printPoly...check printPolyExample.svg, printPoly uses convertAll function to convert Shape pointers to Polygon pointers" << endl;
	printPoly(file3,sh);

	file1 << "</svg>";
	file2 << "</svg>";
	file3 << "</svg>";

	cout << "\nTesting post ++" << endl;
	cout << "Current value x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;
	Rectangle r2=r1++;
	cout << "Return value: x:" << r2.getxCoor() << " y:" << r2.getyCoor() << endl;
	cout << "New value: x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;

	cout << "\nTesting post --" << endl;
	cout << "Current value x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;
	r2=r1--;
	cout << "Return value: x:" << r2.getxCoor() << " y:" << r2.getyCoor() << endl;
	cout << "New value: x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;

	cout << "\nTesting pre ++" << endl;
	cout << "Current value x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;
	r2=++r1;
	cout << "Return value: x:" << r2.getxCoor() << " y:" << r2.getyCoor() << endl;
	cout << "New value: x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;

	cout << "\nTesting pre --" << endl;
	cout << "Current value x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;
	r2=--r1;
	cout << "Return value: x:" << r2.getxCoor() << " y:" << r2.getyCoor() << endl;
	cout << "New value: x:" << r1.getxCoor() << " y:" << r1.getyCoor() << endl;

	cout << endl << "Exception checks.." << endl;
	try{
		Rectangle rect(0,0,-5,6);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	try{
		Rectangle rect1(0,-10,5,6);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	try{
		Triangle tri(0,0,-5,6,2,9,10);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	try{
		Triangle tri1(-10);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	try{
		Circle cir(-5,0,5);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	try{
		Circle cir1(5,0,-9);
	}
	catch(invalidCoordinateException e){
		cout << "\nCoordinate exception caught" << endl;
		cout << e.what() << endl;
	}
	catch(invalidLengthException e){
		cout << "\nLength exception caught" << endl;
		cout << e.what() << endl;
	}

	cout << endl << "Testing << operator for derived classes of shape..check rectangleExample.svg , triangleExample.svg , circleExample.svg..." << endl;
	file4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";
	file5 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";
	file6 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"1000\" height=\"1000\">";

	file4 << r;
	file5 << t;
	file6 << c;

	file4 << "</svg>";
	file5 << "</svg>";
	file6 << "</svg>";

	cout << endl << "Testing area and perimeter functions for derived classes of shape.." << endl;
	cout << "For rectangle: Area:" << r.area() << " Perimeter:" << r.perimeter() << endl;
	cout << "For triangle: Area:" << t.area() << " Perimeter:" << t.perimeter() << endl;
	cout << "For circle: Area:" << c.area() << " Perimeter:" << c.perimeter() << endl << endl;
}
