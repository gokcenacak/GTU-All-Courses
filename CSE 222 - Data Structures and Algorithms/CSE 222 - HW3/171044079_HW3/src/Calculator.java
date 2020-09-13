import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**Calculator class represents a calculator which first transforms an infix notation to a postfix
 * notation, and evaluates the expression.
 */
public class Calculator {
    private static final String [] OPERATORS = {"+","-","*","/","sin","cos","abs"};
    private static final int[] PRECEDENCE = {1 , 1 , 2 , 2 , 3 , 3 , 3};
    private LinkedList variablesAndValues = new LinkedList();
    private StringBuilder postfixExpression;
    private StringBuilder infixExpression;

    public StringBuilder getPostfixExpression() {
        return postfixExpression;
    }

    public StringBuilder getInfixExpression() {
        return infixExpression;
    }



    /**Constructs a Calculator object by reading the contents from the file and initializes
     * variables and infix notation.
     */
    public Calculator(){
        BufferedReader reader;
        try{
            System.out.println("Enter the file name:");
            Scanner scan = new Scanner(System.in);
            String fileName = scan.next();
            reader = new BufferedReader(new FileReader(fileName));
            StringBuilder line = new StringBuilder();
            String temp;
            while(!(temp = reader.readLine()).isEmpty()){
                String arr[] = temp.split(" ");
                Variable var = new Variable(arr[0] , Double.parseDouble(arr[2]));
                variablesAndValues.add(var);
            }
            System.out.println(variablesAndValues.toString());

            temp = reader.readLine();
            infixExpression = new StringBuilder();
            infixExpression.append(temp);
            System.out.println("The Infix Notation: " + infixExpression.toString());

        }
        catch(IOException e){
            System.out.println("There is a problem with the file/reading from file.");
        }
    }
    /**Transforms the infix notation in the calculator to a postfix notation using a stack.
     * Precedence of the operators in the infix notation, and parenthesises are considered.
     * @return converted postfix expression of the infix expression
     * */
    public String infixToPostfix(){
        Stack<String> operatorStack;
        operatorStack = new Stack<>();
        postfixExpression = new StringBuilder();
        String temp = infixExpression.toString().replaceAll("sin" , "sin " );
        String temp1 = temp.replaceAll("cos" , "cos " );
        String temp2 = temp1.replaceAll("abs" , "abs " );
        String[] arr = temp2.split(" ");

        for(int i = 0 ; i < arr.length ; ++i){

                if(isOperator(arr[i])){
                    if(operatorStack.empty())
                        operatorStack.push(arr[i]);
                    else{
                        String temp3 = operatorStack.peek();
                        if(isOperator(temp3) && precedence(arr[i]) >= precedence(temp3)){
                            operatorStack.push(arr[i]);
                        }
                        else{
                            while(!operatorStack.empty() && isOperator(operatorStack.peek()) &&(precedence(arr[i]) <= precedence(operatorStack.peek()))){
                                postfixExpression.append(operatorStack.pop());
                                postfixExpression.append(" ");

                            }
                            operatorStack.push(arr[i]);
                        }
                    }
                }

                else if(!operatorStack.empty() && arr[i].equals(")")){
                    while(!operatorStack.peek().equals("(")) {
                        if(isOperator(operatorStack.peek())) {
                            postfixExpression.append(operatorStack.peek());
                            postfixExpression.append(" ");
                        }
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }

                else{
                    if(arr[i].equals("("))
                        operatorStack.push(arr[i]);
                    else {
                        postfixExpression.append(arr[i]);
                        postfixExpression.append(" ");
                    }
                }

        }

        while(!operatorStack.empty()){
            if(!operatorStack.peek().equals("("))
            postfixExpression.append(operatorStack.peek());
            postfixExpression.append(" ");
            operatorStack.pop();
        }
        return postfixExpression.toString();

    }
    /**Evaluates the postfix notation and returns the result
     * @return the evaluated postfix notation's result.
     * */
    public double calculate(){
        double operand1,operand2;
        String[] arr = postfixExpression.toString().split(" ");
        Stack<String> calculationStack = new Stack<>();

        for(int i = 0 ; i < arr.length ; ++i){
            if(!isOperator(arr[i])){
                if(variablesAndValues.exists(arr[i])){
                    calculationStack.push(Double.toString(variablesAndValues.getValueOfVar(arr[i])));
                }
                else {
                    calculationStack.push(arr[i]);
                }
            }
            else{
                String operator = arr[i];
                switch (operator){
                    case "+" : operand2 = Double.parseDouble(calculationStack.pop());
                               operand1 = Double.parseDouble(calculationStack.pop());
                               calculationStack.push(Double.toString(operand1 + operand2));
                               break;

                    case "-" : operand2 = Double.parseDouble(calculationStack.pop());
                               operand1 = Double.parseDouble(calculationStack.pop());
                               calculationStack.push(Double.toString(operand1 - operand2));
                               break;

                    case "*" : operand2 = Double.parseDouble(calculationStack.pop());
                               operand1 = Double.parseDouble(calculationStack.pop());
                               calculationStack.push(Double.toString(operand1 * operand2));
                               break;

                    case "/" : operand2 = Double.parseDouble(calculationStack.pop());
                               operand1 = Double.parseDouble(calculationStack.pop());
                               calculationStack.push(Double.toString(operand1 / operand2));
                               break;

                    case "sin" : operand1 = Double.parseDouble(calculationStack.pop());
                                 calculationStack.push(Double.toString(sin(operand1)));
                                 break;

                    case "cos" : operand1 = Double.parseDouble(calculationStack.pop());
                                 calculationStack.push(Double.toString(cos(operand1)));
                                 break;

                    case "abs" : operand1 = Double.parseDouble(calculationStack.pop());
                                 calculationStack.push(Double.toString(abs(operand1)));
                                 break;
                }
            }
        }
        return Double.parseDouble(calculationStack.pop());
    }

    /**Calculates the absolute value of a number. If the argument is not negative, the argument
     * is returned. If the argument is negative the negation of the argument is returned.
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument */
    public double abs(double a){
        return (a<=0.0) ? 0.0 - a : a;
    }

    /**Calculates the sine value of the degree given by the argument. Uses the Taylor expansion for calculating
     * sinus value.
     * @param x the argument whose sine is to be determined.
     * @return the sine value of the argument.
     */
    public double sin(double x){
        double result = 0;
        x = x*3.14/180;

        for(int i = 0 ; i < 1000 ; i++){
            result += power(-1,i)*(power(x,2*i+1))/(factorial(2*i+1));

        }
        return result;
    }
    /**Calculates the cosine value of the degree given by the argument. Uses the Taylor expansion for calculating
     * cosine value.
     * @param x the argument whose cosine is to be determined.
     * @return the sinus value of the argument.
     */
    public double cos(double x){
        double result = 0;
        x = x*3.14/180;

        for(int i = 0 ; i < 1000 ; i++){
                result += power(-1,i)*(power(x,2*i))/(factorial(2*i));

        }
        return result;
    }
    /**Returns the value of the first argument raised to the power of the second argument
     * @param x the base
     * @param y the exponent
     * @return the value of x to the power of y.
     */
    public double power(double x , double y){
        double result = 1;

        for(int i = 0 ; i < y ; ++i){
            result*=x;
        }
        return result;
    }
    /**Returns the factorial of the argument
     * @param x the argument whose factorial is to be determined.
     * @return the factorial of x.
     */
    public double factorial(int x){
        double result = 1;

        for(int i = x ; i > 0 ; --i){
            result*=i;
        }
        return result;
    }
    /**Checks if a given string is an operator defined in OPERATORS array
     * @param s the string which will be checked if it is an operator or not.
     * @return true, if it is equal to an operator defined in OPERATORS array, false otherwise.
     * */
    public boolean isOperator(String s){
        for(int i = 0 ; i < OPERATORS.length ; ++i){
            if(s.equals(OPERATORS[i]))
                return true;
        }
        return false;
    }
    /**Returns the precedence value corresponding to the operator
     * @param s the string which contains the operator to get the precedence of
     * @return the precedence of the operator
     * */
    public int precedence(String s){
        int index=0;
        for(int i = 0 ; i < OPERATORS.length ; ++i){
            if(s.equals(OPERATORS[i]))
                index = i;
        }
        return PRECEDENCE[index];
    }
}
