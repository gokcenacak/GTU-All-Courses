package Q3;

public interface IObservableTrafficLight {
    /**
     * Changes timeoutX value which is the green light time interval
     * @param value New timeoutX value to be used
     */
    void changeTimeoutX(int value);
    /**
     * Getter for green light time interval a.k.a timeoutX
     * @return Green light time interval
     */
    int getGreenLightTimeInterval();
    /**
     * Handles the state changes with the given change of seconds
     * @param deltaSeconds Delta seconds
     */
    void handleRequest(int deltaSeconds);
}
