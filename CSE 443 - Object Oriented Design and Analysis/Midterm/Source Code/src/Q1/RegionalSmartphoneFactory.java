package Q1;

/**
 * This abstract class defines an outline to a regional smartphone factory
 * @author Gokce Nur Erer
 */
public abstract class RegionalSmartphoneFactory {
    /**
     * Smartphone factory which a base of a phone can be created
     */
    SmartphoneFactory phoneFactory;

    /**
     * Adds regional specifications for different regions
     * @param phone Smartphone base
     */
    protected abstract void addRegionalSpecifications(Smartphone phone);

    /**
     * Creates a Maximum Effort model smartphone with regional specifications
     * @return Maximum Effort model smartphone with regional specifications
     */
    public abstract Smartphone getMaximumEffortPhone();

    /**
     * Creates a Iflas Deluxe model smartphone with regional specifications
     * @return Iflas Deluxe model smartphone with regional specifications
     */
    public abstract Smartphone getIflasDeluxePhone();

    /**
     * Creates a I-I-Aman Iflas model smartphone with regional specifications
     * @return I-I-Aman Iflas model smartphone with regional specifications
     */
    public abstract Smartphone getIIAmanIflasPhone();
}
