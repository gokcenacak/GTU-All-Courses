package Question3;
/**
 * Accessory class that adds a Flamethrower to a military equipment.
 * @author Gokce Nur Erer
 */
public class Flamethrower extends Accessory{
    /**
     * Equipment which the flamethrower will be added.
     */
    private MilitaryEquipment equipment;
    /**
     * Constructor of Flamethrower
     * @param eq The equipment which the flamethrower will be added.
     */
    public Flamethrower(MilitaryEquipment eq){
        this.equipment = eq;
    }

    /**
     * Gets the cost of the equipment
     * @return Cost of the equipment
     */
    @Override
    public int cost() {
        return this.equipment.cost() + 50000;
    }
    /**
     * Gets the weight of the equipment
     * @return Weight of the equipment
     */
    @Override
    public double weight() {
        return this.equipment.weight() + 2;
    }
}
