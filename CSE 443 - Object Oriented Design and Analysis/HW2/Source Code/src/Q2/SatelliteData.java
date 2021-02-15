package Q2;

/**
 * This class represents the satellite data
 * @author Gökçe Nur Erer
 */
public class SatelliteData implements Iterable {
    /**
     * 2D Array representing the data
     */
    private final int [][] data;

    /**
     * Constructor of the SatelliteData class
     * @param array Satellite data which will be represented
     */
    public SatelliteData(int [][] array){
        data = array;
    }

    /**
     * Returns an iterator for the SatelliteData instance
     * @return An iterator
     */
    @Override
    public Iterator iterator() {
        return new SatelliteDataIterator(this.data);
    }

}
