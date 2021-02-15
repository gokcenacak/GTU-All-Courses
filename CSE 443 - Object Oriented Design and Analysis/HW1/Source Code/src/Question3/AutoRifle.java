package Question3;
/**
 * Accessory class that adds a Autorifle to a military equipment.
 * @author Gokce Nur Erer
 */
public class AutoRifle extends Accessory{
    /**
     * Equipment which the autorifle will be added.
     */
    private MilitaryEquipment equipment;

    /**
     * Constructor of Autorifle
     * @param eq The equipment which the autorifle will be added.
     */
    public AutoRifle(MilitaryEquipment eq){
        this.equipment = eq;
    }
    /**
     * Gets the cost of the equipment
     * @return Cost of the equipment
     */
    @Override
    public int cost() {
        return this.equipment.cost() + 30000;
    }
    /**
     * Gets the weight of the equipment
     * @return Weight of the equipment
     */
    @Override
    public double weight() {
        return this.equipment.weight() + 1.5;
    }
}
