package Q1;

import Q1.PhoneParts.*;

/**
 * This class represents a EU smartphone factory
 * @author Gokce Nur Erer
 */
public class EUSmartphoneFactory extends RegionalSmartphoneFactory{
    /**
     * Constructor of EUSmartphoneFactory
     */
    public EUSmartphoneFactory(){
        phoneFactory = new SmartphoneFactory();
    }

    /**
     * Adds regional specifications for EU kind of manufacturing
     * @param phone Base phone to add the specifications
     */
    @Override
    protected void addRegionalSpecifications(Smartphone phone) {
        System.out.println("Attaching display...");
        phone.getDisplay().setBits(24);
        System.out.println("Attaching battery...");
        phone.getBattery().setType(BatteryType.LithiumIon);
        System.out.println("Attaching CPU & RAM...");
        phone.getCpuAndRam().setCores(4);
        System.out.println("Attaching storage...");
        phone.getStorage().setMaxStorage(64);
        System.out.println("Attaching camera...");
        phone.getCamera().setOptZoom(3);
        System.out.println("Enclosing phone case...");
        phone.getPhoneCase().setWaterproofLength(1);
    }

    /**
     * Creates a smartphone whose model is Maximum Effort with EU standards
     * @return Maximum Effort model smartphone with EU standards
     */
    @Override
    public Smartphone getMaximumEffortPhone() {
        Smartphone phone = phoneFactory.getMaximumEffortPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is Iflas Deluxe with EU standards
     * @return Iflas Deluxe model smartphone with EU standards
     */
    @Override
    public Smartphone getIflasDeluxePhone() {
        Smartphone phone = phoneFactory.getIflasDeluxePhone();
        addRegionalSpecifications(phone);
        return phone;
    }
    /**
     * Creates a smartphone whose model is I-I-Aman Iflas with EU standards
     * @return I-I-Aman Iflas model smartphone with EU standards
     */
    @Override
    public Smartphone getIIAmanIflasPhone() {
        Smartphone phone = phoneFactory.getIIAmanIflasPhone();
        addRegionalSpecifications(phone);
        return phone;
    }
}
