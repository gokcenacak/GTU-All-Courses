import java.lang.*;
import java.util.Arrays;
/**This class implements both List and Queue functions so it implements both interfaces.
  *This class is a generic class. Since this class also implements Queue functions elements are not ordered by magnitude.
*/
public class LinkedList<E> implements List<E>,Queue<E>{
	private Object[] contArr;
	/**
  		*LinkedList constructor which takes an E array.
  		*@param arr the array which the container will be for the LinkedList.
	 */
	public LinkedList(E[] arr){
		contArr=arr.clone();
	}

	/**
	  *Returns a Iterator<E> object that can be used in LinkedList.
	  *@return the iterator corresponding to the LinkedList.
	*/
	public Iterator<E> iterator(){
		Iterator<E> it = new Iterator<E>(contArr);
		return it;
	}

	/**Adds the given element e to the end of the current LinkedList.
	  *@param e the element which will be added to the LinkedList.
	*/
	public void add(E e){
		Object[] tempArr=new Object[contArr.length+1];
		for(int i=0;i<contArr.length;++i){
			tempArr[i]=contArr[i];
		}
		tempArr[tempArr.length-1]=e;
		contArr=tempArr;
	}

	/**Adds the elements to the end of the current LinkedList from a given Collection.
	  *@param c the Collection whose elements will be added to the current LinkedList.
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked") 
	public void addAll(Collection<E> c){
		Iterator<E> it;
		for(it=c.iterator();it.hasNext();it.next()){
			add(it.getElement());	
		}
		add(it.getElement());
	}

	/**Clears the list
	*/
	public void clear(){
		contArr=new Object[0];
	}

	/**Returns the truth value of e existing in the LinkedList or not.
	  *@param e the element which will be checked if it is in the LinkedList or not.
	  *@return the truth value of if e exists in the LinkedList or not
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

	/**Returns the truth value of all the elements in a given Collection is in the current LinkedList or not.
	  *@param c the Collection which will be checked if its all elements are in the current LinkedList or not.
	  *@return the truth value of if all elements in the given Collection are in the current LinkedList or not.
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

	/**Returns the truth value of LinkedList being empty.
	  *@return the truth value of LinkedList being empty.
	*/ 
	public boolean isEmpty(){
		if(contArr.length==0)
			return true;
		else
			return false;

	}

	/**Removes the given element e from the current LinkedList if its the head of the LinkedList.
	  *@param e the element which will be removed from the LinkedList.
	  *@throws RuntimeException
	*/
	public void remove(E e) throws RuntimeException{
		if(e.equals(getContArray()[0])){
			Object[] tempArr = new Object[contArr.length-1];
			for(int i=0,j=1;j<contArr.length;++j){
				tempArr[i]=contArr[j];
				++i;
			}
			contArr=tempArr;
		}
		else{
			throw new RuntimeException();
		}
	}

	/**Removes the elements from the current LinkedList which exists a given Collection and the head of the current LinkedList.
	  *@param c the Collection whose elements will be removed from the current LinkedList.
	*/
	public void removeAll(Collection<E> c){
		Iterator<E> it;
		for(it=iterator();it.hasNext();it.next()){
				if(c.contains(it.getElement())){
					remove(it.getElement());
				}
			
		}
		if(c.contains(it.getElement()))
			remove(it.getElement());
	}

	/**Removes the elements from the current LinkedList which does not exists a given Collection and is the head of the current LinkedList.
	  *@param c the Collection whose elements will be removed from the current LinkedList.
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

	/**Returns the size of the LinkedList.
	  *@return the size of the LinkedList.
	*/
	public int size(){
		return contArr.length;

	}
	public Object[] getContArray(){
		return contArr;
	}

	/**Retrieves but does not removes the head of this LinkedList.
	  *@return the head of the LinkedList.
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public E element(){
		return (E)contArr[0];
	}

	/**Adds the given element e to the current LinkedList.
	  *@param e the element which will be added to the LinkedList.
	*/
	public void offer(E e){
		add(e);
	}

	/**Retrieves and removes the head of this LinkedList.
	  *@return the head of the LinkedList.
	  *@throws RuntimeException
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public E poll() throws RuntimeException{
		if(size()==0)
			throw new RuntimeException();
		E temp=(E)contArr[0];
		remove((E)contArr[0]);
		return temp;
	}
}