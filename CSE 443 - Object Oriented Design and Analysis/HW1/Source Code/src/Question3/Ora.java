package Question3;
/**
 * Class that is representing the Ora suit.
 * @author Gokce Nur Erer
 */
public class Ora extends MilitaryEquipment {
    /**
     * Returns the cost of the Ora suit
     * @return The cost of the Ora suit
     */
    @Override
    public int cost() {
        return 1500000;
    }
    /**
     * Returns the weight of the Ora suit
     * @return The weight of the Ora suit
     */
    @Override
    public double weight() {
        return 30;
    }
}
