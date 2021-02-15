package Q1.PhoneParts;

/**
 * This class represents a display in a smartphone
 * @author Gokce Nur Erer
 */
public class Display {
    /**
     * Size of the display
     */
    private double size;
    /**
     * Bit size of the display
     */
    private int bits;

    /**
     * Constructor of display
     * @param size Size of the display
     */
    public Display(double size){
        this.size = size;
    }

    /**
     * Setter for display size
     * @param size Size of the display
     */
    public void setSize(double size) {
        this.size = size;
    }

    /**
     * Setter for display bit size
     * @param bits Bit size of the display
     */
    public void setBits(int bits) {
        this.bits = bits;
    }
    /**
     * Returns a string representation of a Display object
     * @return String represantation of a Display object
     */
    @Override
    public String toString() {
        return "Display: Size = " + size + " inches , Bit Size = " + bits + " bits";

    }
}
