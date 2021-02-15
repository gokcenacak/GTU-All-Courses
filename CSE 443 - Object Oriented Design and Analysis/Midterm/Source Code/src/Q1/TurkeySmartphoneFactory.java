package Q1;

import Q1.PhoneParts.BatteryType;
/**
 * This class represents a Turkey smartphone factory
 * @author Gokce Nur Erer
 */
public class TurkeySmartphoneFactory extends RegionalSmartphoneFactory{
    /**
     * Constructor of TurkeySmartphoneFactory
     */
    public TurkeySmartphoneFactory(){

        phoneFactory = new SmartphoneFactory();
    }
    /**
     * Adds regional specifications for Turkey kind of manufacturing
     * @param phone Base phone to add the specifications
     */
    protected void addRegionalSpecifications(Smartphone phone){
        System.out.println("Attaching display...");
        phone.getDisplay().setBits(32);
        System.out.println("Attaching battery...");
        phone.getBattery().setType(BatteryType.LithiumBoron);
        System.out.println("Attaching CPU & RAM...");
        phone.getCpuAndRam().setCores(8);
        System.out.println("Attaching storage...");
        phone.getStorage().setMaxStorage(128);
        System.out.println("Attaching camera...");
        phone.getCamera().setOptZoom(4);
        System.out.println("Enclosing phone case...");
        phone.getPhoneCase().setWaterproofLength(2);
    }
    /**
     * Creates a smartphone whose model is Maximum Effort with Turkey standards
     * @return Maximum Effort model smartphone with Turkey standards
     */
    @Override
    public Smartphone getMaximumEffortPhone() {
        Smartphone phone = phoneFactory.getMaximumEffortPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is Iflas Deluxe with Turkey standards
     * @return Iflas Deluxe model smartphone with Turkey standards
     */
    @Override
    public Smartphone getIflasDeluxePhone() {
        Smartphone phone = phoneFactory.getIflasDeluxePhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is I-I-Aman Iflas with Turkey standards
     * @return I-I-Aman Iflas model smartphone with Turkey standards
     */
    @Override
    public Smartphone getIIAmanIflasPhone() {
        Smartphone phone = phoneFactory.getIIAmanIflasPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
}
