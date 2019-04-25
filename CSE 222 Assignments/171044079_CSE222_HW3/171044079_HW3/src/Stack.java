/**The Stack class represents the data structure stack.*/
public class Stack<E> {
    private Node<E> top = null;
    private class Node<E>{
        E data;
        private Node<E> next;

        private Node(E newdata){
            data = newdata;
            next = null;
        }

        public E getData() {
            return data;
        }

        public void setData(E data) {
            this.data = data;
        }

        public Node<E> getNext() {
            return next;
        }

        public void setNext(Node<E> next) {
            this.next = next;
        }
    }
    /**Pushes the given entry to the stack
     * @return The element that is pushed to the stack.
     * @param entry The element that will be pushed to the stack.
     * */
    public E push(E entry){
        Node<E> newNode = new Node<>(entry);
        newNode.setNext(top);
        top = newNode;

        return entry;
    }
    /**Pops the top of the stack.
     * @return The element that is popped from the stack.
     * */
    public E pop(){
        E element = top.getData();
        top = top.getNext();
        return element;
    }
    /**Returns the data at top of the stack without removing it.
     * @return The element that is at the top of the stack.
     * */
    public E peek(){
        return top.getData();
    }
    /**Checks if the stack is empty or not.
     * @return true if the stack is empty, false otherwise.
     * */
    public boolean empty(){
        if(top == null)
            return true;
        else
            return false;
    }
}
