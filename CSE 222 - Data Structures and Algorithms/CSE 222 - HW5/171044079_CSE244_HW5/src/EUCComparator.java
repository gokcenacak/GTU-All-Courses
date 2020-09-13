import java.util.Comparator;
/**EUCComparator is a class that compares two color values according to Euclidean comparison*/

public class EUCComparator implements Comparator<Color> {
    @Override
    public int compare(Color c1, Color c2) {
        double EUCColor1 = Math.sqrt(Math.pow(c1.getRed(),2)+Math.pow(c1.getGreen(),2)+Math.pow(c1.getBlue(),2));
        double EUCColor2 = Math.sqrt(Math.pow(c2.getRed(),2)+Math.pow(c2.getGreen(),2)+Math.pow(c2.getBlue(),2));

        if(EUCColor1<EUCColor2){
            return -1;
        }
        else if(EUCColor1>EUCColor2){
            return 1;
        }
        else
            return 0;
    }
}
