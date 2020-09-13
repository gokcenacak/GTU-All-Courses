#include <exception>
#ifndef INVALIDLENGTHEXCEPTION_H_
#define INVALIDLENGTHEXCEPTION_H_
using namespace std;
//invalidLengthException is derived from exception class to represent invalid length entries.
class invalidLengthException : public exception{
	public:
		const char * what () const throw();
};

#endif
