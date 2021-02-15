package Q3;

/**
 * This interface defines a database operation structure
 * @author Gokce Nur Erer
 */
public interface IDatabaseOperation {
    /**
     * Executes an operation on a given database
     * @param database Database which the operation will be executed
     * @return True if operation succeeds, otherwise false
     */
    boolean execute(Database database);

    /**
     * Sets the parameters of an operation
     * @param tableName Table name of the operation will be executed
     * @param col Column name of the operation will be executed
     * @param condition Condition of the operation will be executed
     */
    void setParameters(String tableName, String col, String condition);

    /**
     * Unexecution of an operation
     */
    void unexecute();
}
