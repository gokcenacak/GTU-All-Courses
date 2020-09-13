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

	ofstream rectFile1,rectFile2,rectFile3,rectFile4,triFile1,triFile2,triFile3,triFile4,cirFile1,cirFile2,cirFile3,cirFile4,file,file1,file2,file3;
	double width;
	decltype(width) height;
	char container;
	decltype(container) inner;

	Rectangle inRect,conRect;
	Triangle inTri,conTri;
	Circle inCir,conCir;

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

	//Creating 4 rectangle objects and also tests for each function
	cout << "Creating 4 rectangle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setxCoor,setyCoor,setWidth,setHeight functions..." << endl;
			rectArray[i].input();

			cout << "Test for output() function ..." << endl;
			rectArray[i].output();

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

		//Creating 4 triangle objects and also tests for each function
		cout << "\n\nCreating 4 triangle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setx1Coor,sety1Coor,setx2Coor,sety2Coor,setx3Coor,sety3Coor,setSideLength functions..." << endl;
			triArray[i].input();
			cout << "Test for output() function ..." << endl;
			triArray[i].output();
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

		//Creating 4 circle objects and also tests for each function
		cout << "\n\nCreating 4 circle objects..." << endl;

		for(int i=0;i<4;++i){
			cout << "Test for input() function that uses setxCoor,setyCoor,setRadius functions..." << endl;
			cirArray[i].input();
			cout << "Test for output() function ..." << endl;
			cirArray[i].output();
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
			//Testing draw function one by one, each test has its own svg file
			cout << "Test for draw for csArray[0]...Results are in the svg file 'output_cs1.svg'\n";
			csArray[0].draw(file);
			cout << "Test for draw for csArray[1]...Results are in the svg file 'output_cs2.svg'\n";
			csArray[1].draw(file1);
			cout << "Test for draw for csArray[2]...Results are in the svg file 'output_cs3.svg'\n";
			csArray[2].draw(file2);
			cout << "Test for draw for csArray[3]...Results are in the svg file 'output_cs4.svg'\n";
			csArray[3].draw(file3);

	
			file << "</svg>";
			file1 << "</svg>";
			file2 << "</svg>";
			file3 << "</svg>";

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
