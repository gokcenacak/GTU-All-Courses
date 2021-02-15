package Q3;

import java.util.ArrayList;

/**
 * This class represents a dummy database
 * @author Gokce Nur Erer
 */
public class Database {
    /**
     * Table names in the database
     */
    ArrayList<DatabaseTable> tables;
    /**
     * Name of the database
     */
    String name;

    /**
     * Constructor for Database
     * @param name Name for the database to create
     */
    public Database(String name){
        this.name = name;
        tables = new ArrayList<>();
    }

    /**
     * Adds a new table to the database
     * @param name Name of the table to be added
     */
    public void addTable(String name){
        tables.add(new DatabaseTable(name));

    }

    /**
     * Adds a new column to an existing table
     * @param name Table name
     * @param columnName Column name
     */
    public void addColumnToTable(String name, String columnName){
        for(DatabaseTable table : tables){
            if(table.name.equals(name)){
                table.addColumn(columnName);
            }
        }
    }

    /**
     * Checks if the given table exists in the database
     * @param name Table name
     * @return True if table exists, false if not
     */
    public boolean hasTable(String name){
        for(DatabaseTable table : tables){
            if(table.name.equals(name)){
                return true;
            }
        }
        return false;
    }

    /**
     * Gets the requested table of the database
     * @param name Table name
     * @return Requested table if it exists, null if not
     */
    public DatabaseTable getTable(String name){
        if(hasTable(name)){
            for(DatabaseTable table : tables){
                if(table.name.equals(name)){
                    return table;
                }
            }
        }
        return null;
    }
}
