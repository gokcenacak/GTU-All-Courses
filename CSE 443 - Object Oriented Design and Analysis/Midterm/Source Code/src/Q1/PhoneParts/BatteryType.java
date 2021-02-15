package Q1.PhoneParts;

/**
 * Defines types of battery
 * @author Gokce Nur Erer
 */
public enum BatteryType {
    LithiumBoron("Lithium-Boron"),
    LithiumIon("Lithium-Ion"),
    LithiumCobalt("Lithium-Cobalt");

    private String typeName;
    BatteryType(String name){
        this.typeName = name;
    }

    @Override
    public String toString() {
        return typeName;
    }
}
