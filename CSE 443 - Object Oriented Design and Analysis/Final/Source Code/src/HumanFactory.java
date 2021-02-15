import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * This class represents a factory that creates random humans
 * @author Gokce Nur Erer
 */
public class HumanFactory {
    /**
     * Creates a human with randomized parameters
     * @return A human
     */
    public Human createHuman(){
        Random rand = new Random();
        int speed = rand.nextInt(500) + 1;
        double wearsMask = rand.nextInt(2);
        wearsMask = wearsMask == 0 ? 0.2 : 1.0;
        int socialDistance = rand.nextInt(10);
        int socialTime = rand.nextInt(4) + 1;

        //Will be random in a 1000x600 area
        int x_pos = rand.nextInt(995);
        int y_pos = rand.nextInt(595);
        MovementDirection movementDirection = MovementDirection.values()[rand.nextInt(8)];

        return new Human(speed,wearsMask,socialDistance,socialTime,x_pos,y_pos,movementDirection);
    }

    /**
     * Creates a randomized human group with a given size
     * @param size Size of the human group desired to be created
     * @return A human group
     */
    public List<Human> createHumanGroup(int size){
        List<Human> humanGroup = new ArrayList<>();
        for(int i = 0; i < size; i++){
            Human human = createHuman();
            human.name = "human-" + i;
            humanGroup.add(human);
        }

        return humanGroup;
    }
}
