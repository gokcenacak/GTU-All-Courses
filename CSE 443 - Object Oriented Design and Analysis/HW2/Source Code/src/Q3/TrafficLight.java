package Q3;

/**
 * This class represents a traffic light
 * @author Gökçe Nur Erer
 */
public class TrafficLight implements IObservableTrafficLight{
    /**
     * Current state
     */
    private TrafficLightState currentState;
    /**
     * Elapsed time at the current state
     */
    private int timeElapsed;
    /**
     * Time interval for yellow light
     */
    private int yellowLightTimeInterval;
    /**
     * Time interval for red light
     */
    private int redLightTimeInterval;
    /**
     * Time interval for green light
     */
    private int greenLightTimeInterval;

    /**
     * Getter for yellow light time interval
     * @return Yellow light time interval
     */
    public int getYellowLightTimeInterval() {
        return yellowLightTimeInterval;
    }

    /**
     * Getter for red light time interval
     * @return Red light time interval
     */
    public int getRedLightTimeInterval() {
        return redLightTimeInterval;
    }

    /**
     * Getter for green light time interval
     * @return Green light time interval
     */
    public int getGreenLightTimeInterval() {
        return greenLightTimeInterval;
    }

    /**
     * Constructor for the Traffic Light class
     * @param redLightTimeInterval Red Light Time Interval value
     * @param yellowLightTimeInterval Yellow Light Time Interval value
     * @param greenLightTimeInterval Green Light Time Interval value
     */
    public TrafficLight(int redLightTimeInterval, int yellowLightTimeInterval, int greenLightTimeInterval){
       currentState = new RedLightState();
       timeElapsed = 0;
       this.redLightTimeInterval = redLightTimeInterval;
       this.yellowLightTimeInterval = yellowLightTimeInterval;
       this.greenLightTimeInterval = greenLightTimeInterval;
    }

    /**
     * Handles the state changes with the given change of seconds
     * @param deltaSeconds Delta seconds
     */
    public void handleRequest(int deltaSeconds){
        timeElapsed += deltaSeconds;
        if(timeElapsed == redLightTimeInterval){
            redLightTimeIntervalPassed();
        }
        else if(timeElapsed == yellowLightTimeInterval){
            yellowLightTimeIntervalPassed();
        }
        else if(timeElapsed == greenLightTimeInterval){
            greenLightTimeIntervalPassed();
            timeElapsed = 0;
        }
        else{
            System.out.println("State didn't change, state is " + currentState.getStateName());
        }
    }


    private void yellowLightTimeIntervalPassed(){
        TrafficLightState prevState = currentState;
        currentState = currentState.yellowLightTimeIntervalPassed();

        if(prevState.getClass() != currentState.getClass()){
            System.out.println("Changing from state : " + prevState.getStateName() + " to: " + currentState.getStateName());
            timeElapsed = 0;
        }
        else{
            currentState = prevState;
            System.out.println("State didn't change, state is " + currentState.getStateName());
        }
    }

    private void redLightTimeIntervalPassed(){
        TrafficLightState prevState = currentState;
        currentState = currentState.redLightTimeIntervalPassed();
        if(prevState.getClass() != currentState.getClass()){
            System.out.println("Changing from state : " + prevState.getStateName() + " to: " + currentState.getStateName());
            timeElapsed = 0;
        }
        else{
            currentState = prevState;
            System.out.println("State didn't change, state is " + currentState.getStateName());
        }
    }

    private void greenLightTimeIntervalPassed(){
        TrafficLightState prevState = currentState;
        currentState = currentState.greenLightTimeIntervalPassed();

        if(prevState.getClass() != currentState.getClass()){
            System.out.println("Changing from state : " + prevState.getStateName() + " to: " + currentState.getStateName());
            timeElapsed = 0;
        }
        else{
            System.out.println("State didn't change, state is " + currentState.getStateName());
        }
    }

    /**
     * Changes timeoutX value which is the green light time interval
     * @param val New timeoutX value to be used
     */
    @Override
    public void changeTimeoutX(int val) {
        greenLightTimeInterval = val;
    }
}
