import java.lang.*;
import java.util.Arrays;
/**This class implements Set functions so it implements Set interface.
  *This class is a generic class.
*/
public class HashSet<E> implements Set<E>{
	private Object[] contArr;
	/**
  		*HashSet constructor which takes an E array.
  		*@param arr the array which the container will be for the Hashset.
	 */
	public HashSet(E[] arr){
		contArr=arr.clone();
	}

	/**
	  *Returns a Iterator<E> object that can be used in HashSet.
	  *@return the iterator corresponding to the HashSet.
	*/
	public Iterator<E> iterator(){
		Iterator<E> it = new Iterator<E>(contArr);
		return it;
	}

	/**Adds the given element e to the current HashSet. Makes sure that the element is not in the HashSet already.
	  *@param e the element which will be added to the HashSet.
	*/
	public void add(E e){
		Object[] tempArr=new Object[contArr.length+1];
		for(int i=0;i<contArr.length;++i){
			tempArr[i]=contArr[i];
		}
		if(!(contains(e))){
			tempArr[tempArr.length-1]=e;
			contArr=tempArr;
		}
	} 

	/**Adds the elements to the current HashSet from a given Collection. Makes sure that the element is not in the HashSet already.
	  *@param c the Collection whose elements will be added to the current HashSet.
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public void addAll(Collection<E> c){
		Iterator<E> it;
		for(it=c.iterator();it.hasNext();it.next()){
				if(!contains(it.getElement())){
					add(it.getElement());
				}
			
		}
		if(!contains(it.getElement()))
			add(it.getElement());
	}

	/**Clears the set
	*/
	public void clear(){
		contArr=new Object[0];
	}

	/**Returns the truth value of e existing in the HashSet or not.
	  *@param e the element which will be checked if it is in the HashSet or not.
	  *@return the truth value of if e exists in the HashSet or not
	*/ 
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public boolean contains(E e){
		for(int i=0;i<contArr.length;++i){
			if(e.equals((E)contArr[i]))
				return true;
		}
		return false;
	}

	/**Returns the truth value of all the elements in a given Collection is in the current HashSet or not.
	  *@param c the Collection which will be checked if its all elements are in the current HashSet or not.
	  *@return the truth value of if all elements in the given Collection are in the current HashSet or not.
	*/ 
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public boolean containsAll(Collection<E> c){
		int i=0;
		Iterator<E> it=c.iterator();
		for(it=c.iterator();it.hasNext();it.next()){
				if(contains(it.getElement()))
					i++;
			
		}
		if(contains(it.getElement()))
			i++;
		if(c.size()==i)
			return true;
		else
			return false;

	}

	/**Returns the truth value of HashSet being empty.
	  *@return the truth value of HashSet being empty.
	*/ 
	public boolean isEmpty(){
		if(contArr.length==0)
			return true;
		else
			return false;

	}

	/**Removes the given element e from the current HashSet if it exists.
	  *@param e the element which will be removed from the HashSet.
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public void remove(E e){
		Object[] tempArr=new Object[contArr.length-1];
		if(contains(e)){
			for(int i=0, j=0;i<contArr.length;++i){
				if(e.equals(contArr[i])){
					continue;
				}
				else{
					tempArr[j]=contArr[i];
					j++;
				}
			}
			contArr=tempArr;
		}
	}

	/**Removes the elements from the current HashSet which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current HashSet.
	*/
	public void removeAll(Collection<E> c){
		Iterator<E> it;
		for(it=c.iterator();it.hasNext();it.next()){
				if(contains(it.getElement())){
					remove(it.getElement());
				}
			
		}
		if(contains(it.getElement()))
			remove(it.getElement());
	}

	/**Removes the elements from the current HashSet which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current HashSet.
	*/
	public void retainAll(Collection<E> c){
		Iterator<E> it;
		for(it=iterator();it.hasNext();it.next()){
				if(!c.contains(it.getElement())){
					remove(it.getElement());
				}
			
		}
		if(!c.contains(it.getElement()))
			remove(it.getElement());
	}

	/**Returns the size of the HashSet.
	  *@return the size of the HashSet.
	*/
	public int size(){
		return contArr.length;

	}
	public Object[] getContArray(){
		return contArr;
	}
}