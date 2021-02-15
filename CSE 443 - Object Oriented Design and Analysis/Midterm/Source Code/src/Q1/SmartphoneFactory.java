package Q1;

import Q1.PhoneParts.*;

/**
 * This class represents a smartphone factory which creates a base of a smartphone
 */
public class SmartphoneFactory {
    /**
     * Creates a Maximum Effort model smartphone base
     * @return A base Maximum Effort model smartphone base
     */
    Smartphone getMaximumEffortPhone(){
        Display display = new Display(5.5);
        Battery battery = new Battery(27,3600);
        CPU_RAM cpu_ram = new CPU_RAM(2.8,8);
        Storage storage = new Storage(StorageSupport.MicroSD, 64);
        Camera camera = new Camera(12,8);
        Case phoneCase = new Case(new CaseDimension(151,73,7.7), true, true, CaseType.Aluminum);
        return new Smartphone(PhoneModel.MaximumEffort, display, battery, cpu_ram,storage,camera,phoneCase);
    }
    /**
     * Creates a Iflas Deluxe model smartphone base
     * @return A base Iflas Deluxe model smartphone base
     */
    Smartphone getIflasDeluxePhone(){
        Display display = new Display(5.3);
        Battery battery = new Battery(20,2800);
        CPU_RAM cpu_ram = new CPU_RAM(2.2,6);
        Storage storage = new Storage(StorageSupport.MicroSD, 32);
        Camera camera = new Camera(12,5);
        Case phoneCase = new Case(new CaseDimension(149,73,7.7), false, true, CaseType.Aluminum);
        return new Smartphone(PhoneModel.IflasDeluxe, display, battery, cpu_ram,storage,camera,phoneCase);
    }
    /**
     * Creates a I-I-Aman Iflas model smartphone base
     * @return A base I-I-Aman Iflas model smartphone base
     */
    Smartphone getIIAmanIflasPhone(){
        Display display = new Display(4.5);
        Battery battery = new Battery(16,2000);
        CPU_RAM cpu_ram = new CPU_RAM(2.2,4);
        Storage storage = new Storage(StorageSupport.MicroSD, 16);
        Camera camera = new Camera(8,5);
        Case phoneCase = new Case(new CaseDimension(143,69,7.3), false, true, CaseType.Plastic);
        return new Smartphone(PhoneModel.IIAmanIflas, display, battery, cpu_ram,storage,camera,phoneCase);
    }
}
