import java.util.Comparator;
/**LEXComparator is a class that compares two color values according to lexicographical comparison*/
public class LEXComparator implements Comparator<Color> {
    @Override
    public int compare(Color c1, Color c2) {
       if(c1.getRed() < c2.getRed())
           return -1;
       else if(c1.getRed() > c2.getRed())
           return 1;
       if(c1.getGreen() < c2.getGreen())
           return -1;
       else if(c1.getGreen() > c2.getGreen())
           return 1;
       if(c1.getBlue() < c2.getBlue())
           return -1;
       else if(c1.getBlue() > c2.getBlue())
           return 1;

       return 0;

    }
}
