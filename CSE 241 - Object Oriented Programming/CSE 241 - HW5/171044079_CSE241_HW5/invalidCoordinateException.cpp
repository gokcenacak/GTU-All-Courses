#include "invalidCoordinateException.h"	

const char * invalidCoordinateException::what () const throw(){
	return "Invalid Coordinate Exception"; 
}
