package Q3;

public interface TrafficLightState {
    /**
     * Returns the next state which has to be transitioned if yellow light time interval passes
     * @return Next traffic light state
     */
    TrafficLightState yellowLightTimeIntervalPassed();
    /**
     * Returns the next state which has to be transitioned if red light time interval passes
     * @return Next traffic light state
     */
    TrafficLightState redLightTimeIntervalPassed();
    /**
     * Returns the next state which has to be transitioned if green light time interval passes
     * @return Next traffic light state
     */
    TrafficLightState greenLightTimeIntervalPassed();
    /**
     * Returns the state name
     * @return State's name
     */
    String getStateName();
}
