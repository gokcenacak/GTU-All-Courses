package Q3;

public class YellowLightState implements TrafficLightState{
    /**
     * Returns the next state which has to be transitioned if yellow light time interval passes when
     * the current state is yellow light state
     * @return Next traffic light state
     */
    @Override
    public TrafficLightState yellowLightTimeIntervalPassed() {
        return new RedLightState();
    }
    /**
     * Returns the next state which has to be transitioned if red light time interval passes when
     * the current state is yellow light state
     * @return Next traffic light state
     */
    @Override
    public TrafficLightState redLightTimeIntervalPassed() {
        return new YellowLightState();
    }
    /**
     * Returns the next state which has to be transitioned if green light time interval passes when
     * the current state is yellow light state
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
        return "Yellow Light State";
    }
}
