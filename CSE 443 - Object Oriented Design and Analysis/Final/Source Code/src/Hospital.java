import java.util.Random;
/**
 * This class represents a hospital, implements Singleton pattern
 */
public class Hospital {
    private int currentVentilatorCount;
    private int maxVentilatorCount;
    private static volatile Hospital instance;

    private Hospital(){
    }

    /**
     * Returns created Hospital instance is created before, else creates one
     * @return Hospital instance
     */
    public static Hospital getInstance(){
        if(instance != null){
            return instance;
        }
        synchronized (Hospital.class) {
            if (instance == null) {
                instance = new Hospital();
            }

            return instance;
        }
    }

    /**
     * Initializes the hospital with the given maximum ventilator count
     * @param maxVentilatorCount Maximum ventilator count
     */
    public void initialize(int maxVentilatorCount){

        this.currentVentilatorCount = maxVentilatorCount;
        this.maxVentilatorCount = maxVentilatorCount;
    }

    /**
     * Admits a human in to the hospital
     * @param human Human to be admitted to the hospital
     */
    public synchronized void accept(Human human){
        assert (currentVentilatorCount >= 0);
        while (currentVentilatorCount == 0){
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        if(human.isInfected()){
            human.setHospitalized();
            currentVentilatorCount--;
        }
    }

    /**
     * Discharges a human from the hospital
     * @param human Human to be discharged from the hospital
     */
    public synchronized void discharge(Human human){
        if(currentVentilatorCount < maxVentilatorCount){
            currentVentilatorCount++;
        }
        notifyAll();
        human.setHealthy();
        Random rand = new Random();
        int x_pos = rand.nextInt(995);
        int y_pos = rand.nextInt(595);
        MovementDirection movementDirection = MovementDirection.values()[rand.nextInt(8)];
        human.setMovementDirection(movementDirection);
        human.setXPos(x_pos);
        human.setYPos(y_pos);
    }
}
