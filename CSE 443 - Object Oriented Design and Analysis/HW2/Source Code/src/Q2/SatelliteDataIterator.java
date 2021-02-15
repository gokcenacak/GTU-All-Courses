package Q2;

/**
 * This class represents the iterator of the SatelliteData class
 * @author Gökçe Nur Erer
 */
public class SatelliteDataIterator implements Iterator {
    /**
     * Current position of the iterator
     */
    private Tuple currentPosition;
    /**
     * Checks if all the data is traversed
     */
    private boolean traversedAll = false;
    /**
     * Checks if the data is single dimensional or the remaining data is single dimensional
     */
    private boolean isRemainingSingleDimensional = false;
    /**
     * Corner list for the current spiraling
     */
    private Tuple[] boundaryList;
    /**
     * Position of the last corner encountered
     */
    private int currentBoundaryCornerPos;
    /**
     * Satellite data which will be iterated on
     */
    private int [][] satelliteData;

    /**
     * Constructor of the SatelliteDataIterator class
     * @param data Satellite data which will be iterated on
     */
    public SatelliteDataIterator(int [][] data) {
        this.satelliteData = data;
        boundaryList = new Tuple[4];
        boundaryList[0] = new Tuple(0,0);
        boundaryList[1]= new Tuple(0,data[0].length - 1);
        boundaryList[2]= new Tuple(data.length - 1, data[0].length - 1);
        boundaryList[3] = new Tuple(data.length - 1, 0);
        currentBoundaryCornerPos = 0;
        currentPosition = new Tuple(0,0);

        ensureSingleDimensional();
    }

    /**
     * Checks if the iterator has a next element to visit in the data
     * @return If there is still unvisited data left, true; else false
     */
    @Override
    public boolean hasNext() {
        return !traversedAll;
    }

    /**
     * Changes the position of the iterator to the next element
     */
    @Override
    public void next() {
        if(hasNext()){
            if(currentBoundaryCornerPos == 0){
                if(currentPosition.equals(boundaryList[1])){
                    traversedAll = true;
                }
                currentPosition.setXY(currentPosition.getX(), currentPosition.getY()+1);
            }
            else if(currentBoundaryCornerPos == 1){
                if (isRemainingSingleDimensional){
                    traversedAll = true;
                }
                currentPosition.setXY(currentPosition.getX() + 1, currentPosition.getY());
            }
            else if(currentBoundaryCornerPos == 2){
                currentPosition.setXY(currentPosition.getX(), currentPosition.getY() - 1);
            }
            else if(currentBoundaryCornerPos == 3){
                currentPosition.setXY(currentPosition.getX() - 1, currentPosition.getY());
            }

            if(currentBoundaryCornerPos < 3 && currentPosition.equals(boundaryList[currentBoundaryCornerPos + 1])){
                currentBoundaryCornerPos++;
            }
            else if(currentBoundaryCornerPos == 3 && currentPosition.equals(boundaryList[0])){
                boolean canUpdate = updateBoundaries();

                if(canUpdate){
                    currentBoundaryCornerPos = 0;
                    currentPosition.setXY(boundaryList[0].getX(), boundaryList[0].getY());
                }
                else{
                    traversedAll = true;
                }
            }

        }
    }

    /**
     * Returns the element currently pointed by the iterator
     * @return The element currently pointed by the iterator
     */
    @Override
    public Object getCurrent() {
        return satelliteData[currentPosition.getX()][currentPosition.getY()];
    }

    private boolean updateBoundaries(){
        boundaryList[0].setXY(boundaryList[0].getX() + 1, boundaryList[0].getY() + 1);
        boundaryList[1].setXY(boundaryList[1].getX() + 1, boundaryList[1].getY() - 1);
        boundaryList[2].setXY(boundaryList[2].getX() - 1, boundaryList[2].getY() - 1);
        boundaryList[3].setXY(boundaryList[3].getX() - 1, boundaryList[3].getY() + 1);

        ensureSingleDimensional();

        return boundaryList[0].getX() <= boundaryList[2].getX() && boundaryList[0].getY() <= boundaryList[2].getY();
    }

    private void ensureSingleDimensional(){
        isRemainingSingleDimensional = boundaryList[0].equals(boundaryList[3]) && boundaryList[1].equals(boundaryList[2]);
    }
}
