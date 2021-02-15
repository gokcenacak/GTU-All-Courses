package Question3;
/**
 * Accessory class that adds a RocketLauncher to a military equipment.
 * @author Gokce Nur Erer
 */
public class RocketLauncher extends Accessory {
    /**
     * Equipment which the rocket launcher will be added.
     */
    private MilitaryEquipment equipment;

    /**
     * Constructor of RocketLauncher
     * @param eq The equipment which the rocket launcher will be added.
     */
    public RocketLauncher(MilitaryEquipment eq){
        this.equipment = eq;
    }

    /**
     * Gets the cost of the equipment
     * @return Cost of the equipment
     */
    @Override
    public int cost() {
        return this.equipment.cost() + 150000;
    }

    /**
     * Gets the weight of the equipment
     * @return Weight of the equipment
     */
    @Override
    public double weight() {
        return this.equipment.weight() + 7.5;
    }
}
