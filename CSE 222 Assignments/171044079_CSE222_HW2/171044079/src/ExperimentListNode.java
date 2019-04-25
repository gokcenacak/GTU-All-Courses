/**ExperimentlistNode class represents the nodes in the ExperimentList data structure*/
public class ExperimentListNode {
    private Experiment experiment;
    private ExperimentListNode nextExperiment = null;
    private ExperimentListNode nextDay = null;

    public Experiment getExperiment() {
        return experiment;
    }

    public void setExperiment(Experiment experiment) {
        this.experiment = experiment;
    }
    /**Constructor
     * @param e Experiment to create the node with.

     */
    public ExperimentListNode(Experiment e){
        experiment=e;
    }
    public ExperimentListNode getNextExperiment() {
        return nextExperiment;
    }

    public void setNextExperiment(ExperimentListNode nextExperiment) {
        this.nextExperiment = nextExperiment;
    }

    public ExperimentListNode getNextDay() {
        return nextDay;
    }

    public void setNextDay(ExperimentListNode nextDay) {
        this.nextDay = nextDay;
    }
}
