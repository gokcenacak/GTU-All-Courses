#include <iostream>
#include "Set.h"
#ifndef HASHSET_H_
#define HASHSET_H_
//HashSet is a class to represent Hash Sets. Hash sets only have one per element, it does not have duplicates.
template<class E , class Container>

class HashSet : public Set<E,Container>{
	public:
		//Constructors
		HashSet(Container c);
		HashSet();
		//Returns an iterator
		virtual Iterator<E,Container> iterator(); 
		//Adds an element, also checks if the item is in the hash set or not
		virtual void add(E e);
		//Adds all the elements to the collection from the given collection
		virtual void addAll(Collection<E,Container> & c);
		//Clears the hash set
		virtual void clear();
		//Checks if a certain element e is contained in the collection
		virtual bool contains(E e);
		//Checks if all the given hash set elements are contained in the current hash set
		virtual bool containsAll(Collection<E,Container> & c);
		//Checks if the hash set is empty
		virtual bool isEmpty();
		//Removes a certain element from the hash set
		virtual void remove(E e);
		//Removes all the elements contained in the given hash set from the current hash set
		virtual void removeAll(Collection<E,Container> & c);
		//Removes everything from the current hash set except the same items in both of the collections 
		virtual void retainAll(Collection<E,Container> & c);
		//Returns the size
		virtual int size();
	private:
		Container cont;
 
};

#endif