import java.lang.*;
/**
  *List interface represents the List which extends from Collection interface in Java. List
  *is extended from Collection interface. List elements are always ordered.This interface is a generic interface.
 */
public interface List<E> extends Collection<E>{
	/**
	  *Returns a Iterator<E> object that can be used in List.
	  *@return the iterator corresponding to the List.
	*/
	public Iterator<E> iterator();

	/**Adds the given element e to the current List.
	  *@param e the element which will be added to the List.
	*/
	public void add(E e);

	/**Adds the elements to the current List from a given Collection.
	  *@param c the Collection whose elements will be added to the current List.
	*/
	public void addAll(Collection<E> c);

	/**Clears the list
	*/
	public void clear();

	/**Returns the truth value of e existing in the List or not.
	  *@param e the element which will be checked if it is in the List or not.
	  *@return the truth value of if e exists in the List or not
	*/ 
	public boolean contains(E e);

	/**Returns the truth value of all the elements in a given Collection is in the current List or not.
	  *@param c the Collection which will be checked if its all elements are in the current List or not.
	  *@return the truth value of if all elements in the given Collection are in the current List or not.
	*/ 
	public boolean containsAll(Collection<E> c);

	/**Returns the truth value of List being empty.
	  *@return the truth value of List being empty.
	*/ 
	public boolean isEmpty();

	/**Removes the given element e from the current List if it exists.
	  *@param e the element which will be removed from the List.
	*/
	public void remove(E e);

	/**Removes the elements from the current List which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current List.
	*/
	public void removeAll(Collection<E> c);

	/**Removes the elements from the current List which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current List.
	*/
	public void retainAll(Collection<E> c);

	/**Returns the size of the List.
	  *@return the size of the List.
	*/
	public int size();
	//public void sort();
}