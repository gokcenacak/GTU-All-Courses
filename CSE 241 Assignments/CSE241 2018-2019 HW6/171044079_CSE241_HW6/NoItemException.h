#include <exception>
#ifndef NOITEMEXCEPTION_H_
#define NOITEMEXCEPTION_H_
using namespace std;
//invalidLengthException is derived from exception class to represent invalid length entries.
class NoItemException : public exception{
	public:
		const char * what () const throw();
};

#endif