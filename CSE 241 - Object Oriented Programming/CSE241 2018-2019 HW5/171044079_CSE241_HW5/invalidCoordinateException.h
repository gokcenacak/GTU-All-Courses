#include <exception>
#ifndef INVALIDCOORDINATEEXCEPTION_H_
#define INVALIDCOORDINATEEXCEPTION_H_
using namespace std;

//invalidCoordinateException is derived from exception class to represent invalid coordinate entries.
class invalidCoordinateException : public exception{
	public :
		const char * what () const throw();
};
#endif
