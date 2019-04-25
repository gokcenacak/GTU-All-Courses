import java.util.Comparator;

/**PriorityQueue class is a class that represents PriorityQueues which use a max binary
 * heap implementation. A PriorityQueue has a comparator to compare values
 * and a arraylist to hold the values.
 */
public class PriorityQueue {
    private ArrayList<Color> values;
    private Comparator<Color> comp;

    /**Constructs a PriorityQueue with a given comparator
     *
     * @param comp comparator to be used in comparison of the elements in the PriorityQueue.
     */
    public PriorityQueue(Comparator<Color> comp){
        this.comp = comp;
        values = new ArrayList<>();
    }

    /**Adds a given color to the PriorityQueue does the necessary comparisons and rearranges the whole heap
     * according to the comparisons.
     * @param c color to be added to the priority queue
     */
    public synchronized void add(Color c){
        values.add(c);
        int childPos = values.size()-1;
        int parentPos = getParentIndex(childPos);

        while(parentPos>=0 && compare(values.get(parentPos) , values.get(childPos)) < 0 ){
            swap(childPos,parentPos);
            childPos = parentPos;
            parentPos = getParentIndex(childPos);
        }
        notifyAll();
    }
    private void swap(int i , int j){
        Color temp = values.get(i);
        values.set(values.get(j),i);
        values.set(temp,j);
    }
    public int compare(Color c1 , Color c2){
        return comp.compare(c1,c2);
    }
    /**Removes biggest color value from the PriorityQueue does the necessary comparisons and rearranges the whole heap
     * according to the comparisons.
     * @return the color removed from the priority queue
     */
    public synchronized Color remove(){
        if(isEmpty()) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        Color removed = values.get(0);
        values.set(values.get(values.size()-1),0);
        values.remove(values.size()-1);
        int i = 0;
        int count = 0 ;
        while(getLeftChildIndex(i)<values.size() || getRightChildIndex(i)<values.size()){
            Color c1 = new Color(0,0,0);
            Color c2 = new Color(0,0,0);
            count ++;
            if(getLeftChildIndex(i)<values.size())
                c1 = values.get(getLeftChildIndex(i));
            if(getRightChildIndex(i)<values.size())
                c2 = values.get(getRightChildIndex(i));
            if(comp.compare(values.get(i),c1) < 0 || comp.compare(values.get(i),c2) < 0) {
                if (comp.compare(c1, c2) > 0) {
                    swap(i, getLeftChildIndex(i));
                    i = getLeftChildIndex(i);
                }
                else if (comp.compare(c1, c2) < 0) {
                    swap(i, getRightChildIndex(i));
                    i = getRightChildIndex(i);
                }
                else {
                    swap(i, getLeftChildIndex(i));
                    i = getLeftChildIndex(i);
                }
            }
            else {
                break;
            }
        }
        return removed;

    }
    /**Returns the biggest color value in the priority queue
     * @return the biggest color value
     * */
    public Color peek(){
        return values.get(0);
    }
    private int getLeftChildIndex(int parentIndex){
        return parentIndex*2+1;
    }
    private int getRightChildIndex(int parentIndex){
        return parentIndex*2+2;
    }
    private int getParentIndex(int childIndex){
        if(childIndex%2 == 0)
            return (childIndex-2)/2;
        else
            return (childIndex-1)/2;
    }
    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("[");
        for(int i = 0 ; i < values.size() ; i++){
            string.append(values.get(i));
            string.append(" ");
        }
        string.append("]");
        return string.toString();
    }
    public boolean isEmpty(){
        return values.isEmpty();
    }
}
