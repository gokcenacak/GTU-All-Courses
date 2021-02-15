package Q3;

import java.util.Timer;
import java.util.TimerTask;

public class Main {
    public static void main(String[] args) {
        TrafficLight light = new TrafficLight(1,3,5);
        Hitech camera = new Hitech(10);
        camera.addTrafficLight(light);

        int updateFrequencyMillis = 1000;
        int startingSecondWhenTrafficJams = 13;
        int startingSecondWhenTrafficClears = 26;

        final int[] count = {0};

        Timer timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                count[0] = count[0] + 1;
                System.out.println(count[0] + " seconds passed...");
                light.handleRequest(updateFrequencyMillis / 1000);
            }
        }, 0, updateFrequencyMillis);


        Timer timerForTrafficJam = new Timer();
        timerForTrafficJam.schedule(new TimerTask() {
            @Override
            public void run() {
                camera.changeDetected(true);
            }
        }, startingSecondWhenTrafficJams * 1000);

        Timer timerForClearingTrafficJam = new Timer();
        timerForClearingTrafficJam.schedule(new TimerTask() {
            @Override
            public void run() {
                camera.changeDetected(false);
            }
        }, startingSecondWhenTrafficClears * 1000);

    }
}
