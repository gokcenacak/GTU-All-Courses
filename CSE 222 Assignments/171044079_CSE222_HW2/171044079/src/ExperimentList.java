import java.lang.*;
import java.util.Iterator;

/**This class implements the structure called ExperimentList which
 * keeps track of some machine learning experiments and their results*/
public class ExperimentList implements Iterable {
    private ExperimentListNode head=null;
    /**Constructor*/
    public ExperimentList(){
        //Intentionally empty.
    }
    private ExperimentListNode getHead() {
        return head;
    }

    private void setHead(ExperimentListNode head) {
        this.head = head;
    }
    /**ExperimentListIterator is an inner class of ExperimentList to implement an iterator for the data structure*/
    public class ExperimentListIterator implements Iterator<ExperimentListNode> {
        private ExperimentListNode current;
        private ExperimentListNode getCurrent() {
            return current;
        }

        private void setCurrent(ExperimentListNode current) {
            this.current = current;
        }
        /**Constructor for ExperimentListIterator*/
        public ExperimentListIterator(){
            current=head;
        }
        /**Overridden hasNext function from Iterator interface
         * @return Returns true if the element shown by the iterator has a next element.
         * */
        @Override
        public boolean hasNext() {
            return current.getNextExperiment() != null;
        }
        /**Overridden next function from Iterator interface
         * @return Returns the next experiment node if exists one. Else returns null.
         * */
        @Override
        public ExperimentListNode next() {
            if(hasNext()){
                current=current.getNextExperiment();
                return current;
            }
            else
                return null;
        }
        /**Overridden remove function from Iterator interface
         * Removes the current element shown by the iterator.
         * */
        @Override
        public void remove() {
            ExperimentListNode previous=null;

            ExperimentListNode temp = head;
            while(temp != null && temp != current){
                previous = temp;
                temp = temp.getNextExperiment();
            }
            if(previous == null){
                if(hasNextDay()){
                    current.getNextExperiment().setNextDay(current.getNextDay());
                }
                head = current.getNextExperiment();
                current=current.getNextExperiment();

            }
            else {
                ExperimentListNode previousDay=null;
                temp=head;
                if(hasNextDay()){

                    while(temp.getNextDay() != current.getNextDay()){
                        previousDay = temp;
                        temp = temp.getNextDay();
                    }
                    if(previousDay==null) {
                        previousDay=head;
                        previousDay.setNextDay(current.getNextExperiment());
                        current.getNextExperiment().setNextDay(current.getNextDay());
                    }
                    else{
                        if(current.getNextExperiment().getExperiment().getDay() == current.getExperiment().getDay()) {

                            previousDay.setNextDay(current.getNextExperiment());
                            if(current.getNextDay() != null)
                                current.getNextExperiment().setNextDay(current.getNextDay());
                        }
                        else{
                            previousDay.setNextDay(current.getNextDay());
                        }
                    }
                }
                previous.setNextExperiment(current.getNextExperiment());
                setCurrent(current.getNextExperiment());


            }
        }
        /**hasNextDay function checks if there is a next day or not.
         * @return Returns true if the element shown by the iterator has a next day.
         * */
        public boolean hasNextDay(){
            return current.getNextDay() != null;
        }
        /**nextDay function returns the element at the beginning the next day.
         * @return Returns the ExperimentListNode which shows the next day's first day if there is any existing.
         * */
        public ExperimentListNode nextDay(){
            if(hasNextDay()) {
                setCurrent(current.getNextDay());
                return current;
            }
            else
                return null;
        }

    }
    /**This function adds an Experiment element to the end of the day
     * @param e The experiment which will be added to the list
     * */
    void addExp(Experiment e){
        boolean flag=false;
        ExperimentListIterator listIterator = iterator();
        //Checking if the day exists in the list.
        if(head!=null) {
            while (listIterator.hasNextDay()) {
                if (e.getDay() == listIterator.getCurrent().getExperiment().getDay()) {
                    flag = true;
                }
                listIterator.nextDay();
            }
            if(!listIterator.hasNextDay()){
                if(e.getDay() == listIterator.getCurrent().getExperiment().getDay())
                    flag = true;
            }
        }
        ExperimentListNode newNode = new ExperimentListNode(e);
        //Checking if list is empty or not.
        if(head==null){
            setHead(newNode);
        }
        //Adding the experiment for the case of having the day in the list.
        else if(flag) {
            for (listIterator = iterator();
                 listIterator.getCurrent().getNextExperiment() != null &&
                         (listIterator.getCurrent().getNextExperiment().getExperiment().getDay() != e.getDay() + 1); ) {

                listIterator.setCurrent(listIterator.next());
            }

            newNode.setNextDay(null);

            if (!listIterator.hasNext()) {
                listIterator.getCurrent().setNextExperiment(newNode);
                newNode.setNextExperiment(null);
            } else {
                newNode.setNextExperiment(listIterator.getCurrent().getNextExperiment());
                listIterator.getCurrent().setNextExperiment(newNode);
            }
        }
        //Adding the element if the day does not exist in the list.
        else{
            listIterator=iterator();
            while(listIterator.getCurrent().getNextDay() != null && listIterator.getCurrent().getNextDay().getExperiment().getDay()<e.getDay()){
                listIterator.nextDay();
            }
            newNode.setNextDay(listIterator.getCurrent().getNextDay());
            listIterator.getCurrent().setNextDay(newNode);
            int temp = listIterator.getCurrent().getExperiment().getDay();
            while(listIterator.getCurrent().getNextExperiment() != null && listIterator.getCurrent().getNextExperiment().getExperiment().getDay() == temp){
                listIterator.next();
            }
            newNode.setNextExperiment(listIterator.getCurrent().getNextExperiment());
            listIterator.getCurrent().setNextExperiment(newNode);

        }

    }

    /**This function gets the experiment with the given day and index.
     * @param day The day to get the experiment from.
     * @param index The index of the day to get the experiment from.
     * @return The requested experiment with the given day and index.
     */
    Experiment getExp(int day , int index){
        ExperimentListIterator listIterator;
        for(listIterator = iterator() ; listIterator.hasNextDay() && (listIterator.getCurrent().getExperiment().getDay() != day) ; ){
            listIterator.nextDay();
        }
        if((listIterator.getCurrent().getExperiment().getDay() != day))
            throw new ArithmeticException();
        for(int i = 1 ; i<index && listIterator.hasNext() && (listIterator.getCurrent().getExperiment().getDay() == day ); ++i){
            listIterator.setCurrent(listIterator.next());
        }
        if((listIterator.getCurrent().getExperiment().getDay() != day))
            throw new IndexOutOfBoundsException();
        return listIterator.getCurrent().getExperiment();
    }

    /**This function sets the given experiment to the given day and index.
     * @param day The day to set the experiment to.
     * @param index The index of the day to set the experiment to.
     * @param e The experiment to set.
     * @throws IndexOutOfBoundsException
     */
    public void setExp(int day , int index , Experiment e){
        if(head == null)
            throw new NullPointerException();
        if(day==e.getDay()) {
            ExperimentListIterator listIterator;
            for (listIterator = iterator(); listIterator.hasNextDay() && (listIterator.getCurrent().getExperiment().getDay() != day); ) {
                listIterator.nextDay();
            }
            for (int i = 1; i < index && listIterator.hasNext() && (listIterator.getCurrent().getExperiment().getDay() == e.getDay()); ++i) {
                listIterator.setCurrent(listIterator.next());
            }
            if ((listIterator.getCurrent().getExperiment().getDay() == e.getDay()))
                listIterator.getCurrent().setExperiment(e);
            else
                throw new IndexOutOfBoundsException();
        }
        else{
            throw new ArithmeticException();
        }
    }

    /**This function removes the experiment from the given day and index.
     * @param day The day to remove the experiment
     * @param index The index of the day to remove the experiment.
     */
    public void removeExp(int day , int index){
        ExperimentListIterator listIterator;
        if(head == null)
            throw new NullPointerException();
        if(day == head.getExperiment().getDay() && index == 1){
            listIterator=iterator();
            listIterator.remove();
        }
        else {
            for (listIterator = iterator(); listIterator.hasNextDay() && (listIterator.getCurrent().getExperiment().getDay() != day); ) {
                listIterator.nextDay();
            }

            for (int i = 1; i < index; ++i) {
                if (!listIterator.hasNext()) {
                    throw new IndexOutOfBoundsException();
                }
                else {
                        listIterator.setCurrent(listIterator.next());
                }
            }
            if ((listIterator.getCurrent().getExperiment().getDay() != day)) {
                throw new IndexOutOfBoundsException();

            }
            if ((day == listIterator.getCurrent().getExperiment().getDay()))
                listIterator.remove();
            else {
                throw new ArithmeticException();
            }
        }
    }

    /**This function lists all the completed experiments in a given day.
     * @param day The day which will be used to list the completed experiments in it.
     */
    public void listExp(int day){
        if(head == null)
            throw new NullPointerException();
        ExperimentListIterator listIterator;
        for(listIterator = iterator() ; (listIterator.getCurrent().getExperiment().getDay() != day) && (listIterator.hasNextDay()) ; ){
            listIterator.nextDay();
        }

        while(listIterator.getCurrent().getExperiment().getDay()==day && listIterator.hasNext()){
            if(listIterator.getCurrent().getExperiment().isCompleted()){
                System.out.println(listIterator.getCurrent().getExperiment());
            }
            listIterator.setCurrent(listIterator.next());
        }
        if((day > listIterator.getCurrent().getExperiment().getDay()))
            throw new ArithmeticException();

        if(listIterator.getCurrent().getExperiment().isCompleted() && listIterator.getCurrent().getExperiment().getDay()==day){
            System.out.println(listIterator.getCurrent().getExperiment());
        }
    }

    /**This function removes all the experiments in a day
     * @param day The day to remove all the experiments from.
     */
    public void removeDay(int day){
        if(head == null)
            throw new NullPointerException();
        ExperimentListIterator listIterator;
        for(listIterator = iterator() ; listIterator.hasNextDay() && (listIterator.getCurrent().getExperiment().getDay() != day) ; ){
            listIterator.nextDay();
        }
        if((day != listIterator.getCurrent().getExperiment().getDay()))
            throw new ArithmeticException();
        while(listIterator.getCurrent().getExperiment().getDay()==day && listIterator.hasNext()){
            listIterator.remove();
        }

        if(!listIterator.hasNext())
            listIterator.remove();

    }

    /**This function sorts the experiments in the given day according to the accuracy.
     * This function changes the list!
     * @param day The day to sort the experiments in it.
     */
    public void orderDay(int day){
        //Checking if list is empty.
        if(head == null)
            throw new NullPointerException();
        Experiment temp;
        ExperimentListIterator li1;
        ExperimentListIterator li2;
        //Bringing 2 iterators one at the beginning of the required day, and the other one to the next experiment of
        //the first iterator.
        for(li1 = iterator() ; li1.hasNextDay() && (li1.getCurrent().getExperiment().getDay() != day) ; ){
            li1.nextDay();
        }
        for(li2 = iterator() ; li2.hasNextDay() && (li2.getCurrent().getExperiment().getDay() != day) ; ){
            li2.nextDay();
        }
        li2.next();
        //Sorting
        while(li1.hasNext()&& (li1.getCurrent().getNextExperiment().getExperiment().getDay() == day)){
            while(li2.hasNext() && (li2.getCurrent().getNextExperiment().getExperiment().getDay() == day)){
                if(li1.getCurrent().getExperiment().getAccuracy()>li2.getCurrent().getExperiment().getAccuracy()){
                    temp = li1.getCurrent().getExperiment();
                    li1.getCurrent().setExperiment(li2.getCurrent().getExperiment());
                    li2.getCurrent().setExperiment(temp);
                }
                li2.next();
            }
            li2.setCurrent(li1.next());
        }
        //Sorting for the last element: moving one of the iterators to the beginning of the day to compare the last
        //element with the rest of them.
        for(li2 = iterator() ; li2.hasNextDay() && (li2.getCurrent().getExperiment().getDay() != day) ; ){
            li2.nextDay();
        }
        while(li2.hasNext() && (li2.getCurrent().getNextExperiment().getExperiment().getDay() == day)) {
            if (li1.getCurrent().getExperiment().getAccuracy() < li2.getCurrent().getExperiment().getAccuracy()) {
                temp = li1.getCurrent().getExperiment();
                li1.getCurrent().setExperiment(li2.getCurrent().getExperiment());
                li2.getCurrent().setExperiment(temp);
            }
            li2.next();
        }

        //Day check
        if(day > li1.getCurrent().getExperiment().getDay() || day > li2.getCurrent().getExperiment().getDay() ){
            throw new IndexOutOfBoundsException();
        }



    }

    /**This function sorts all the experiments according the accuracy, does not change the list and returns the head of the list.
     * @return The head of the list.
     */
    public ExperimentListNode orderExperiments(){
        ExperimentListIterator listIterator;
        ExperimentListIterator li1;
        ExperimentListIterator li2;
        Experiment newExp;
        Experiment e;
        ExperimentList temp = new ExperimentList();
        listIterator = iterator();
        while(listIterator.hasNext()){
            e = new Experiment(listIterator.getCurrent().getExperiment());
            e.setDay(0);
            temp.addExp(e);
            listIterator.next();
        }
        e = new Experiment(listIterator.getCurrent().getExperiment());
        e.setDay(0);
        temp.addExp(e);

        li1 = temp.iterator();
        li2 = temp.iterator();
        li2.next();
        //Sorting
        while(li1.hasNext()){
            while(li2.hasNext()){
                if(li1.getCurrent().getExperiment().getAccuracy()>li2.getCurrent().getExperiment().getAccuracy()){
                    newExp = li1.getCurrent().getExperiment();
                    li1.getCurrent().setExperiment(li2.getCurrent().getExperiment());
                    li2.getCurrent().setExperiment(newExp);
                }
                li2.next();
            }
            li2.setCurrent(li1.next());
        }
        //Sorting for the last element:
        //Checks all the elements with the last element of the list if the last element is smaller or not.
        li2 = temp.iterator();
        while(li2.hasNext()) {
            if (li1.getCurrent().getExperiment().getAccuracy() < li2.getCurrent().getExperiment().getAccuracy()) {
                newExp = li1.getCurrent().getExperiment();
                li1.getCurrent().setExperiment(li2.getCurrent().getExperiment());
                li2.getCurrent().setExperiment(newExp);
            }
            li2.next();
        }
        return temp.getHead();
    }
    /**Creates a ExperimentListIterator*/
    @Override
    public ExperimentListIterator iterator() {
        return new ExperimentListIterator();
    }
    /**Prints a ExperimentList*/
    @Override
    public String toString() {
        ExperimentListIterator listIterator;
        StringBuilder string = new StringBuilder();
        for (listIterator = this.iterator(); listIterator.hasNext(); listIterator.next()) {
            string.append(listIterator.getCurrent().getExperiment());
            string.append("\n\n");
        }
        string.append(listIterator.getCurrent().getExperiment());
        string.append("\n\n");
        return string.toString();
    }
}
