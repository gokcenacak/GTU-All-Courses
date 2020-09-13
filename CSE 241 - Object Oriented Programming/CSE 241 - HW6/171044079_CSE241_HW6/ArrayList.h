#include <iostream>
#include "List.h"

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
//ArrayList is a class to represent Array Lists. Array Lists are sorted.

template<class E , class Container>
class ArrayList : public List<E,Container>{
	public:
		//Constructors
		ArrayList(Container c);
		ArrayList();
		//Returns an iterator
		virtual Iterator<E,Container> iterator(); 
		//Adds the given element
		virtual void add(E e);
		//Adds everything in the given c to the current array list
		virtual void addAll(Collection<E,Container> & c);
		//Clears the array list
		virtual void clear();
		//Checks if certain e is in the array list
		virtual bool contains(E e);
		//Checks if every element in c is in the array list
		virtual bool containsAll(Collection<E,Container> & c);
		//Checks if array list is empty.
		virtual bool isEmpty();
		//Removes a certain element e
		virtual void remove(E e);
		//Removes everything that is contained in c from the current array list
		virtual void removeAll(Collection<E,Container> & c);
		//Removes everything except the same elements from the current array list.
		virtual void retainAll(Collection<E,Container> & c);
		//Returns size
		virtual int size();
		//Sorts the array list
		virtual void sort();
	private:
		Container cont;
};

#endif