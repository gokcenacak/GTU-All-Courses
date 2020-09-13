/** The LinkedList class represents the data structure Linked List which gets Variable objects only*/
public class LinkedList {
    private class Node<Variable>{
        private Variable data;
        private Node<Variable> next;

        private Node(Variable newdata){
            data = newdata;
            next = null;
        }

        public Variable getData() {
            return data;
        }

        public void setData(Variable data) {
            this.data = data;
        }

        public Node<Variable> getNext() {
            return next;
        }

        public void setNext(Node<Variable> next) {
            this.next = next;
        }
    }
    private Node<Variable> head = null;

    public Node<Variable> getHead() {
        return head;
    }

    /**Adds a given variable to the list, if list is empty it puts it to the head, if not it finds the last
     * element and adds after it.
     * @param data the variable which will be added to the list
     * */
    public void add(Variable data){
        Node<Variable> node = new Node<>(data);

        if(head == null){
            head = node;
        }
        else {
            Node<Variable> tracker = head;
            while(tracker.getNext() != null){
                tracker = tracker.getNext();
            }
            tracker.setNext(node);
        }

    }
    /**Checks a given string is equal to the strings of the variables in the list. Technically, checks if a variable
     * exist with its string data member.
     * @param x the string which will be compared with the variables' strings in the list
     * @return true if the string matches with any of the variables in the list, false otherwise.
     * */
    public boolean exists(String x) {
        Node<Variable> tracker = head;
        while (tracker.getNext() != null) {
            if(x.equals(tracker.getData().getVariableName()))
                return true;
            tracker = tracker.getNext();
        }
        if(x.equals(tracker.getData().getVariableName()))
            return true;
        return false;
    }
    /**Finds the variable which has the given string in it and returns its value
     * @param x the string which will be compared to find the variable corresponding to it.
     * @return the numeric value of the requested variable.
     * */
    public double getValueOfVar(String x){
        Node<Variable> tracker = head;
        while (tracker.getNext() != null) {
            if(x.equals(tracker.getData().getVariableName())){
                return tracker.getData().getVariableValue();
            }
            tracker = tracker.getNext();

        }
        if(x.equals(tracker.getData().getVariableName())){
            return tracker.getData().getVariableValue();
        }
        return 0.0;
    }
    /**Returns the proper string representation of the linked list
     * @return string representation of the linked list
     * */
    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        Node<Variable> node = head;
        string.append("\n");

        while(node != null){
            string.append(node.getData());
            string.append("\n");
            node = node.getNext();
        }
        return string.toString();
    }
}
