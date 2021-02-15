package Q4;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        if(args.length < 2  ||
            (Arrays.stream(args).anyMatch("DFT"::equalsIgnoreCase) && (args.length > 3) ) ||
            (Arrays.stream(args).anyMatch("DCT"::equalsIgnoreCase) && args.length != 2)){
            System.out.println("Usage: <program name> <filename> <transform-method> <if:transformMethod == DFT, shouldPrintExecutionTime>");
        }
        else {
            OneDimensionalTransform transform;
            if(args[1].equals("DFT")){
                if(args.length == 3){
                    transform = new DiscreteFourierTransform(args[0], true);

                }
                else{
                    transform = new DiscreteFourierTransform(args[0], false);
                }
                transform.executeTransform();
                transform.printTimeOfExecution();
            }
            else if(args[1].equals("DCT")){
                transform = new DiscreteCosineTransform(args[0]);
                transform.executeTransform();
                transform.printTimeOfExecution();
            }
        }
    }
}
