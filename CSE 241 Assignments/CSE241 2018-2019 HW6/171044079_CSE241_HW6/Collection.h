#include <iostream>
#include "Iterator.h"
#ifndef COLLECTION_H_
#define COLLECTION_H_
using namespace std;
using namespace IteratorNamespace;
template<class E , class Container>
//Collection is a class created to represent Java Collections.
class Collection{
	public:
		virtual Iterator<E,Container> iterator()=0; 
		virtual void add(E e)=0;
		virtual void addAll(Collection & c)=0;
		virtual void clear()=0;
		virtual bool contains(E e)=0;
		virtual bool containsAll(Collection & c)=0;
		virtual bool isEmpty()=0;
		virtual void remove(E e)=0;
		virtual void removeAll(Collection & c)=0;
		virtual void retainAll(Collection & c)=0;
		virtual int size()=0;

};
#endif