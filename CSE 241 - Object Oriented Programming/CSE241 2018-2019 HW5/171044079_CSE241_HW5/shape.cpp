#include <iostream>
#include <vector>
#include "shape.h"
using namespace std;
namespace ShapeErer{
	bool Shape::operator==(const Shape & compared){
		return (this->area()==compared.area());
	}
	bool Shape::operator!=(const Shape & compared){
		return (this->area()!=compared.area());
	}
	bool Shape::operator<(const Shape & compared){
		return (this->area()<compared.area());
	}
	bool Shape::operator>(const Shape & compared){
		return (this->area()>compared.area());
	}
	bool Shape::operator<=(const Shape & compared){
		return (this->area()<=compared.area());
	}
	bool Shape::operator>=(const Shape & compared){
		return (this->area()>=compared.area());
	}

	ostream& operator << (ostream& file, const Shape&s){
		s.draw(file);
		return file;
	}

}
