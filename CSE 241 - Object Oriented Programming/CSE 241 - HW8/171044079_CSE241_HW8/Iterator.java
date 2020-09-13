import java.lang.*;
/**
  *Iterator class represents the iterators which works in the Collections. Iterator
  *is a generic class.
 */
public class Iterator<E>{
	private int index;
	private E element;
	private Object[] container;
	/**
  		*Iterator constructor which takes an Object array.
  		*@param arr the array which the iterator is wanted to be used.
	 */
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public Iterator(Object[] arr){
		index=0;
		element=(E)arr[0];
		container=arr.clone();
	}
	/**
  		*This function checks if the element that iterator shows has a next element after it.
  		*@return the truth value of if a next value exists after the current element.
	 */
	public boolean hasNext(){
		if(index<container.length-1)
			return true;
		else
			return false;
	}
	/**
  		*This function returns the element after the current iterator shows and increments the iterator is there is a next element.
  		*@return the truth value of the next value.
	 */
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public E next(){
		if(hasNext()){
			element=(E)container[++index];
		}
		return element;
	} 
	/**
  		*This function removes the element which the current iterator shows.
	*/
	public void remove(){
		container[index]=null;
	}
	/**
  		*This function return the value of the element which the current iterator shows.
  		*@return the current element value.
	*/
	public E getElement(){
		return element;
	}
	/**
  		*This function return the position of the element which the current iterator shows.
  		*@return the current iterator position.
	*/
	public int getIndex(){
		return index;
	}
}