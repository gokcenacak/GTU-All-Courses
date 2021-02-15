
public class Main {
    public static void main(String[] args) {
        int tickPerMilliseconds = 50;
        EpidemicSimulator simulator = new EpidemicSimulator(tickPerMilliseconds);
        simulator.createWindow();
    }
}
