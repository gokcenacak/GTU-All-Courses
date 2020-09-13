#include "LinkedList.h"

template<class E , class Container>
	LinkedList<E,Container>::LinkedList(Container c){
		cont=c;
	};

	template<class E , class Container>
	Iterator<E,Container> LinkedList<E,Container>::iterator(){
		Iterator<E,Container> it (cont);
		return it;
	}


	template<class E , class Container>
	void LinkedList<E,Container>::add(E e) {
			Iterator<E,Container> it(cont);
			cont.insert(cont.end(),e);
			it.setIterator(cont.end());
			it.previous();
	}

	//Segment at string collections
	template<class E , class Container>
	void LinkedList<E,Container>::addAll(Collection<E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
			add(*conti.getIterator());
		}
		add(*conti.getIterator());
	}

	template<class E , class Container>
	void LinkedList<E,Container>::clear(){
		cont.clear();
	}

	template<class E , class Container>
	bool LinkedList<E,Container>::contains(E e){
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
	bool LinkedList<E,Container>::containsAll(Collection<E,Container> & c){
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
	bool LinkedList<E,Container>::isEmpty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	template<class E , class Container>
	void LinkedList<E,Container>::remove(E e){
		Iterator<E,Container> it(cont);
		it=element();
	
		if(*it.getIterator()==e && (cont.begin()!=cont.end())){
			cont.erase(it.getIterator());
			cout << "Deleted" << endl;
		}
		else
			cout << "You cannot delete this element!" << endl;
	}
	template<class E , class Container>
	void LinkedList<E,Container>::removeAll(Collection <E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				if(contains(*conti.getIterator()))
					remove(*conti.getIterator());
			
		}
		if(contains(*conti.getIterator()))
			remove(*conti.getIterator());
	}

	template<class E , class Container>
	void LinkedList<E,Container>::retainAll(Collection <E,Container> & c){
		//Problem
	}

	template<class E , class Container>
	int LinkedList<E,Container>::size(){
		return cont.size();
	}

	template<class E , class Container>
	Iterator<E,Container> LinkedList<E,Container>::element(){
		auto it = iterator();
		return it;
	}

	template<class E , class Container>
	bool LinkedList<E,Container>::offer(E e){
		Iterator<E,Container> it(cont);
		cont.insert(cont.end(),e);
		it.setIterator(cont.end());
		it.previous();
		if(*it.getIterator()==e)
			return true;
		else
			return false;
	}

	template<class E , class Container>
	Iterator<E,Container> LinkedList<E,Container>::poll(){
		auto it = iterator();
		auto temp=it;
		it.remove();
		return temp;
	}
	template<class E , class Container>
	void LinkedList<E,Container>::sort(){
		vector<E> temp;
		auto i=iterator();
		for(i;i.hasNext();i.next()){
			temp.push_back(*i.getIterator());	
		}
		temp.push_back(*i.getIterator());	
		cont.clear();
		std::sort(temp.begin(),temp.end());
		for(int c=0;c<temp.size();c++){
			add(temp[c]);
		}
	}