import java.lang.*;
import java.util.Arrays;
/**This class implements ArrayList functions so it implements List interface. ArrayList elements are always ordered.
  *This class is a generic class.
*/
public class ArrayList<E> implements List<E>{
	private Object[] contArr;

	/**
  		*ArrayList constructor which takes an E array.
  		*@param arr the array which the container will be for the ArrayList.
	 */
	public ArrayList(E[] arr){
		contArr=arr.clone();
		Arrays.sort(contArr);
	}

	/**
	  *Returns a Iterator<E> object that can be used in ArrayList.
	  *@return the iterator corresponding to the ArrayList.
	*/
	public Iterator<E> iterator(){
		Iterator<E> it = new Iterator<E>(contArr);
		return it;
	}

	/**Adds the given element e to the current ArrayList.
	  *@param e the element which will be added to the ArrayList.
	*/
	public void add(E e){
		Object[] tempArr=new Object[contArr.length+1];
		for(int i=0;i<contArr.length;++i){
			tempArr[i]=contArr[i];
		}
		tempArr[tempArr.length-1]=e;
		contArr=tempArr;
		Arrays.sort(contArr);
	}

	/**Adds the elements to the current ArrayList from a given Collection.
	  *@param c the Collection whose elements will be added to the current ArrayList.
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

	/**Returns the truth value of e existing in the ArrayList or not.
	  *@param e the element which will be checked if it is in the ArrayList or not.
	  *@return the truth value of if e exists in the ArrayList or not
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

	/**Returns the truth value of all the elements in a given Collection is in the current ArrayList or not.
	  *@param c the Collection which will be checked if its all elements are in the current ArrayList or not.
	  *@return the truth value of if all elements in the given Collection are in the current ArrayList or not.
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

	/**Returns the truth value of ArrayList being empty.
	  *@return the truth value of ArrayList being empty.
	*/ 
	public boolean isEmpty(){
		if(contArr.length==0)
			return true;
		else
			return false;

	}

	/**Removes the given element e from the current ArrayList if it exists.
	  *@param e the element which will be removed from the ArrayList.
	*/
	//To disable the unchecked warning
	@SuppressWarnings("unchecked")
	public void remove(E e){
		
		if(contains(e)){
			Object[] tempArr=new Object[contArr.length-1];
			int index=0;
			for(int i=0;i<contArr.length;++i){
				if(e.equals(contArr[i])){
					index=i;
				}	
			}
			for(int j=0;j<contArr.length-1;++j){
				if(j<index){
					tempArr[j]=contArr[j];
				}
				else{
					tempArr[j]=contArr[j+1];
				}
			}
			contArr=tempArr;
		}
	}

	/**Removes the elements from the current ArrayList which exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current ArrayList.
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

	/**Removes the elements from the current ArrayList which does not exists a given Collection.
	  *@param c the Collection whose elements will be removed from the current ArrayList.
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

	/**Returns the size of the ArrayList.
	  *@return the size of the ArrayList.
	*/
	public int size(){
		return contArr.length;

	}
	public Object[] getContArray(){
		return contArr;
	}
}