package Q1.PhoneParts;

/**
 * This class defines a smartphone case's dimensions
 * @author Gokce Nur Erer
 */
public class CaseDimension {
    /**
     * Width of a case
     */
    private double width;
    /**
     * Height of a case
     */
    private double height;
    /**
     * Thickness of a case
     */
    private double thickness;

    /**
     * Constructor of CaseDimension
     * @param height Height
     * @param width Width
     * @param thickness Thickness
     */
    public CaseDimension(double height, double width, double thickness){
        this.width = width;
        this.height = height;
        this.thickness = thickness;
    }

    /**
     * Getter for width
     * @return Width of the case
     */
    public double getWidth() {
        return width;
    }

    /**
     * Getter for height
     * @return Height of the case
     */
    public double getHeight() {
        return height;
    }

    /**
     * Getter for thickness
     * @return Thickness of the case
     */
    public double getThickness() {
        return thickness;
    }
}
