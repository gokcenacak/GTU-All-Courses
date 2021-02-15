package Q1.PhoneParts;
/**
 * This class represents a battery in a smartphone.
 * @author Gokce Nur Erer
 */
public class Battery {
    /**
     * Hours of a battery can work functionally
     */
    private int batteryHour;
    /**
     * Capacity of an battery
     */
    private int capacity;
    /**
     * Type of the battery
     */
    private BatteryType type;

    /**
     * Constructor
     * @param hours Battery hours
     * @param capacity Battery Capacity
     */
    public Battery(int hours, int capacity){
        this.batteryHour = hours;
        this.capacity = capacity;
    }

    /**
     * Setter for battery hour
     * @param batteryHour Battery hours
     */
    public void setBatteryHour(int batteryHour) {
        this.batteryHour = batteryHour;
    }

    /**
     * Setter for battery capacity
     * @param capacity Battery capacity
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    /**
     * Setter for Battery Type
     * @param type Battery type
     */
    public void setType(BatteryType type) {
        this.type = type;
    }

    /**
     * Returns a string representation of a Battery object
     * @return String represantation of a Battery object
     */
    @Override
    public String toString() {
        return "Battery: Battery Hour = " + batteryHour + "h , Battery Capacity = " + capacity + "mAh , Battery Type = " + type.toString();
    }
}
