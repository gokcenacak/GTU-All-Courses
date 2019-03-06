import java.lang.*;
/**
  *Collection interface represents the Collections in Java. Collection
  *is a generic interface.
 */
public interface Collection<E>{
	/**Returns a Iterator<E> object that can be used in other Collection classes.
	  *@return the iterator corresponding to the Collection type.
	*/
	public Iterator<E> iterator();

	/**Adds the given element e to the current Collection.
	  *@param e the element which will be added to the Collection.
	*/
	public void add(E e);

	/**Adds the elements to the current Collection from a given Collection.
	  *@param c the Collection whose elements will be added to the current Collection.
	*/
	public void addAll(Collection<E> c);

	/**Clears the collection
	*/
	public void clear();

	/**Returns the truth value of e existing in the Collection or not.
	  *@param e the element which will be checked if it is in the Collection or not.
	  *@return the truth value of if e exists in the collection or not
	*/ 
	public boolean contains(E e);

	/**Returns the truth value of all the elements in a given Collection is in the current Collection or not.
	  *@param c the Collection which will be checked if its all elements are in the current Collection or not.
	  *@return the truth value of if all elements in the given Collection are in the current Collection or not.
	*/ 
	public boolean containsAll(Collection<E> c);

	/**Returns the truth value of Collection being empty.
	  *@return the truth value of Collection being empty.
	*/ 
	public boolean isEmpty();

	/**Removes the given element e from the current Collection.
	  *@param e the element which will be removed from the Collection.
	*/
	public void remove(E e);

	/**Removes the elements from the current Collection which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Collection.
	*/
	public void removeAll(Collection<E> c);

	/**Removes the elements from the current Collection which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Collection.
	*/
	public void retainAll(Collection<E> c);
	
	/**Returns the size of the Collection
	  *@return the size of the Collection
	*/
	public int size();
}