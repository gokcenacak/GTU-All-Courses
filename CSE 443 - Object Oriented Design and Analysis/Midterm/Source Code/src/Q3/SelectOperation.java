package Q3;
/**
 * This class represents the Select operation in the database engine
 * @author Gokce Nur Erer
 */
public class SelectOperation implements IDatabaseOperation{
    /**
     * Table name which the operation will be done
     */
    private String tableName;
    /**
     * Column of the table which the operation will be done
     */
    private String col;
    /**
     * Condition of the operation
     */
    private String condition;
    /**
     * Getter for the table name of the operation
     * @return Table name of the operation
     */
    public String getTableName() {
        return tableName;
    }
    /**
     * Getter for the column name of the operation
     * @return Column name of the operation
     */
    public String getCol() {
        return col;
    }
    /**
     * Getter for the condition of the operation
     * @return Condition of the operation
     */
    public String getCondition() {
        return condition;
    }
    /**
     * Execution of the alter operation
     * @param database Database which the operation will be done on
     * @return False if operation fails (table doesn't exist or column doesn't exist), otherwise true
     */
    @Override
    public boolean execute(Database database) {

        if (!database.hasTable(tableName)) {
            return false;
        }
        else if(!database.getTable(tableName).hasColumn(col)){
            return false;
        }
        System.out.println("Selecting the col " + col + " from table " + tableName + " in database " + database.name);
        return true;
    }
    /**
     * Setting parameters for the operation
     * @param tableName Table name of the operation
     * @param col Column name of the operation
     * @param condition Condition of the operation
     */
    @Override
    public void setParameters(String tableName, String col, String condition) {
        this.tableName = tableName;
        this.col = col;
        this.condition = condition;
    }
    /**
     * Unexecution of an Select operation
     */
    @Override
    public void unexecute() {
        System.out.println("Unexecuting select operation");
    }
    /**
     * Creates a string representation of an SelectOperation object.
     * @return String representation of an SelectOperation object.
     */
    @Override
    public String toString() {
        return "SelectOperation{" +
                "tableName='" + tableName + '\'' +
                ", col='" + col + '\'' +
                ", condition='" + condition + '\'' +
                '}';
    }
}
