#include "ArrayList.h"
#include <vector>
#include <list>
#include <algorithm>
//All necessary comments are provided in ArrayList.h

template<class E , class Container>
	ArrayList<E,Container>::ArrayList(Container c){
		cont=c;
		sort();
	};

	template<class E , class Container>
	Iterator<E,Container> ArrayList<E,Container>::iterator(){
		Iterator<E,Container> it (cont);
		return it;
	}


	template<class E , class Container>
	void ArrayList<E,Container>::add(E e){
			cont.insert(cont.end(),e);
			//sort(); //gives segmentation fault
	}

	template<class E , class Container>
	void ArrayList<E,Container>::addAll(Collection<E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				add(*conti.getIterator());
			
		}
			add(*conti.getIterator());
	}

	template<class E , class Container>
	void ArrayList<E,Container>::clear(){
		cont.clear();
	}

	template<class E , class Container>
	bool ArrayList<E,Container>::contains(E e){
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
	bool ArrayList<E,Container>::containsAll(Collection<E,Container> & c){
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
	bool ArrayList<E,Container>::isEmpty(){
		if(size()==0)
			return true;
		else
			return false;
	}
	template<class E , class Container>
	void ArrayList<E,Container>::remove(E e){
		if(contains(e)){
			auto i=iterator();
			for(i;i.hasNext()==true;i.next()){
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
		else
			cout << "The element you want to remove does not exist in this list." << endl;
	}
	template<class E , class Container>
	void ArrayList<E,Container>::removeAll(Collection <E,Container> & c){
		auto conti=c.iterator();
		for(conti;conti.hasNext();conti.next()){
				if(contains(*conti.getIterator()))
					remove(*conti.getIterator());
			
		}
		if(contains(*conti.getIterator()))
			remove(*conti.getIterator());

	}

	template<class E , class Container>
	void ArrayList<E,Container>::retainAll(Collection <E,Container> & c){
		auto i=iterator();
		for(i;i.hasNext();i.next()){
				if(!c.contains(*i.getIterator())){
					remove(*i.getIterator());
					i.previous();
				}
		}

		if(!c.contains(*i.getIterator())){
			remove(*i.getIterator());
		}
	}

	template<class E , class Container>
	int ArrayList<E,Container>::size(){
		return cont.size();
	}

	template<class E , class Container>
	void ArrayList<E,Container>::sort(){
		list<E> temp;
		auto i=iterator();
		for(i;i.hasNext();i.next()){
			temp.push_back(*i.getIterator());	
		}
		temp.push_back(*i.getIterator());	
		cont.clear();
		temp.sort();
		for(auto i=temp.begin();i!=temp.end();++i){
			add(*i);
		}

	}