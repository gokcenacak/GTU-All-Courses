import java.util.Comparator;
/**BMXComparator is a class that compares two color values according to bitmix comparison*/

public class BMXComparator implements Comparator<Color> {
    @Override
    public int compare(Color c1, Color c2) {
        if(mixedBit(c1) < mixedBit(c2)){
            return -1;
        }
        else if(mixedBit(c1) > mixedBit(c2)){
            return 1;
        }
        else
            return 0;
    }
    public int getRequestedBit(int num , int shifting){
        return (num >> shifting) & 1;
    }
    public int mixedBit(Color c){
        int result = 0 ;
        for(int i = 7 ; i >= 0 ; --i){
            result |= getRequestedBit(c.getRed() , i);
            result = result << 1;
            result |= getRequestedBit(c.getGreen() , i);
            result = result << 1;
            result |= getRequestedBit(c.getBlue() , i);
            result = result << 1;
        }
        result = result >> 1;
        return result;
    }
}
