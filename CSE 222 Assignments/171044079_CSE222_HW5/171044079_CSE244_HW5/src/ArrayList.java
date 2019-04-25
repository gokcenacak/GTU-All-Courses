/**ArrayList class is a generic class which implements a resizeable array. It implements add , get , set , remove ,
 * reallocate , size and isEmpty methods. Each ArrayList instance has a capacity. The capacity is the size of the
 * array used to store the elements. As elements are added to the ArrayList, its capacity grows automatically.*/
public class ArrayList<E> {
    private int currentSize = 0;
    private static final int CAPACITY = 10;
    private int currentCapacity;
    private E[] values;
    /**Constructs an empty list with an initial capacity of ten.*/
    @SuppressWarnings("unchecked")
    public ArrayList(){
        currentCapacity = CAPACITY;
        values = (E[])new Object[currentCapacity];
    }

    /**Adds the specified element to the end of the arraylist.
     * @param entry element to be added to this arraylist.
     * */
    public void add(E entry){
        if(currentSize == currentCapacity){
            reallocate();
        }
        values[currentSize] = entry;
        currentSize++;
    }
    /**Returns the element at the specified position in the arraylist.
     * @param index index of the element to return
     * @return the element at the specified position in this arraylist
     * */
    public E get(int index){
        if(index < 0 || currentSize <= index){
            throw new ArrayIndexOutOfBoundsException(index);
        }
        return values[index];
    }

    /**Replaces the element at the specified position in this arraylist with the specified
     * element.
     * @param entry element to be stored at the specified position
     * @param index index of the element to replace
     * @return the element previously at the specified position
     */
    public E set(E entry , int index){
        if(index < 0 || currentSize <= index){
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E returnValue = values[index];
        values[index] = entry;
        return returnValue;
    }

    /**Removes the element at the specified position in the arraylist. Shifts any subsequent
     * elements to the left.
     * @param index the index of the element to be removed
     * @return the element that was removed from the arraylist
     */
    public E remove(int index){
        if(index < 0 || currentSize <= index){
            throw new ArrayIndexOutOfBoundsException(index);
        }
        E returnValue = values[index];
        for(int i = index + 1 ; i < currentSize ; i++){
            values[i - 1] = values[i];
        }
        currentSize--;
        return returnValue;
    }

    @SuppressWarnings("unchecked")
    private void reallocate(){
        currentCapacity *= 2;
        E[] enlargedArr = (E[])new Object[currentCapacity];
        for(int i = 0 ; i < values.length ; i++){
            enlargedArr[i]=values[i];
        }
        values = enlargedArr;
    }

    /**Returns the number of elements in this arraylist.
     * @return the number of elements in this list
     */
    public int size(){
        return currentSize;
    }
    /**Returns true if this arraylist contains no elements
     * @return true if this arraylist contains no elements
     * */
    public boolean isEmpty(){
        if(size()==0)
            return true;
        else
            return false;
    }
}
