#include "invalidLengthException.h"	

const char * invalidLengthException::what () const throw(){
	return "Invalid Length Exception"; 
}
