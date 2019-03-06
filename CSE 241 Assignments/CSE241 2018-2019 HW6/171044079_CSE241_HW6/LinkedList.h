#include <iostream>
#include "List.h"
#include "Queue.h"
#include <exception>
#include <algorithm>
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
template<class E , class Container>
//ArrayList is a class to represent Linked Lists. Linked Lists work with FIFO principle.

class LinkedList : public List<E,Container>, Queue<E,Container>{
	public:
		//Constructors
		LinkedList(Container c);
		LinkedList();
		//Returns the iterator
		virtual Iterator<E,Container> iterator(); 
		//Adds the given element to the end of the list
		virtual void add(E e); 
		//Adds everything in the given c to the current linked list
		virtual void addAll(Collection<E,Container> & c);
		//Clears the linked list
		virtual void clear();
		//Checks if certain element e is in the linked list
		virtual bool contains(E e);
		//Checks if all the elements in c is contained in the linked list
		virtual bool containsAll(Collection<E,Container> & c);
		//Checks if list is empty
		virtual bool isEmpty();
		//Removes a certain element from the head of the list
		virtual void remove(E e);
		//Removes everything from the given collection if they are at the head of the list
		virtual void removeAll(Collection<E,Container> & c);
		//Removes everything but the same items from the given collection if they are at the head of the list
		virtual void retainAll(Collection<E,Container> & c);
		//Returns the size
		virtual int size();
		//Returns the head
		virtual Iterator<E,Container> element();
		//Adds a given element e
		virtual bool offer(E e); // returns false if cannot add
		//Returns the head and deletes it
		virtual Iterator<E,Container> poll();
		//Sorts the list
		virtual void sort();

	private:
		Container cont;
};
#endif