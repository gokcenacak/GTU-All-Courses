package Q3;

/**
 * This class represents the Green Light State of a Traffic Light
 * @author Gökçe Nur Erer
 */
public class GreenLightState implements TrafficLightState {
    /**
     * Returns the next state which has to be transitioned if yellow light time interval passes when
     * the current state is green light state
     * @return Next traffic light state
     */
    @Override
    public TrafficLightState yellowLightTimeIntervalPassed() {
        return new GreenLightState();
    }
    /**
     * Returns the next state which has to be transitioned if red light time interval passes when
     * the current state is green light state
     * @return Next traffic light state
     */
    @Override
    public TrafficLightState redLightTimeIntervalPassed() {
        return new GreenLightState();
    }
    /**
     * Returns the next state which has to be transitioned if green light time interval passes when
     * the current state is green light state
     * @return Next traffic light state
     */
    @Override
    public TrafficLightState greenLightTimeIntervalPassed() {
        return new YellowLightState();
    }
    /**
     * Returns the state name
     * @return State's name
     */
    @Override
    public String getStateName() {
        return "Green Light State";
    }
}
