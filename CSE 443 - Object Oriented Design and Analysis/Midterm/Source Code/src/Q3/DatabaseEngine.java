package Q3;

import java.util.ArrayList;

/**
 * This class represents the database engine.
 * @author Gokce Nur Erer
 */
public class DatabaseEngine {
    /**
     * List of successful operations
     */
    ArrayList<IDatabaseOperation> successfulOperations;

    /**
     * Constructor of the database engine
     */
    public DatabaseEngine(){
        successfulOperations = new ArrayList<>();
    }

    /**
     * Executes an select operation
     * @param database Database to perform the operation
     * @param tableName Table to perform the operation
     * @param col Column to perform the operation
     * @param condition Condition to perform the operation
     */
    public void select(Database database, String tableName, String col, String condition){
        SelectOperation selectOperation = new SelectOperation();
        selectOperation.setParameters(tableName,col,condition);
        if(!selectOperation.execute(database)){
            rollback();
        }
        else{
            successfulOperations.add(selectOperation);
        }
    }
    /**
     * Executes an alter operation
     * @param database Database to perform the operation
     * @param tableName Table to perform the operation
     * @param col Column to perform the operation
     * @param condition Condition to perform the operation
     */
    public void alter(Database database, String tableName, String col, String condition){
        AlterOperation alterOperation = new AlterOperation();
        alterOperation.setParameters(tableName,col,condition);

        if(!alterOperation.execute(database)){
            rollback();
        }
        else{
            successfulOperations.add(alterOperation);
        }
    }
    /**
     * Executes an update operation
     * @param database Database to perform the operation
     * @param tableName Table to perform the operation
     * @param col Column to perform the operation
     * @param condition Condition to perform the operation
     */
    public void update(Database database, String tableName, String col, String condition){
        UpdateOperation updateOperation = new UpdateOperation();
        updateOperation.setParameters(tableName,col,condition);
        if(!updateOperation.execute(database)){
            rollback();
        }
        else{
            successfulOperations.add(updateOperation);
        }
    }

    /**
     * Rollbacks whole successful operations
     */
    public void rollback(){
        for(int i = successfulOperations.size() - 1; i >= 0; i--){
            successfulOperations.get(i).unexecute();
        }
        successfulOperations.clear();
    }

    /**
     * Prints all successful operations
     */
    public void printSuccessfulOperations(){
        if(successfulOperations.isEmpty()){
            System.out.println("There is no operation history");
        }
        for(IDatabaseOperation op : successfulOperations){
            System.out.println(op);
        }
    }
}
