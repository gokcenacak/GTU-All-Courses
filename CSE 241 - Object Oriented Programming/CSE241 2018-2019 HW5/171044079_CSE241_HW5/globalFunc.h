#include "shape.h"
#include "polygon.h"
#include <vector>
#include "polygonDyn.h"
#include "polygonVect.h"
using namespace ShapeErer;
using namespace polygonNamespace;
using namespace std;
	//Prints all Shape pointer vector elements to a svg file
	void printAll(ostream& file, vector<Shape *> vect);
	//Converts all Shape pointer vector elements to Polygon pointers then prints them to a svg file
	//Uses convertAll inside
	void printPoly(ostream& file, vector<Shape *> vect);
	//Converts all Shape pointer vector elements to Polygon pointers 
	vector <Polygon *> convertAll(vector<Shape *> vect);
	//Sorts shapes respect to their areas
	vector <Shape *> sortShapes(vector<Shape *> vect);
