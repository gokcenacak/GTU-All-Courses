import java.lang.*;
public class Experiment {
    private String setup;
    private int day;
    private String time;
    private boolean completed;
    private float accuracy;

    public Experiment(String setup , int day , String time , boolean completed , float accuracy){
        setSetup(setup);
        setDay(day);
        setTime(time);
        setCompleted(completed);
        setAccuracy(accuracy);
    }
    public Experiment(Experiment e){
        setSetup(e.setup);
        setDay(e.day);
        setTime(e.time);
        setCompleted(e.completed);
        setAccuracy(e.accuracy);
    }

    private String getSetup() {
        return setup;
    }

    private void setSetup(String setup) {
        this.setup = setup;
    }

    int getDay() {
        return day;
    }

    void setDay(int day) {
        this.day = day;
    }

    private String getTime() {
        return time;
    }

    private void setTime(String time) {
        this.time = time;
    }

    boolean isCompleted() {
        return completed;
    }

    private void setCompleted(boolean completed) {
        this.completed = completed;
    }

    float getAccuracy() {
        return accuracy;
    }

    private void setAccuracy(float accuracy) {
        this.accuracy = accuracy;
    }

    @Override
    public String toString() {
        return ("Experiment Setup:" + this.getSetup() + "\n" + "Day:" + this.getDay() + "\n" + "Time:" +
                this.getTime() + "\n" + "Completed:" + this.isCompleted() + "\n" + "Accuracy:" + this.getAccuracy());
    }
}
