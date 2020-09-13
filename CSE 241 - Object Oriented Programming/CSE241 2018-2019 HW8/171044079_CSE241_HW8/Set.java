import java.lang.*;
/**
  *Set interface represents the Set which extends from Collection interface in Java. Set
  *is extended from Collection interface. This interface is a generic interface.
 */
public interface Set<E> extends Collection<E>{
	/**
	  *Returns a Iterator<E> object that can be used in Set.
	  *@return the iterator corresponding to the Set.
	*/
	public Iterator<E> iterator();

	/**Adds the given element e to the current Set. Makes sure that the element is not in the Set already.
	  *@param e the element which will be added to the Set.
	*/
	public void add(E e);

	/**Adds the elements to the current Set from a given Collection. Makes sure that the element is not in the Set already.
	  *@param c the Collection whose elements will be added to the current Set.
	*/
	public void addAll(Collection<E> c);

	/**Clears the set
	*/
	public void clear();

	/**Returns the truth value of e existing in the Set or not.
	  *@param e the element which will be checked if it is in the Set or not.
	  *@return the truth value of if e exists in the Set or not
	*/ 
	public boolean contains(E e);

	/**Returns the truth value of all the elements in a given Collection is in the current Set or not.
	  *@param c the Collection which will be checked if its all elements are in the current Set or not.
	  *@return the truth value of if all elements in the given Collection are in the current Set or not.
	*/ 
	public boolean containsAll(Collection<E> c);

	/**Returns the truth value of Set being empty.
	  *@return the truth value of Set being empty.
	*/ 
	public boolean isEmpty();

	/**Removes the given element e from the current Set if it exists.
	  *@param e the element which will be removed from the Set.
	*/
	public void remove(E e);

	/**Removes the elements from the current Set which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Set.
	*/
	public void removeAll(Collection<E> c);

	/**Removes the elements from the current Set which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Set.
	*/
	public void retainAll(Collection<E> c);

	/**Returns the size of the Set.
	  *@return the size of the Set.
	*/
	public int size();
}