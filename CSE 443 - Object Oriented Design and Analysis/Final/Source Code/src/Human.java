import javax.swing.*;
import java.awt.*;
import java.util.Random;

/**
 * Represents movement directions of a human
 * @author Gokce Nur Erer
 */
enum MovementDirection{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NORTHEAST,
    NORTHWEST,
    SOUTHEAST,
    SOUTHWEST,
}

/**
 * Represents the health state of a human
 * @author Gokce Nur Erer
 */
enum HealthState
{
    Healthy,
    Infected,
    Hospitalized,
    Dead
}

/**
 * This class represents a human
 * @author Gokce Nur Erer
 */
public class Human {
    public String name;

    private int speed;
    private double wearsMask;
    private int socialDistance;
    private int socialTime;
    private int x_pos;
    private int y_pos;
    private MovementDirection movementDirection;
    private boolean canMove;
    private int stallDuration;
    private int currentStallTime;
    private int secondsPassedAfterInfection;
    private int secondsUntilDeath = -1;
    private int secondsUntilHospitalizing = -1;
    private HealthState currentHealthState;
    private int timeInHospital = 0;
    private Thread hospitalizationThread;

    /**
     * Constructor that creates a Human with given parameters
     * @param speed Speed of the human
     * @param wearsMask Mask status of the human
     * @param socialDistance Social distance the human practices
     * @param socialTime Time that the human spends when socializing
     * @param x_pos x coordinate of the human's position
     * @param y_pos y coordinate of the human's position
     * @param direction Movement direction of the human
     */
    public Human(int speed, double wearsMask, int socialDistance, int socialTime, int x_pos, int y_pos, MovementDirection direction){
        this.speed = speed;
        this.wearsMask = wearsMask;
        this.socialDistance = socialDistance;
        this.socialTime = socialTime;
        this.movementDirection = direction;
        this.x_pos = x_pos;
        this.y_pos = y_pos;
        this.canMove = true;
        this.stallDuration = -1;
        setHealthy();

    }

    /**
     * Returns the x coordinate of human's position
     * @return x coordinate of human's position
     */
    public int getXPos() {
        return x_pos;
    }

    /**
     * Returns the y coordinate of human's position
     * @return y coordinate of human's position
     */
    public int getYPos() {
        return y_pos;
    }

    /**
     * Returns the movement direction of the human
     * @return Movement direction of the human
     */
    public MovementDirection getMovementDirection() {
        return movementDirection;
    }

    /**
     * Returns the mask status of human
     * @return Mask status of human
     */
    public double getWearsMask() {
        return wearsMask;
    }

    /**
     * Returns the social distance the human practices
     * @return Social distance the human practices
     */
    public int getSocialDistance() {
        return socialDistance;
    }

    /**
     * Returns the time that human spends when it socializes
     * @return Time that human spends when it socializes
     */
    public int getSocialTime() {
        return socialTime;
    }

    /**
     * Returns the speed of human
     * @return Speed
     */
    public int getSpeed(){
        return speed;
    }

    /**
     * Returns the time spent in the hospital
     * @return Time spent in the hospital
     */
    public int getTimeInHospital() { return timeInHospital; }

    /**
     * Returns if the human can move
     * @return True if it can move, false if it can't move.
     */
    public boolean canMove() {
        return canMove;
    }

    /**
     * Sets the movement direction of the human
     * @param movementDirection Movement direction
     */
    public void setMovementDirection(MovementDirection movementDirection) {
        this.movementDirection = movementDirection;
    }

    /**
     * Sets the x coordinate of the human's position
     * @param x_pos x coordinate
     */
    public void setXPos(int x_pos) {
        if(canMove){
            this.x_pos = x_pos;
        }
    }

    /**
     * Sets the y coordinate of the human's position
     * @param y_pos y coordinate
     */
    public void setYPos(int y_pos) {
        if(canMove){
            this.y_pos = y_pos;
        }
    }

    /**
     * Checks if a human is dead
     * @return True if the human is dead, false otherwise
     */
    public boolean isDead() {
        return currentHealthState == HealthState.Dead;
    }
    /**
     * Checks if a human is hospitalized
     * @return True if the human is hospitalized, false otherwise
     */
    public boolean isHospitalized() {
        return currentHealthState == HealthState.Hospitalized;
    }
    /**
     * Checks if a human is infected
     * @return True if the human is infected, false otherwise
     */
    public boolean isInfected() {
        return currentHealthState == HealthState.Infected;
    }
    /**
     * Checks if a human is healthy
     * @return True if the human is healthy, false otherwise
     */
    public boolean isHealthy() { return  currentHealthState == HealthState.Healthy; }

    /**
     * Initializes seconds to death and seconds to hospitalize after infection of a human
     * @param secondsToHospitalize Seconds to hospitalize
     * @param secondsToKill Seconds to death
     */
    public void startCountdownAfterInfection(int secondsToHospitalize, int secondsToKill){
        this.secondsUntilDeath = secondsToKill;
        this.secondsUntilHospitalizing = secondsToHospitalize;
    }

    /**
     * Sets a human healthy
     */
    public void setHealthy(){
        this.currentHealthState = HealthState.Healthy;
        secondsPassedAfterInfection = 0;
        canMove = true;
    }

    /**
     * Sets a human infected
     */
    public void setInfected() {
        if (currentHealthState == HealthState.Healthy) {
            this.currentHealthState = HealthState.Infected;
        }
    }

    /**
     * Sets a human hospitalized
     */
    public void setHospitalized() {
        if(currentHealthState == HealthState.Infected){
            timeInHospital = 0;
            this.currentHealthState = HealthState.Hospitalized;
            canMove = false;
        }
    }

    /**
     * Sets a human dead
     */
    public void setDead() {
        this.currentHealthState = HealthState.Dead;
    }

    /**
     * Stalls a human for a given duration
     * @param stallDuration Stalling duration
     */
    public void stall(int stallDuration){
        currentStallTime = 0;
        this.stallDuration = stallDuration * 1000;
        canMove = false;
    }

    /**
     * Updates human with the given time interval
     * @param deltaTime Time interval
     */
    public void onTick(int deltaTime){
        if(canMove){
            updatePos(false);
        }
        else{
            currentStallTime += deltaTime;
        }
        if(currentHealthState == HealthState.Infected){
            secondsPassedAfterInfection += deltaTime;
            if(secondsPassedAfterInfection == secondsUntilHospitalizing * 1000){
                hospitalizationThread = new Thread(() -> {
                    Hospital.getInstance().accept(this);
                });
                hospitalizationThread.start();

            }
            if(secondsPassedAfterInfection == secondsUntilDeath * 1000){
                setDead();
            }
        }
        if(currentHealthState == HealthState.Hospitalized){
            if(timeInHospital == 10000){
                synchronized (this) {
                    Hospital.getInstance().discharge(this);
                }
            }
            timeInHospital += deltaTime;
        }
        if(currentStallTime == stallDuration){
            currentStallTime = 0;
            canMove = true;
            updatePos(true);
        }
    }

    /**
     * Updates the position of the human
     * @param forceChangeDirection Should it change direction without reaching to the bounds of the map
     */
    private void updatePos(boolean forceChangeDirection){
        Random rand = new Random();

        if(forceChangeDirection){
            setMovementDirection(MovementDirection.values()[rand.nextInt(8)]);
        }

        if(getXPos() > EpidemicSimulator.SIMULATION_MAX_X_POS){
            setMovementDirection(MovementDirection.values()[rand.nextInt(8)]);
            setXPos(EpidemicSimulator.SIMULATION_MAX_X_POS);
        }
        if(getYPos() > EpidemicSimulator.SIMULATION_MAX_Y_POS){
            setMovementDirection(MovementDirection.values()[rand.nextInt(8)]);
            setYPos(EpidemicSimulator.SIMULATION_MAX_Y_POS);
        }
        if(getXPos() < EpidemicSimulator.SIMULATION_MIN_X_POS){
            setMovementDirection(MovementDirection.values()[rand.nextInt(8)]);
            setXPos(EpidemicSimulator.SIMULATION_MIN_X_POS);
        }
        if(getYPos() < EpidemicSimulator.SIMULATION_MIN_Y_POS){
            setMovementDirection(MovementDirection.values()[rand.nextInt(8)]);
            setYPos(EpidemicSimulator.SIMULATION_MIN_Y_POS);
        }
        else{
            switch (getMovementDirection()) {
                case EAST -> setXPos(getXPos() + getSpeed());
                case WEST -> setXPos(getXPos() - getSpeed());
                case NORTH -> setYPos(getYPos() - getSpeed());
                case SOUTH -> setYPos(getYPos() + getSpeed());
                case NORTHEAST -> {
                    setYPos(getYPos() - getSpeed());
                    setXPos(getXPos() + getSpeed());
                }
                case NORTHWEST -> {
                    setYPos(getYPos() - getSpeed());
                    setXPos(getXPos() - getSpeed());
                }
                case SOUTHEAST -> {
                    setYPos(getYPos() + getSpeed());
                    setXPos(getXPos() + getSpeed());
                }
                case SOUTHWEST -> {
                    setYPos(getYPos() + getSpeed());
                    setXPos(getXPos() - getSpeed());
                }
            }
        }
    }

    /**
     * Returns a string representation of a human
     * @return String representation of a human
     */
    @Override
    public String toString() {
        return "Human{" +
                "speed=" + speed +
                ", wearsMask=" + wearsMask +
                ", socialDistance=" + socialDistance +
                ", socialTime=" + socialTime +
                ", infected=" + (currentHealthState == HealthState.Infected) +
                '}';
    }
}
