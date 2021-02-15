package Question3;

/**
 * Class that represents the add-on accessories to the suits
 * @author Gokce Nur Erer
 */
public abstract class Accessory extends MilitaryEquipment {
    /**
     * Gets the cost of the equipment
     * @return Cost of the equipment
     */
    public abstract int cost();
    /**
     * Gets the weight of the equipment
     * @return Weight of the equipment
     */
    public abstract double weight();
}
