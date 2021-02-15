package Q1.PhoneParts;

public class Case {
    /**
     * Dimension of a case
     */
    private CaseDimension dimension;
    /**
     * Boolean variable to check if a case is dustproof or not
     */
    private boolean isDustproof;
    /**
     * Boolean variable to check if a case is waterproof or not
     */
    private boolean isWaterproof;
    /**
     * Type of the case
     */
    private CaseType type;
    /**
     * Length of the waterproof durability
     */
    private double waterproofLength;

    /**
     * Constructor of Case
     * @param dimension Dimensions of the case
     * @param isDustproof Is case dustproof or not
     * @param isWaterproof Is case waterproof or not
     * @param type Type of the case
     */
    public Case(CaseDimension dimension, boolean isDustproof, boolean isWaterproof, CaseType type){
        this.dimension = dimension;
        this.isDustproof = isDustproof;
        this.isWaterproof = isWaterproof;
        this.type = type;
    }

    /**
     * Setter for case dimension
     * @param dimension Dimensions of the case
     */
    public void setDimension(CaseDimension dimension) {
        this.dimension = dimension;
    }

    /**
     * Setter for if case is dustproof or not
     * @param dustproof If case is dustproof or not
     */
    public void setDustproof(boolean dustproof) {
        isDustproof = dustproof;
    }
    /**
     * Setter for if case is waterproof or not
     * @param waterproof If case is waterproof or not
     */
    public void setWaterproof(boolean waterproof) {
        isWaterproof = waterproof;
    }

    /**
     * Setter for case type
     * @param type Type of the case
     */
    public void setType(CaseType type) {
        this.type = type;
    }

    /**
     * Setter for the length of waterproof durability
     * @param waterproofLength Length of waterproof durability
     */
    public void setWaterproofLength(double waterproofLength) {
        this.waterproofLength = waterproofLength;
    }

    /**
     * Returns a string representation of a Case object
     * @return String representation of a Case object
     */
    @Override
    public String toString() {
        return "Case: Dimension = " + dimension.getHeight() + "x" + dimension.getWidth() + "x" + dimension.getThickness()
                + "mm , Dustproof = " + isDustproof + " , Waterproof = " + isWaterproof
                + " , Waterproof Length = " + waterproofLength + "m , Type = " + type.toString();
    }
}
