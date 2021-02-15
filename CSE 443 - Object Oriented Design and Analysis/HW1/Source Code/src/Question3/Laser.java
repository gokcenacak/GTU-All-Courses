package Question3;
/**
 * Accessory class that adds a laser to a military equipment.
 * @author Gokce Nur Erer
 */
public class Laser extends Accessory{
    /**
     * Equipment which the laser will be added.
     */
    private MilitaryEquipment equipment;
    /**
     * Constructor of Laser
     * @param eq The equipment which the laser will be added.
     */
    public Laser(MilitaryEquipment eq){
        this.equipment = eq;
    }
    /**
     * Gets the cost of the equipment
     * @return Cost of the equipment
     */
    @Override
    public int cost() {
        return this.equipment.cost() + 200000;
    }
    /**
     * Gets the weight of the equipment
     * @return Weight of the equipment
     */
    @Override
    public double weight() {
        return this.equipment.weight() + 5.5;
    }
}
