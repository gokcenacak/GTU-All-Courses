package Q4;

/**
 * This class represents a DatabaseTableProxy which enables synchronization
 * on the DatabaseTable between reader and writer threads
 */
public class DatabaseTableProxy implements ITable {
    private volatile DatabaseTable databaseTable;
    private int writers = 0;
    private int readers = 0;
    private int writersWaiting = 0;

    /**
     * Constructor
     * @param databaseTable DatabaseTable to use the proxy on
     */
    public DatabaseTableProxy(DatabaseTable databaseTable){
        this.databaseTable = databaseTable;
    }

    /**
     * Gets the element at the given row and column
     * @param row Row
     * @param column Column
     * @return Element at the given row and column
     */
    @Override
    public synchronized Object getElementAt(int row, int column) {
        Object res;

        while(writers > 0 || writersWaiting > 0){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
        readers++;
        res =  databaseTable.getElementAt(row,column);
        readers--;
        notifyAll();

        return res;
    }
    /**
     * Sets the given object to the position with the given row and column
     * @param row Row
     * @param column Column
     */
    @Override
    public synchronized void setElementAt(int row, int column, Object o) {
        writersWaiting++;
        while(readers > 0 || writers > 0){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
        writersWaiting--;

        writers++;
        databaseTable.setElementAt(row,column,o);
        writers--;
        notifyAll();
    }
    /**
     * Get row count of the table
     * @return Row count of the table
     */
    @Override
    public int getNumberOfRows() {
        return databaseTable.getNumberOfRows();
    }
    /**
     * Get column count of the table
     * @return Column count of the table
     */
    @Override
    public int getNumberOfColumns() {
        return databaseTable.getNumberOfColumns();
    }

    /**
     * Returns the string representation of the DatabaseTableProxy
     * @return String representation of the DatabaseTableProxy
     */
    @Override
    public String toString() {
        return databaseTable.toString();
    }
}
