package Q1;

import Q1.PhoneParts.BatteryType;

/**
 * This class represents a global smartphone factory
 * @author Gokce Nur Erer
 */
public class GlobalSmartphoneFactory extends RegionalSmartphoneFactory{
    /**
     * Constructor of GlobalSmartphoneFactory
     */
    public GlobalSmartphoneFactory(){
        phoneFactory = new SmartphoneFactory();
    }

    /**
     * Adds regional specifications for global kind of manufacturing
     * @param phone Base phone to add the specifications
     */
    @Override
    protected void addRegionalSpecifications(Smartphone phone) {
        System.out.println("Attaching display...");
        phone.getDisplay().setBits(24);
        System.out.println("Attaching battery...");
        phone.getBattery().setType(BatteryType.LithiumCobalt);
        System.out.println("Attaching CPU & RAM...");
        phone.getCpuAndRam().setCores(2);
        System.out.println("Attaching storage...");
        phone.getStorage().setMaxStorage(32);
        System.out.println("Attaching camera...");
        phone.getCamera().setOptZoom(2);
        System.out.println("Enclosing phone case...");
        phone.getPhoneCase().setWaterproofLength(0.5);
    }

    /**
     * Creates a smartphone whose model is Maximum Effort with global standards
     * @return Maximum Effort type of smartphone with global standarts
     */
    @Override
    public Smartphone getMaximumEffortPhone() {
        Smartphone phone = phoneFactory.getMaximumEffortPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is Iflas Deluxe with global standards
     * @return Iflas Deluxe type of smartphone with global standarts
     */
    @Override
    public Smartphone getIflasDeluxePhone() {
        Smartphone phone = phoneFactory.getIflasDeluxePhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is I-I-Aman Iflas with global standards
     * @return I-I-Aman Iflas type of smartphone with global standarts
     */
    @Override
    public Smartphone getIIAmanIflasPhone() {
        Smartphone phone = phoneFactory.getIIAmanIflasPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
}
