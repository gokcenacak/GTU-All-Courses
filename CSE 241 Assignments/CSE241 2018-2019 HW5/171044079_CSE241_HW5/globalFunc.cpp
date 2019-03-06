#include "globalFunc.h"
//Definitions and comments are provided in globalFunc.h
	void printAll(ostream& file, vector<Shape *> vect){
		for(int i=0;i<vect.size();++i){
			file << *vect[i];
		}

	}
	void printPoly(ostream& file, vector<Shape *> vect){
		vector<Polygon *> printVect;
		printVect=convertAll(vect);
		for(int i=0;i<printVect.size();++i){
			file << *printVect[i];
		}
	}
	vector <Polygon *> convertAll(vector<Shape *> vect){
		vector<Polygon *> res;
		for(int i=0;i<vect.size();++i){
			if(vect[i]->shapeName()=="Rectangle"){
				Polygon * p = new PolygonVect(*dynamic_cast<Rectangle *>(vect[i]));
				res.push_back(p);
			}
			if(vect[i]->shapeName()=="Triangle"){
				Polygon * p = new PolygonVect(*dynamic_cast<Triangle *>(vect[i]));
				res.push_back(p);
			}
			if(vect[i]->shapeName()=="Circle"){
				Polygon * p = new PolygonVect(*dynamic_cast<Circle *>(vect[i]));
				res.push_back(p);
			}
		}
		return res;
	}
	vector <Shape *> sortShapes(vector<Shape *> vect){
		Shape * temp;
		for(int i=0;i<vect.size()-1;++i){
			for(int j=0;j<vect.size()-i-1;++j){
				if(*vect[j]>*vect[j+1]){
					temp=vect[j];
					vect[j]=vect[j+1];
					vect[j+1]=temp;
				}
			}
		}
		return vect;
	}
