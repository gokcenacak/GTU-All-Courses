#include "HashSet.h"
//All necessary comments are provided in HashSet.h
	template<class E , class Container>
	HashSet<E,Container>::HashSet(Container c){
		cont=c;
	}

	template<class E , class Container>
	Iterator<E,Container> HashSet<E,Container>::iterator(){
		Iterator<E,Container> it (cont);
		return it;
	}


	template<class E , class Container>
	void HashSet<E,Container>::add(E e){
		if(!contains(e))
			cont.insert(cont.end(),e);
		else
			cout << "The value you want to add is already in the set." << endl;
		
	}

	template<class E , class Container>
	void HashSet<E,Container>::addAll(Collection<E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				if(!contains(*conti.getIterator()))
					add(*conti.getIterator());
			
		}
		if(!contains(*conti.getIterator()))
			add(*conti.getIterator());
	}

	template<class E , class Container>
	void HashSet<E,Container>::clear(){
		cont.clear();
	}

	template<class E , class Container>
	bool HashSet<E,Container>::contains(E e){
		auto i=iterator();
		for(i;i.hasNext();i.next()){
			if(e == *(i.getIterator()))
				return true;
		}
		if(e == *(i.getIterator()))
			return true;

		return false;
	}

	template<class E , class Container>
	bool HashSet<E,Container>::containsAll(Collection<E,Container> & c){
		int i=0;
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				if(contains(*conti.getIterator()))
					i++;
			
		}
		if(contains(*conti.getIterator()))
			i++;
		if(c.size()==i)
			return true;
		else
			return false;
		
	}

	template<class E , class Container>
	bool HashSet<E,Container>::isEmpty(){
		if(size()==0)
			return true;
		else
			return false;
	}

	template<class E , class Container>
	void HashSet<E,Container>::remove(E e){
		if(contains(e)){
			auto i=iterator();
			for(i;i.hasNext();i.next()){

				if(e == *(i.getIterator())){
					i.remove();
					return;
				}
				

			}
			if(e == *(i.getIterator())){
				i.remove();
				return;
			}
		}
		else{
			cout << "The element you want to remove does not exist in this list." << endl;
		}
	}
	template<class E , class Container>
	void HashSet<E,Container>::removeAll(Collection <E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				if(contains(*conti.getIterator()))
					remove(*conti.getIterator());
			
		}
		if(contains(*conti.getIterator()))
			remove(*conti.getIterator());

	}
	template<class E , class Container>
	void HashSet<E,Container>::retainAll(Collection <E,Container> & c){
		auto i=iterator();
		for(i;i.hasNext();i.next()){
				if(!(c.contains(*i.getIterator()))){
					remove(*i.getIterator());
					i.previous();
				}
		}
		if(!c.contains(*i.getIterator())){
			remove(*i.getIterator());
		}
	}

	template<class E , class Container>
	int HashSet<E,Container>::size(){
		return cont.size();
	}