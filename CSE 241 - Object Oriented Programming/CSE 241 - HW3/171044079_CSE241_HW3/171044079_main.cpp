#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "composedShape.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;
int main(){

	ofstream rectFile1,rectFile2,rectFile3,rectFile4,triFile1,triFile2,triFile3,triFile4,cirFile1,cirFile2,cirFile3,cirFile4,file,file1,file2,file3,composedShapeAddFile,composedShapeAddFile1, composedShapeAddFile2;
	double width;
	decltype(width) height;
	char container;
	decltype(container) inner;

	Rectangle inRect,conRect;
	Triangle inTri,conTri;
	Circle inCir,conCir;


	vector <ComposedShape::ShapeElem> test1;

	//Declaring arrays of each class type
	Rectangle rectArray[4];
	Triangle triArray[4];
	Circle cirArray[4];
	ComposedShape csArray[4];

	//Opening output files
	rectFile1.open("output_rect1.svg");
	triFile1.open("output_tri1.svg");
	cirFile1.open("output_cir1.svg");

	rectFile2.open("output_rect2.svg");
	triFile2.open("output_tri2.svg");
	cirFile2.open("output_cir2.svg");

	rectFile3.open("output_rect3.svg");
	triFile3.open("output_tri3.svg");
	cirFile3.open("output_cir3.svg");

	rectFile4.open("output_rect4.svg");
	triFile4.open("output_tri4.svg");
	cirFile4.open("output_cir4.svg");

	file.open("output_cs1.svg");
	file1.open("output_cs2.svg");
	file2.open("output_cs3.svg");
	file3.open("output_cs4.svg");

	composedShapeAddFile.open("output_cs_addShape1.svg");
	composedShapeAddFile1.open("output_cs_addShape2.svg");
	composedShapeAddFile2.open("output_cs_addShape3.svg");

	//Creating 4 rectangle objects and also tests for each function
	cout << "Creating 4 rectangle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setxCoor,setyCoor,setWidth,setHeight functions..." << endl;
			rectArray[i].input();

			cout << "Test rectangle operator <<" << endl;
			cout << rectArray[i];

			cout << "Test for getxCoor() function ..." << endl;
			cout << rectArray[i].getxCoor() << endl;

			cout << "Test for getyCoor() function ..." << endl;
			cout << rectArray[i].getyCoor() << endl;

			cout << "Test for getWidth() function ..." << endl;
			cout << rectArray[i].getWidth() << endl;

			cout << "Test for getHeight() function ..." << endl;
			cout << rectArray[i].getHeight() << endl;
		}
		//Testing draw function one by one, each test has its own svg file
		cout << "Testing draw for rectArray[0]..Results are in the svg file 'output_rect1.svg'\n" << endl;
		rectFile1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << rectArray[0].getWidth() << "\" height=\"" <<  rectArray[0].getHeight() << "\">";
		rectArray[0].draw(rectFile1);
		rectFile1 << "</svg>";

		cout << "Testing draw for rectArray[1]..Results are in the svg file 'output_rect2.svg'\n" << endl;
		rectFile2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << rectArray[1].getWidth() << "\" height=\"" <<  rectArray[1].getHeight() << "\">";
		rectArray[1].draw(rectFile2);
		rectFile2 << "</svg>";

		cout << "Testing draw for rectArray[2]..Results are in the svg file 'output_rect3.svg'\n" << endl;
		rectFile3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << rectArray[2].getWidth() << "\" height=\"" <<  rectArray[2].getHeight() << "\">";
		rectArray[2].draw(rectFile3);
		rectFile3 << "</svg>";

		cout << "Testing draw for rectArray[3]..Results are in the svg file 'output_rect4.svg'\n" << endl;
		rectFile4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << rectArray[3].getWidth() << "\" height=\"" <<  rectArray[3].getHeight() << "\">";
		rectArray[3].draw(rectFile4);
		rectFile4 << "</svg>";

		cout << "Testing rectangle operators ==/</>/<=/>= on:\n" << endl
		     << "rectArray[0]" << endl << "Area: " << rectArray[0].getRectangleArea() << endl << "Perimeter: " << rectArray[0].getRectanglePerimeter() << endl << endl
		     << "rectArray[1]" << endl << "Area: " << rectArray[1].getRectangleArea() << endl << "Perimeter: " << rectArray[1].getRectanglePerimeter() <<endl
		     << "(Printing smaller and smaller equal, bigger and bigger equal is intentional)\n" << endl;

			if(rectArray[0]>rectArray[1]){
				cout << "rectArray[0] is bigger than rectArray[1]." << endl;
			}
			if(rectArray[0]>=rectArray[1]){
				cout << "rectArray[0] is bigger than or equal to rectArray[1]." << endl;
			}
			if(rectArray[0]<rectArray[1]){
				cout << "rectArray[0] is smaller than rectArray[1]." << endl;
			}
			if(rectArray[0]<=rectArray[1]){
				cout << "rectArray[0] is smaller than or equal to rectArray[1]." << endl;
			}
			if(rectArray[0]==rectArray[1]){
				cout << "rectArray[0] is equal to rectArray[1]." << endl;
			}

		cout << "\nTesting pre increment(++) operator for rectArray[0]\nStart values of x and y:" << rectArray[0].getxCoor() << " " << rectArray[0].getyCoor() << endl;
		Rectangle operatorTestingRect =++rectArray[0];
		cout << "Value returned: x:" << operatorTestingRect.getxCoor() << " y:" << operatorTestingRect.getyCoor() << endl;
		cout << "Changed object: x:" << rectArray[0].getxCoor() << " y:" << rectArray[0].getyCoor() << endl;

		cout << "\nTesting post increment(++) operator for rectArray[0]\nStart values of x and y:" << rectArray[0].getxCoor() << " " << rectArray[0].getyCoor() << endl;
		Rectangle operatorTestingRect1 =rectArray[0]++;
		cout << "Value returned: x:" << operatorTestingRect1.getxCoor() << " y:" << operatorTestingRect1.getyCoor() << endl;
		cout << "Changed object: x:" << rectArray[0].getxCoor() << " y:" << rectArray[0].getyCoor() << endl;

		cout << "\nTesting pre decrement(--) operator for rectArray[0]\nStart values of x and y:" << rectArray[0].getxCoor() << " " << rectArray[0].getyCoor() << endl;
		Rectangle operatorTestingRect2 =--rectArray[0];
		cout << "Value returned: x:" << operatorTestingRect2.getxCoor() << " y:" << operatorTestingRect2.getyCoor() << endl;
		cout << "Changed object: x:" << rectArray[0].getxCoor() << " y:" << rectArray[0].getyCoor() << endl;

		cout << "\nTesting post decrement(--) operator for rectArray[0]\nStart values of x and y:" << rectArray[0].getxCoor() << " " << rectArray[0].getyCoor() << endl;
		Rectangle operatorTestingRect3 =rectArray[0]--;
		cout << "Value returned: x:" << operatorTestingRect3.getxCoor() << " y:" << operatorTestingRect3.getyCoor() << endl;
		cout << "Changed object: x:" << rectArray[0].getxCoor() << " y:" << rectArray[0].getyCoor() << endl;

		cout << "\nTesting + operator for rectArray[0]\nWidth: " << rectArray[0].getWidth() << " Height: " << rectArray[0].getHeight()
	  	     << "\nPlease enter a double value to test:";
		     double testDouble;
		     cin >> testDouble;
		     Rectangle operatorTestingRect4 =rectArray[0]+testDouble; 
		cout << "Returned object values: Width: " << operatorTestingRect4.getWidth() << " Height: " << operatorTestingRect4.getHeight() << endl; 

		cout << "\nTesting - operator for rectArray[0]\nWidth: " << rectArray[0].getWidth() << " Height: " << rectArray[0].getHeight()
	  	     << "\nPlease enter a double value to test:";
		     double testDouble1;
		     cin >> testDouble1;
		Rectangle operatorTestingRect5 =rectArray[0]-testDouble1;
		cout << "Returned object values: Width: " << operatorTestingRect5.getWidth() << " Height: " << operatorTestingRect5.getHeight() << endl; 
  
		cout << "Total rectangle areas so far: " << Rectangle::getTotalArea() << endl;
		cout << "Total rectangle perimeters so far: " << Rectangle::getTotalPerimeter() << endl;
		//Creating 4 triangle objects and also tests for each function
		cout << "\n\nCreating 4 triangle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setx1Coor,sety1Coor,setx2Coor,sety2Coor,setx3Coor,sety3Coor,setSideLength functions..." << endl;
			triArray[i].input();
			cout << "Test for triangle operator <<" << endl;
			cout << triArray[i];
			cout << "Test for getx1Coor() function ..." << endl;
			cout << triArray[i].getx1Coor() << endl;
			cout << "Test for gety1Coor() function ..." << endl;
			cout << triArray[i].gety1Coor() << endl;
			cout << "Test for getx2Coor() function ..." << endl;
			cout << triArray[i].getx2Coor() << endl;
			cout << "Test for gety2Coor() function ..." << endl;
			cout << triArray[i].gety2Coor() << endl;
			cout << "Test for getx3Coor() function ..." << endl;
			cout << triArray[i].getx3Coor() << endl;
			cout << "Test for gety3Coor() function ..." << endl;
			cout << triArray[i].gety3Coor() << endl;
			cout << "Test for getSideLength() function ..." << endl;
			cout << triArray[i].getSideLength() << endl;
		}
		//Testing draw function one by one, each test has its own svg file
		cout << "Testing draw for triArray[0]..Results are in the svg file 'output_tri1.svg'\n" << endl;
		triFile1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << triArray[0].getSideLength() << "\" height=\"" <<  triArray[0].getSideLength()*sqrt(3)/2 << "\">";
		triArray[0].draw(triFile1);
		triFile1 << "</svg>";

		cout << "Testing draw for triArray[1]..Results are in the svg file 'output_tri2.svg'\n" << endl;
		triFile2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << triArray[1].getSideLength() << "\" height=\"" <<  triArray[1].getSideLength()*sqrt(3)/2 << "\">";
		triArray[1].draw(triFile2);
		triFile2 << "</svg>";

		cout << "Testing draw for triArray[2]..Results are in the svg file 'output_tri3.svg'\n" << endl;
		triFile3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << triArray[2].getSideLength() << "\" height=\"" <<  triArray[2].getSideLength()*sqrt(3)/2 << "\">";
		triArray[2].draw(triFile3);
		triFile3 << "</svg>";

		cout << "Testing draw for triArray[3]..Results are in the svg file 'output_tri4.svg'\n" << endl;
		triFile4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << triArray[3].getSideLength() << "\" height=\"" <<  triArray[3].getSideLength()*sqrt(3)/2 << "\">";
		triArray[3].draw(triFile4);
		triFile4 << "</svg>";

		//Test for compare operations such as == > < >= <=
		cout << "Testing triangle operators ==/</>/<=/>= on:\n" << endl
		     << "triArray[0]" << endl << "Area: " << triArray[0].getTriangleArea() << endl << "Perimeter: " << triArray[0].getTrianglePerimeter() << endl << endl
		     << "triArray[1]" << endl << "Area: " << triArray[1].getTriangleArea() << endl << "Perimeter: " << triArray[1].getTrianglePerimeter() <<endl
		     << "(Printing smaller and smaller equal, bigger and bigger equal is intentional)\n" << endl;

			if(triArray[0]>triArray[1]){
				cout << "triArray[0] is bigger than triArray[1]." << endl;
			}
			if(triArray[0]>=triArray[1]){
				cout << "triArray[0] is bigger than or equal to triArray[1]." << endl;
			}
			if(triArray[0]<triArray[1]){
				cout << "triArray[0] is smaller than triArray[1]." << endl;
			}
			if(triArray[0]<=triArray[1]){
				cout << "triArray[0] is smaller than or equal to triArray[1]." << endl;
			}
			if(triArray[0]==triArray[1]){
				cout << "triArray[0] is equal to triArray[1]." << endl;
			}

		//Testing increment and decrement operators
		cout << "\nTesting pre increment(++) operator for triArray[0]\nStart values of x and y: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

			Triangle operatorTestingTri =++triArray[0];

		cout << "Value returned: x1:" << operatorTestingTri.getx1Coor() << " y1: " << operatorTestingTri.gety1Coor() << " x2: "
		     << operatorTestingTri.getx2Coor() << " y2: " << operatorTestingTri.gety2Coor() << " x3: " << operatorTestingTri.getx3Coor() << " y3: " << operatorTestingTri.gety3Coor() << endl;

		cout << "Changed object: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

		cout << "\nTesting post increment(++) operator for triArray[0]\nStart values of x and y: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

			Triangle operatorTestingTri1 =++triArray[0];

		cout << "Value returned: x1:" << operatorTestingTri1.getx1Coor() << " y1: " << operatorTestingTri1.gety1Coor() << " x2: "
		     << operatorTestingTri1.getx2Coor() << " y2: " << operatorTestingTri1.gety2Coor() << " x3: " << operatorTestingTri1.getx3Coor() << " y3: " << operatorTestingTri1.gety3Coor() << endl;

		cout << "Changed object: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

		cout << "\nTesting pre decrement(--) operator for triArray[0]\nStart values of x and y: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

			Triangle operatorTestingTri2 =--triArray[0];

		cout << "Value returned: x1:" << operatorTestingTri2.getx1Coor() << " y1: " << operatorTestingTri2.gety1Coor() << " x2: "
		     << operatorTestingTri2.getx2Coor() << " y2: " << operatorTestingTri2.gety2Coor() << " x3: " << operatorTestingTri2.getx3Coor() << " y3: " << operatorTestingTri2.gety3Coor() << endl;

		cout << "Changed object: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

		cout << "\nTesting post decrement(--) operator for triArray[0]\nStart values of x and y: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

			Triangle operatorTestingTri3 =triArray[0]--;

		cout << "Value returned: x1:" << operatorTestingTri3.getx1Coor() << " y1: " << operatorTestingTri3.gety1Coor() << " x2: "
		     << operatorTestingTri3.getx3Coor() << " y2: " << operatorTestingTri3.gety2Coor() << " x3: " << operatorTestingTri3.getx3Coor() << " y3: " << operatorTestingTri3.gety3Coor() << endl;
		cout << "Changed object: x1: " << triArray[0].getx1Coor() << " y1: " << triArray[0].gety1Coor() << " x2: "
		     << triArray[0].getx2Coor() << " y2: " << triArray[0].gety2Coor() << " x3: " << triArray[0].getx3Coor() << " y3: " << triArray[0].gety3Coor() << endl;

		//This operation causes program exit sometimes because coordinates go to negative values. But it works with some values. Test for a working case is included.
		Triangle testTri(200,200,100,286.6,300,286.6,200);
		cout << "\nTesting + operator for a triangle object\nPS: This operation causes program exit sometimes because coordinates go to negative values.\nSince when values are taken with inputs x and y values are assigned by the program to fit in a SVG file.\nBut it works with some values. Test for a working case is included.\n \nTester Side Length: " << testTri.getSideLength() << endl;
	  	 
		     Triangle operatorTestingTri4 =testTri+10; 
		cout << "Returned object values: Side Length: " << operatorTestingTri4.getSideLength() << endl; 

		cout << "\nTesting - operator for triArray[0]\nSide Length: " << triArray[0].getSideLength()
	  	     << "\nPlease enter a double value to test:";
		     double testDouble3;
		     cin >> testDouble3;
		Triangle operatorTestingTri5 =triArray[0]-testDouble3;
		cout << "Returned object values: Side Length: " << operatorTestingTri5.getSideLength() << endl;

		cout << "Total triangle areas so far: " << Triangle::getTotalArea() << endl;
		cout << "Total triangle perimeters so far: " << Triangle::getTotalPerimeter() << endl;

		//Creating 4 circle objects and also tests for each function
		cout << "\n\nCreating 4 circle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setxCoor,setyCoor,setRadius functions..." << endl;
			cirArray[i].input();
			cout << "Test for << operator " << endl;
			cout << cirArray[i];
			cout << "Test for getxCoor() function ..." << endl;
			cout << cirArray[i].getxCoor() << endl;
			cout << "Test for getyCoor() function ..." << endl;
			cout << cirArray[i].getyCoor() << endl;
			cout << "Test for getRadius() function ..." << endl;
			cout << cirArray[i].getRadius() << endl;
			cout << endl;
		}
		//Testing draw function one by one, each test has its own svg file
		cout << "Testing draw for cirArray[0]..Results are in the svg file 'output_cir1.svg'\n" << endl;
		cirFile1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << cirArray[0].getRadius()*2 << "\" height=\"" << cirArray[0].getRadius()*2  << "\">";
		cirArray[0].draw(cirFile1);
		cirFile1 << "</svg>";

		cout << "Testing draw for cirArray[1]..Results are in the svg file 'output_cir2.svg'\n" << endl;
		cirFile2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << cirArray[1].getRadius()*2 << "\" height=\"" << cirArray[1].getRadius()*2  << "\">";
		cirArray[1].draw(cirFile2);
		cirFile2 << "</svg>";

		cout << "Testing draw for cirArray[2]..Results are in the svg file 'output_cir3.svg'\n" << endl;
		cirFile3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << cirArray[2].getRadius()*2 << "\" height=\"" << cirArray[2].getRadius()*2  << "\">";
		cirArray[2].draw(cirFile3);
		cirFile3 << "</svg>";

		cout << "Testing draw for cirArray[3]..Results are in the svg file 'output_cir4.svg'\n" << endl;
		cirFile4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << cirArray[3].getRadius()*2 << "\" height=\"" << cirArray[3].getRadius()*2  << "\">";
		cirArray[3].draw(cirFile4);
		cirFile4 << "</svg>";

		//Tesing comparing operators such as == > < <= >=
		cout << "Testing circle operators ==/</>/<=/>= on:\n" << endl
		     << "cirArray[0]" << endl << "Area: " << cirArray[0].getCircleArea() << endl << "Perimeter: " << cirArray[0].getCirclePerimeter() << endl << endl
		     << "cirArray[1]" << endl << "Area: " << cirArray[1].getCircleArea() << endl << "Perimeter: " << cirArray[1].getCirclePerimeter() <<endl
		     << "(Printing smaller and smaller equal, bigger and bigger equal is intentional)\n" << endl;

			if(cirArray[0]>cirArray[1]){
				cout << "cirArray[0] is bigger than cirArray[1]." << endl;
			}
			if(cirArray[0]>=cirArray[1]){
				cout << "cirArray[0] is bigger than or equal to cirArray[1]." << endl;
			}
			if(cirArray[0]<cirArray[1]){
				cout << "cirArray[0] is smaller than cirArray[1]." << endl;
			}
			if(cirArray[0]<=cirArray[1]){
				cout << "cirArray[0] is smaller than or equal to cirArray[1]." << endl;
			}
			if(cirArray[0]==cirArray[1]){
				cout << "cirArray[0] is equal to cirArray[1]." << endl;
			}
		//Testing increment and decrement operators for circle
		cout << "\nTesting pre increment(++) operator for cirArray[0]\nStart values of x and y:" << cirArray[0].getxCoor() << " " << cirArray[0].getyCoor() << endl;
		Circle operatorTestingCir =++cirArray[0];
		cout << "Value returned: x:" << operatorTestingCir.getxCoor() << " y:" << operatorTestingCir.getyCoor() << endl;
		cout << "Changed object: x:" << cirArray[0].getxCoor() << " y:" << cirArray[0].getyCoor() << endl;

		cout << "\nTesting post increment(++) operator for cirArray[0]\nStart values of x and y:" << cirArray[0].getxCoor() << " " << cirArray[0].getyCoor() << endl;
		Circle operatorTestingCir1 =cirArray[0]++;
		cout << "Value returned: x:" << operatorTestingCir1.getxCoor() << " y:" << operatorTestingCir1.getyCoor() << endl;
		cout << "Changed object: x:" << cirArray[0].getxCoor() << " y:" << cirArray[0].getyCoor() << endl;

		cout << "\nTesting pre decrement(--) operator for cirArray[0]\nStart values of x and y:" << cirArray[0].getxCoor() << " " << cirArray[0].getyCoor() << endl;
		Circle operatorTestingCir2 =--cirArray[0];
		cout << "Value returned: x:" << operatorTestingCir2.getxCoor() << " y:" << operatorTestingCir2.getyCoor() << endl;
		cout << "Changed object: x:" << cirArray[0].getxCoor() << " y:" << cirArray[0].getyCoor() << endl;

		cout << "\nTesting post decrement(--) operator for cirArray[0]\nStart values of x and y:" << cirArray[0].getxCoor() << " " << cirArray[0].getyCoor() << endl;
		Circle operatorTestingCir3 =cirArray[0]--;
		cout << "Value returned: x:" << operatorTestingCir3.getxCoor() << " y:" << operatorTestingCir3.getyCoor() << endl;
		cout << "Changed object: x:" << cirArray[0].getxCoor() << " y:" << cirArray[0].getyCoor() << endl;

		//Testing + and - operators for circle
		cout << "\nTesting + operator for cirArray[0]\nRadius: " << cirArray[0].getRadius() 
	  	     << "\nPlease enter a double value to test:";
		     double testDouble4;
		     cin >> testDouble4;
		     Circle operatorTestingCir4 =cirArray[0]+testDouble4; 
		cout << "Returned object values: Radius: " << operatorTestingCir4.getRadius() << endl; 

		cout << "\nTesting - operator for cirArray[0]\nRadius: " << cirArray[0].getRadius()
	  	     << "\nPlease enter a double value to test:";
		     double testDouble5;
		     cin >> testDouble5;
		     Circle operatorTestingCir5 =cirArray[0]-testDouble5; 
		cout << "Returned object values: Radius: " << operatorTestingCir5.getRadius() << endl; 
  
		//Testing total area and total perimeter functions for circle
		cout << "Total circle areas so far: " << Circle::getTotalArea() << endl;
		cout << "Total circle perimeters so far: " << Circle::getTotalPerimeter() << endl;

		//Creating 4 composed shape objects and also tests for each function
		cout << "\n\nCreating 4 ComposedShape objects..." << endl;
	
			for(int i=0;i<4;++i){
				cout << "Container shape:";
				cin >> container;
	
					if((container=='R' || container=='r')){
						conRect.input();
						width=conRect.getWidth();
						height=conRect.getHeight();
						cout << "Inner shape:";
						cin >> inner;
							if(inner=='R' || inner=='r'){
								inRect.input();
								ComposedShape cs(conRect,inRect);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conRect,inTri);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conRect,inCir);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
					}
					else if((container=='T' || container=='t')){
						conTri.input();
						width=conTri.getSideLength();
						height=conTri.getSideLength()*sqrt(3)/2;
						cout << "Inner shape:";
						cin >> inner;
							if(inner=='R' || inner=='r'){
								inRect.input();
								ComposedShape cs(conTri,inRect);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conTri,inTri);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
					
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conTri,inCir);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
					}
					else if((container=='C' || container=='c')){
						conCir.input();
						width=conCir.getRadius()*2;
						height=conCir.getRadius()*2;
						cout << "Inner shape:";
						cin >> inner;

							if(inner=='R' || inner=='r'){
								inRect.input();
								ComposedShape cs(conCir,inRect);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conCir,inTri);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conCir,inCir);
								cs.optimalFit();
								csArray[i]=cs;
								test1=cs.getInnerShapeVec();
								cout << "Testing << operator for ShapeElem objects also using getter for inner shape vector of the class" << endl;
									for(int i=0;i<test1.size();i++){
									cout << test1[i] << endl;
								}
							}
					}
			}
			//Testing [] operator
			cout << "Testing << operator for composedShape object csArray[3]" << endl;
			cout << csArray[3];
			cout << "Testing [] operator for composedShape class with a test rectangle and csArray[3]" << endl;
			Rectangle shapeElemTestRect(5,5,120,210);
			ComposedShape::ShapeElem test2=csArray[3][shapeElemTestRect];
			cout << test2 ;

			cout << "Testing [] operator for composedShape class with a test triangle and csArray[3]" << endl;
			Triangle shapeElemTestTri(5,5,100,5,7.5,45,100);
			ComposedShape::ShapeElem test3=csArray[3][shapeElemTestTri];
			cout << test3 ;

			cout << "Testing [] operator for composedShape class with a test circle and csArray[3]" << endl;
			Circle shapeElemTestCir(40,40,40);
			ComposedShape::ShapeElem test4=csArray[3][shapeElemTestCir];
			cout << test4 ;

			//Testing draw function one by one, each test has its own svg file
			cout << "Test for draw for csArray[0]...Results are in the svg file 'output_cs1.svg'\n";
			csArray[0].draw(file);
			cout << "Test for draw for csArray[1]...Results are in the svg file 'output_cs2.svg'\n";
			csArray[1].draw(file1);
			cout << "Test for draw for csArray[2]...Results are in the svg file 'output_cs3.svg'\n";
			csArray[2].draw(file2);
			cout << "Test for draw for csArray[3]...Results are in the svg file 'output_cs4.svg'\n";
			csArray[3].draw(file3);

			cout << "Testing += operator for ComposedShape object having a container rectangle and inner shape as a rectangle, and adding a rectangle to that shape" << endl;
			Rectangle containerRectangle;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle.input();
			Rectangle innerRectangle;
			cout << "Enter inner rectangle dimensions for test composed shape object:\n";
			innerRectangle.input();
			ComposedShape cstest(containerRectangle, innerRectangle);
			cstest.optimalFit();
			cstest+=shapeElemTestRect;
			cstest.draw(composedShapeAddFile);

			cout << "Testing += operator for ComposedShape having a container rectangle and inner shape as a triangle, and adding a triangle to that shape" << endl;
			Rectangle containerRectangle1;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle1.input();
			Triangle innerTriangle;
			cout << "Enter inner triangle dimensions for test composed shape object:\n";
			innerTriangle.input();
			ComposedShape cstest1(containerRectangle1, innerTriangle);
			cstest1.optimalFit();
			cstest1+=shapeElemTestTri;
			cstest1.draw(composedShapeAddFile1);

			cout << "Testing += operator for ComposedShape having a container rectangle and inner shape as a circle, and adding a circle to that shape" << endl;
			Rectangle containerRectangle2;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle2.input();
			Circle innerCircle;
			cout << "Enter inner circle dimensions for test composed shape object:\n";
			innerCircle.input();
			ComposedShape cstest2(containerRectangle2, innerCircle);
			cstest2.optimalFit();
			cstest2+=shapeElemTestCir;
			cstest2.draw(composedShapeAddFile2);
	
			file << "</svg>";
			file1 << "</svg>";
			file2 << "</svg>";
			file3 << "</svg>";
			composedShapeAddFile << "</svg>";
			composedShapeAddFile1 << "</svg>";
			composedShapeAddFile2 << "</svg>";
			//Closing all output files
			rectFile1.close();
			rectFile2.close();
			rectFile3.close();
			rectFile4.close();

			triFile1.close();
			triFile2.close();
			triFile3.close();
			triFile4.close();

			cirFile1.close();
			cirFile2.close();
			cirFile3.close();
			cirFile4.close();

			file.close();
			file1.close();
			file2.close();
			file3.close();
	
		return 0;
}
