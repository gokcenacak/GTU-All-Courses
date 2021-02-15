package Q4;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;

/**
 * This abstract class defines a one dimensional transform either with DCT or DFT
 * @author Gokce Nur Erer
 */
public abstract class OneDimensionalTransform {
    /**
     * Input file name
     */
    String inputFileName;

    /**
     * Constructor of OneDimensionalTransform
     * @param filename File to read the values from
     */
    public OneDimensionalTransform(String filename){
        this.inputFileName = filename;
    }

    /**
     * Reads the input file, performs the transform then writes the results to an output file.
     */
    public void executeTransform(){
        try{
            String fileInputValues = Files.readString(Path.of(inputFileName));
            String [] seperatedValues = fileInputValues.split("\\s+");
            String [] resultArray = applyTransform(seperatedValues);
            FileWriter outputFileWriter = new FileWriter("outputFile.txt");
            for (String str: resultArray){
                outputFileWriter.write(str + "\t");
            }
            outputFileWriter.close();

        }
        catch (IOException e){
            System.out.println("Could not open and read from the file!");
        }
    }

    /**
     * Applies either DCT or DFT to a given string value array
     * @param valueArray Array of values
     * @return Array of results of the transform
     */
    public abstract String [] applyTransform(String [] valueArray);
    /**
     * Prints the time of execution
     */
    public void printTimeOfExecution(){
        System.out.println("NO");
    }
}
