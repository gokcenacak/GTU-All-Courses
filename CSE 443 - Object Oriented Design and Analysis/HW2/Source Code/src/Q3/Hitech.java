package Q3;

import java.util.ArrayList;
import java.util.List;

/**
 * This class represents a Hitech camera
 */
public class Hitech{
    private List<IObservableTrafficLight> trafficLights;
    private int defaultGreenLightInterval;
    private int updatedGreenLightInterval;

    /**
     * Constructor of the Hitech class
     * @param intervalUpdatedValue the value which will be updated when change is detected in the traffic
     */
    public Hitech(int intervalUpdatedValue){
        trafficLights = new ArrayList<>();
        updatedGreenLightInterval = intervalUpdatedValue;
    }

    /**
     * Depending on the flag value changes the timeoutX value
     * @param flag True if there is a change, False if not
     */
    public void changeDetected(boolean flag){
        System.out.println("----CHANGE DETECTED----");
        if(flag){
            for(IObservableTrafficLight trafficLight : trafficLights){
                trafficLight.changeTimeoutX(updatedGreenLightInterval);
            }
        }
        else{
            for(IObservableTrafficLight trafficLight : trafficLights){
                System.out.println("-----" + defaultGreenLightInterval);
                trafficLight.changeTimeoutX(defaultGreenLightInterval);
            }
        }

    }

    /**
     * Add a traffic light to the list of observers
     * @param light Light which will observe the camera
     */
    public void addTrafficLight(IObservableTrafficLight light){
        trafficLights.add(light);
        defaultGreenLightInterval = light.getGreenLightTimeInterval();
    }
    /**
     * Remove a traffic light from the list of observers
     * @param light Light which will ve removed from the observers of the camera
     */
    public void removeTrafficLight(IObservableTrafficLight light){
        trafficLights.remove(light);
    }
}
