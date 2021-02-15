package Q4;
/**
 * This class is an representation of the One Dimensional Transform method Discrete Fourier Transform.
 * @author Gokce Nur Erer
 */
public class DiscreteFourierTransform extends OneDimensionalTransform {
    private long startingTime;
    private long endingTime;
    private boolean shouldPrintExecutionTime;

    /**
     * Constructor of DiscreteFourierTransform
     * @param filename File to read the values from
     * @param shouldPrintExecutionTime Value if execution time should be printed or not
     */
    public DiscreteFourierTransform(String filename, boolean shouldPrintExecutionTime) {
        super(filename);
        this.shouldPrintExecutionTime = shouldPrintExecutionTime;
    }
    /**
     * Applies Discrete Fourier Transform to a given string value array
     * @param valueArray Array of values
     * @return Array of results of Discrete Fourier Transform
     */
    @Override
    public String [] applyTransform(String[] valueArray) {
        startingTime = System.nanoTime();
        String [] resArray = new String[valueArray.length];
        for(int k = 0; k < valueArray.length ; k++){
            double realSum = 0;
            double imgSum = 0;
            for(int n = 0; n < valueArray.length ; n++){
                realSum += Double.parseDouble(valueArray[n]) * Math.cos(2*Math.PI / valueArray.length * k * n);
                imgSum -= Double.parseDouble(valueArray[n]) * Math.sin(2*Math.PI / valueArray.length * k * n);
            }
            resArray[k] = String.format("%.2f",realSum) + String.format("%+.2f",imgSum) + "i";
        }
        endingTime = System.nanoTime();
        return resArray;
    }

    /**
     * Prints the time of execution
     */
    @Override
    public void printTimeOfExecution(){
        if(shouldPrintExecutionTime){
            System.out.println(endingTime - startingTime + " nanoseconds");
        }
        else{
            super.printTimeOfExecution();
        }
    }
}
