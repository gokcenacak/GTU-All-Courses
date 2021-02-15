package Q4;

import java.util.Arrays;

/**
 * This class represents a database table
 * @author Gökçe Nur Erer
 */
public class DatabaseTable implements ITable{
    /**
     * Table
     */
    private Object [][] table;

    /**
     * Constructor
     * @param rowCount Row count of the table
     * @param columnCount Column count of the table
     */
    public DatabaseTable(int rowCount, int columnCount){
        table = new Object[rowCount][columnCount];
    }

    /**
     * Gets the element at the given row and column
     * @param row Row
     * @param column Column
     * @return Element at the given row and column
     */
    @Override
    public Object getElementAt(int row, int column) {
        return table[row][column];
    }
    /**
     * Sets the given object to the position with the given row and column
     * @param row Row
     * @param column Column
     */
    @Override
    public void setElementAt(int row, int column, Object o) {
        table[row][column] = o;
    }

    /**
     * Get row count of the table
     * @return Row count of the table
     */
    @Override
    public int getNumberOfRows() {
        return table.length;
    }
    /**
     * Get column count of the table
     * @return Column count of the table
     */
    @Override
    public int getNumberOfColumns() {
        return table[0].length;
    }
    /**
     * Constructs a string representation of the table
     * @return String representation of the table
     */
    @Override
    public String toString() {
        return "DatabaseTable{" +
                "table=" + Arrays.deepToString(table) +
                '}';
    }
}
