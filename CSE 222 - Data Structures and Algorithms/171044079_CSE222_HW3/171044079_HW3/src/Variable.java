/**The Variable class represents the variables with a string representative and a value*/
public class Variable {
    private String variableName;
    private double variableValue;
    /**Constructs a variable with a given name and a value
     * @param name the name of the variable
     * @param value the value of the variable
     * */
    public Variable(String name , double value){
        variableName = name;
        variableValue = value;
    }
    /**Getter for the variable's name
     * @return variable name
     * */
    public String getVariableName() {
        return variableName;
    }
    /**Setter for the variable's name
     * @param variableName variable name to be setted.
     * */
    public void setVariableName(String variableName) {
        this.variableName = variableName;
    }
    /**Getter for the variable's value
     * @return variable value
     * */
    public double getVariableValue() {
        return variableValue;
    }
    /**Setter for the variable's value
     * @param variableValue variable value to be setted.
     * */
    public void setVariableValue(int variableValue) {
        this.variableValue = variableValue;
    }
    /**Returns the proper string representation of the variable
     * @return string representation of the variable
     * */
    @Override
    public String toString() {
        return variableName + "=" + variableValue;
    }
}
