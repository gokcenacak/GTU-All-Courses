#include "Iterator.h"

using std::cout;
using std::endl;
namespace IteratorNamespace{

	template<typename E , typename Container>
	Iterator<E,Container>::Iterator(Container & c){
		iterator=c.begin();
		cont=&c;
	}

	template<typename E , typename Container>
	Iterator<E,Container>::Iterator(){}

	template<typename E , typename Container>
	bool Iterator<E,Container>::hasNext(){
		auto temp = iterator;
		auto temp2=cont->end();
		++temp;
		return (temp!=temp2);
	}

	template<typename E , typename Container>
	E Iterator<E,Container>::next() throw(NoItemException){
		if(hasNext()){
		++iterator;
			return *iterator;
		}
		else{
			throw NoItemException();
		}
	}

	template<typename E , typename Container>
	typename Container::iterator Iterator<E,Container>::getIterator() const{
		return iterator;
	}
	template<typename E , typename Container>
	void Iterator<E,Container>::setIterator(typename Container::iterator it){
		iterator=it;
	}

	template<typename E , typename Container>
	void Iterator<E,Container>::remove(){
		cont->erase(iterator);
	}
	template<typename E , typename Container>
	E Iterator<E,Container>::previous(){
		--iterator;
	}
	template<typename E , typename Container>
	bool Iterator<E,Container>::hasPrevious(){
		auto temp = iterator;
		auto temp2=cont->begin();
		--temp;
		return (temp!=temp2);
	}
}