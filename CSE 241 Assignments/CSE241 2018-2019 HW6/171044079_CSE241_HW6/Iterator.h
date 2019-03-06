#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <exception>
#include <iostream>
#include "NoItemException.h"
//This is the header file Iterator.h. This is the interface for the class Iterator. Objects 
//of this class are iterators with a container class type Container and an inner type for 
//the container, type E.

namespace IteratorNamespace{

	template<typename E , typename Container>

	class Iterator{
		public:
			Iterator(Container & c);
			Iterator();
			bool hasNext();
			E next() throw (NoItemException);
			void remove();
			typename Container::iterator getIterator() const;
			void setIterator(typename Container::iterator it);
			E previous();
			bool hasPrevious();


		private: 
			typename Container::iterator iterator;
			Container * cont;
	};

}
#endif