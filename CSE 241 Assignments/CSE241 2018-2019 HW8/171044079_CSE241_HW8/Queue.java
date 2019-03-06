import java.lang.*;
/**
  *Queue interface represents the Queue which extends from Collection interface in Java. Queue
  *is extended from Collection interface.This interface is a generic interface.
 */
public interface Queue<E> extends Collection<E>{
	/**
	  *Returns a Iterator<E> object that can be used in Queue.
	  *@return the iterator corresponding to the Queue.
	*/
	public Iterator<E> iterator();

	/**Adds the given element e to the current Queue.
	  *@param e the element which will be added to the Queue.
	*/
	public void add(E e);

	/**Adds the elements to the current Queue from a given Collection.
	  *@param c the Collection whose elements will be added to the current Queue.
	*/
	public void addAll(Collection<E> c);

	/**Clears the list
	*/
	public void clear();

	/**Returns the truth value of e existing in the Queue or not.
	  *@param e the element which will be checked if it is in the Queue or not.
	  *@return the truth value of if e exists in the Queue or not
	*/ 
	public boolean contains(E e);

	/**Returns the truth value of all the elements in a given Collection is in the current Queue or not.
	  *@param c the Collection which will be checked if its all elements are in the current Queue or not.
	  *@return the truth value of if all elements in the given Collection are in the current Queue or not.
	*/ 
	public boolean containsAll(Collection<E> c);

	/**Returns the truth value of Queue being empty.
	  *@return the truth value of Queue being empty.
	*/ 
	public boolean isEmpty();

	/**Removes the given element e from the current Queue if it exists.
	  *@param e the element which will be removed from the Queue.
	  *@throws RuntimeException
	*/
	public void remove(E e) throws RuntimeException;

	/**Removes the elements from the current Queue which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Queue.
	*/
	public void removeAll(Collection<E> c);

	/**Removes the elements from the current Set which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current Queue.
	*/
	public void retainAll(Collection<E> c);

	/**Returns the size of the Queue.
	  *@return the size of the Queue.
	*/
	public int size();

	/**Retrieves but does not removes the head of this Queue.
	  *@return the head of the Queue.
	*/
	public E element();

	/**Adds the given element e to the current Queue.
	  *@param e the element which will be added to the Queue.
	*/
	public void offer(E e);

	/**Retrieves and removes the head of this Queue.
	  *@return the head of the Queue.
	  *@throws RuntimeException
	*/
	public E poll() throws RuntimeException;
}