package Q4;

/**
 * This class is an representation of the One Dimensional Transform method Discrete Cosine Transform.
 * @author Gokce Nur Erer
 */
public class DiscreteCosineTransform extends OneDimensionalTransform {
    /**
     * Constructor of DiscreteCosineTransform
     * @param filename File to read the values from
     */
    public DiscreteCosineTransform(String filename) {
        super(filename);
    }

    /**
     * Applies Discrete Cosine Transform to a given string value array
     * @param valueArray Array of values
     * @return Array of results of Discrete Cosine Transform
     */
    @Override
    public String [] applyTransform(String[] valueArray) {
        String [] resArray = new String[valueArray.length];

        for(int k = 0; k < valueArray.length ; k++){
            double realSum = 0;
            double coeff = (k==0) ? Math.sqrt(.5) : 1;
            for(int n = 0; n < valueArray.length; n++){
                realSum += Double.parseDouble(valueArray[n]) * Math.cos(Math.PI  * (n + 0.5) * k / valueArray.length) ;
            }
            double res = realSum * Math.sqrt(2./ valueArray.length) * coeff;
            resArray[k] = String.format("%.2f",res);
        }
        return resArray;


    }
}
