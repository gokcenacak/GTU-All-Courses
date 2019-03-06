#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "polygon.h"
#include "polyline.h"
#include "composedShape.h"
using namespace std;

int main(){

	ofstream polyFile1,polyFile2,polyFile3,polyFile4,polyFile5,polyFile6;
	ofstream plFile1,plFile2,plFile3,plFile4,plFile5,plFile6;
	ofstream file,file1,file2,file3,file4;
	ofstream composedShapeAddFile,composedShapeAddFile1, composedShapeAddFile2;

	double width;
	decltype(width) height;
	char container;
	decltype(container) inner;

	Rectangle inRect,conRect;
	Triangle inTri,conTri;
	Circle inCir,conCir;


	//Declaring arrays of each class type
	ComposedShape csArray[5];
	Polygon polyArray[5];
	PolyLine plArray[5];
	//Opening output files
	file.open("output_cs1.svg");
	file1.open("output_cs2.svg");
	file2.open("output_cs3.svg");
	file3.open("output_cs4.svg");
	file4.open("output_cs5.svg");
	
	composedShapeAddFile.open("output_cs_addShape1.svg");
	composedShapeAddFile1.open("output_cs_addShape2.svg");
	composedShapeAddFile2.open("output_cs_addShape3.svg");

	polyFile1.open("output_polygon1.svg");
	polyFile2.open("output_polygon2.svg");
	polyFile3.open("output_polygon3.svg");
	polyFile4.open("output_polygon4.svg");
	polyFile5.open("output_polygon5.svg");
	
	polyFile6.open("output_polyadd.svg");

	plFile1.open("output_polyLine1.svg");
	plFile2.open("output_polyLine2.svg");
	plFile3.open("output_polyLine3.svg");
	plFile4.open("output_polyLine4.svg");
	plFile5.open("output_polyLine5.svg");
	plFile6.open("output_polyLineadd.svg");

	polyFile1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	polyFile2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	polyFile3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	polyFile4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	polyFile5 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	polyFile6 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";

	plFile1 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	plFile2 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	plFile3 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	plFile4 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	plFile5 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";
	plFile6 << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << 1000 << "\" height=\"" << 1000  << "\"> \n";

		//Creating 4 composed shape objects and also tests for each function
		cout << "\n\nCreating 4 ComposedShape objects..." << endl;
	
			for(int i=0;i<5;++i){
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
								
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conRect,inTri);
								cs.optimalFit();
								csArray[i]=cs;
								
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conRect,inCir);
								cs.optimalFit();
								csArray[i]=cs;
								
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
								
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conTri,inTri);
								cs.optimalFit();
								csArray[i]=cs;

							
					
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conTri,inCir);
								cs.optimalFit();
								csArray[i]=cs;
								
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
								
							}
							else if(inner=='T' || inner=='t'){
								inTri.input();
								ComposedShape cs(conCir,inTri);
								cs.optimalFit();
								csArray[i]=cs;
							
							}
							else if(inner=='C' || inner=='c'){
								inCir.input();
								ComposedShape cs(conCir,inCir);
								cs.optimalFit();
								csArray[i]=cs;
							
							}
					}
			}
			//Testing [] operator
			cout << "Testing << operator for composedShape object csArray[3]" << endl;
			cout << csArray[3];
			cout << "Testing [] operator for composedShape class with a test rectangle and csArray[3]\nAlso testing << operator for polygon to write to svg file 'output_polygon1.svg'." << endl;
			Rectangle polygonTestRect(5,5,120,210);
			Polygon test2=csArray[3][polygonTestRect];
			polyArray[0]=test2;
			polyFile1 << test2 ;

			cout << "Testing [] operator for composedShape class with a test triangle and csArray[3]\nAlso testing << operator for polygon to write to a svg file 'output_polygon2.svg'." << endl;
			Triangle polygonTestTri(5,5,100,5,7.5,45,100);
			Polygon test3=csArray[3][polygonTestTri];
			polyArray[1]=test3;
			polyFile2 << test3 ;

			cout << "Testing [] operator for composedShape class with a test circle and csArray[3]\nAlso testing << operator for polygon to write to a svg file 'output_polygon3.svg'." << endl;
			Circle polygonTestCir(40,40,40);
			Polygon test4=csArray[3][polygonTestCir];
			polyArray[2]=test4;
			polyFile3 << test4 ;

			//Testing draw function one by one, each test has its own svg file
			cout << "Test for draw for csArray[0]...Results are in the svg file 'output_cs1.svg'\n";
			csArray[0].draw(file);
			cout << "Test for draw for csArray[1]...Results are in the svg file 'output_cs2.svg'\n";
			csArray[1].draw(file1);
			cout << "Test for draw for csArray[2]...Results are in the svg file 'output_cs3.svg'\n";
			csArray[2].draw(file2);
			cout << "Test for draw for csArray[3]...Results are in the svg file 'output_cs4.svg'\n";
			csArray[3].draw(file3);
			cout << "Test for draw for csArray[4]...Results are in the svg file 'output_cs5.svg'\n";
			csArray[4].draw(file4);

			cout << endl;

			cout << "Testing += operator for ComposedShape object having a container rectangle and inner shape as a rectangle, and adding a rectangle to that shape" << endl;
			Rectangle containerRectangle;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle.input();
			Rectangle innerRectangle;
			cout << "Enter inner rectangle dimensions for test composed shape object:\n";
			innerRectangle.input();
			ComposedShape cstest(containerRectangle, innerRectangle);
			cstest.optimalFit();
			cout << "Adding a rectangle to composed shape ...\n";
			cstest+=polygonTestRect;
			cstest.draw(composedShapeAddFile);

			cout << endl;

			cout << "Testing += operator for ComposedShape having a container rectangle and inner shape as a triangle, and adding a triangle to that shape" << endl;
			Rectangle containerRectangle1;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle1.input();
			Triangle innerTriangle;
			cout << "Enter inner triangle dimensions for test composed shape object:\n";
			innerTriangle.input();
			ComposedShape cstest1(containerRectangle1, innerTriangle);
			cstest1.optimalFit();
			cout << "Adding a triangle to composed shape ...\n";
			cstest1+=polygonTestTri;
			cstest1.draw(composedShapeAddFile1);

			cout << endl;

			cout << "Testing += operator for ComposedShape having a container rectangle and inner shape as a circle, and adding a circle to that shape" << endl;
			Rectangle containerRectangle2;
			cout << "Enter container rectangle dimensions for test composed shape object:\n";
			containerRectangle2.input();
			Circle innerCircle;
			cout << "Enter inner circle dimensions for test composed shape object:\n";
			innerCircle.input();
			ComposedShape cstest2(containerRectangle2, innerCircle);
			cstest2.optimalFit();
			cout << "Adding a circle to composed shape ...\n";
			cstest2+=polygonTestCir;
			cstest2.draw(composedShapeAddFile2);
	
			cout << endl;

			Polygon::Point2D A(5,5),B(60,80),C(90,50),D(50,45),E(10,15);
			vector <Polygon::Point2D> points;
			points.push_back(A);
			points.push_back(B);
			points.push_back(C);
			points.push_back(D);
			points.push_back(E);

			cout << "Creating polygon with a point vector with points A(5,5),B(60,80),C(90,50),D(50,45),E(10,15)\n" << endl;
			Polygon testpoly1(points);
			polyArray[3]=testpoly1;
			polyFile4 << testpoly1;

			cout << "Creating polygon with a point with dimentions B(60,80)\n" << endl;
			Polygon testpoly2(B);
			polyArray[4]=testpoly2;
			polyFile5 << testpoly2;

			cout << "Adding 2 polygons together..result can be seen at 'output_polyadd.svg'" << endl;
			Polygon p=polyArray[0]+polyArray[1];
			polyFile6 << p;

			cout << "Testing if 2 polygons are equal, comparison is done between a polygon created by a triangle and a circle" << endl;
			if(polyArray[1]==polyArray[2]){
				cout << "These polygons are equal!" << endl;
			}
			else
				cout << "These polygons are different!" << endl;

			cout << "\nTesting if 2 polygons are equal, comparison is done with a polygon compared to itself" << endl;
			if(polyArray[1]==polyArray[1]){
				cout << "These polygons are equal!" << endl;
			}
			else
				cout << "These polygons are different!" << endl;

			cout << "Creating polyline with a point vector with points A(5,5),B(60,80),C(90,50),D(50,45),E(10,15)\n" << endl;
			PolyLine testpl1(points);
			plArray[0]=testpl1;
			plFile1 << testpl1;

			cout << "Creating polyline with a point with dimentions B(60,80)\n" << endl;
			PolyLine testpl2(B);
			plArray[1]=testpl2;
			plFile2 << testpl2;

			cout << "Creating polyline with a rectangle with dimentions (x=5,y=5,w=120,h=210)\n" << endl;
			PolyLine testpl3(polygonTestRect);
			plArray[2]=testpl3;
			plFile3 << testpl3;

			cout << "Creating polyline with a triangle with dimentions (x1=5,y1=5,x2=100,y2=5,x3=7.5,y3=45)\n" << endl;
			PolyLine testpl4(polygonTestTri);
			plArray[3]=testpl4;
			plFile4 << testpl4;

			cout << "Creating polyline with a circle with dimentions (x=40,y=40,r=40)\n" << endl;
			PolyLine testpl5(polygonTestCir);
			plArray[4]=testpl5;
			plFile5 << testpl5;

			cout << "Adding 2 polylines together..result can be seen at 'output_polyLineadd.svg'" << endl << endl;
			PolyLine pl=plArray[0]+plArray[3];
			plFile6 << pl;

			cout << "Testing if 2 polylines are equal, comparison is done between polylines created by a vector of points and created by a single point:" << endl;
			if(polyArray[0]==polyArray[1]){
				cout << "These polylines are equal!" << endl;
			}
			else
				cout << "These polylines are different!" << endl;

			cout << "\nTesting if 2 polylines are equal, comparison is done with a polygon compared to itself:" << endl;
			if(polyArray[0]==polyArray[0]){
				cout << "These polylines are equal!" << endl;
			}
			else
				cout << "These polylines are different!" << endl;
			file << "</svg>";
			file1 << "</svg>";
			file2 << "</svg>";
			file3 << "</svg>";
			file4 << "</svg>";
			composedShapeAddFile << "</svg>";
			composedShapeAddFile1 << "</svg>";
			composedShapeAddFile2 << "</svg>";

			polyFile1 << "</svg>";
			polyFile2 << "</svg>";
			polyFile3 << "</svg>";
			polyFile4 << "</svg>";
			polyFile5 << "</svg>";
			polyFile6 << "</svg>";

			plFile1 << "</svg>";
			plFile2 << "</svg>";
			plFile3 << "</svg>";
			plFile4 << "</svg>";
			plFile5 << "</svg>";
			plFile6 << "</svg>";
			//Closing all output files
			polyFile1.close();
			polyFile2.close();
			polyFile3.close();
			polyFile4.close();
			polyFile5.close();

			plFile1.close();
			plFile2.close();
			plFile3.close();
			plFile4.close();
			plFile5.close();

			
			file.close();
			file1.close();
			file2.close();
			file3.close();
			file4.close();
	
		return 0;
}

