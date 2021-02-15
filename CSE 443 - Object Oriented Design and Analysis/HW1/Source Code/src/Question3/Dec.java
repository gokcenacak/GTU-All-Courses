package Question3;

/**
 * Class that is representing the Dec suit.
 * @author Gokce Nur Erer
 */
public class Dec extends MilitaryEquipment {
    /**
     * Returns the cost of the dec suit
     * @return The cost of the dec suit
     */
    @Override
    public int cost() {
        return 500000;
    }
    /**
     * Returns the weight of the dec suit
     * @return The weight of the dec suit
     */
    @Override
    public double weight() {
        return 25;
    }
}
