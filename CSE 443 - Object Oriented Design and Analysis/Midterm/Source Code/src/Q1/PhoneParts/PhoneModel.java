package Q1.PhoneParts;

/**
 * Defines types of phone models.
 * @author Gokce Nur Erer
 */
public enum PhoneModel {
    MaximumEffort("Maximum Effort"),
    IflasDeluxe("Iflas Deluxe"),
    IIAmanIflas("I-I-Aman-Iflas");

    private String typeName;
    PhoneModel(String name){
        this.typeName = name;
    }

    @Override
    public String toString() {
        return typeName;
    }
}
