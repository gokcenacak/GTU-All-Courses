package Q3;

import java.util.ArrayList;

/**
 * This class represents a database table.
 * @author Gokce Nur Erer
 */
public class DatabaseTable {
    /**
     * List of the columns of the table
     */
    ArrayList<String> cols;
    /**
     * Name of the table
     */
    String name;

    /**
     * Constructor of DatabaseTable
     * @param name Table name
     */
    public DatabaseTable(String name){
        this.name = name;
        cols = new ArrayList<>();
    }

    /**
     * Adds a column to the table
     * @param name Column name
     */
    public void addColumn(String name){
        cols.add(name);
    }

    /**
     * Checks if given column exists
     * @param name Column name
     * @return True if the given column exists, otherwise false
     */
    public boolean hasColumn(String name){
        return cols.contains(name);
    }

}
