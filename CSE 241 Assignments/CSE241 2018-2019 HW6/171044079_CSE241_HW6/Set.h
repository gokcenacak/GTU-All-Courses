#include <iostream>
#include "Collection.h"
#ifndef SET_H_
#define SET_H_

template<class E , class Container>
//This class represents Set intenface in Java.
class Set : public Collection<E,Container>{
	public:
		virtual Iterator<E,Container> iterator()=0; 
		virtual void add(E e)=0;
		virtual void addAll(Collection<E,Container> & c)=0;
		virtual void clear()=0;
		virtual bool contains(E e)=0;
		virtual bool containsAll(Collection<E,Container> & c)=0;
		virtual bool isEmpty()=0;
		virtual void remove(E e)=0;
		virtual void removeAll(Collection<E,Container> & c)=0;
		virtual void retainAll(Collection<E,Container> & c)=0;
		virtual int size()=0;	
};
#endif