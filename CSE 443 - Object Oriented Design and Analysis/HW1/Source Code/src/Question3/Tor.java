package Question3;
/**
 * Class that is representing the Tor suit.
 * @author Gokce Nur Erer
 */
public class Tor extends MilitaryEquipment {
    /**
     * Returns the cost of the Tor suit
     * @return The cost of the Tor suit
     */
    @Override
    public int cost() {
        return 5000000;
    }
    /**
     * Returns the weight of the Tor suit
     * @return The weight of the Tor suit
     */
    @Override
    public double weight() {
        return 50;
    }
}
