#include "NoItemException.h"	

const char * NoItemException::what () const throw(){
	return "There is no next item"; 
}