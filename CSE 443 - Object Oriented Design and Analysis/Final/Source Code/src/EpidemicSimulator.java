import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

/**
 * This class represents a Epidemic Simulator
 * @author Gokce Nur Erer
 */
public class EpidemicSimulator {
    /**
     * Simulation's maximum x coordinate boundary
     */
    public static final int SIMULATION_MAX_X_POS = 995;
    /**
     * Simulation's maximum y coordinate boundary
     */
    public static final int SIMULATION_MAX_Y_POS = 595;
    /**
     * Simulation's minimum x coordinate boundary
     */
    public static final int SIMULATION_MIN_X_POS = 0;
    /**
     * Simulation's minimum y coordinate boundary
     */
    public static final int SIMULATION_MIN_Y_POS = 0;

    private int timeElapsed = 0;
    private int tickPerMilliseconds;
    private JLabel timerLabel;
    private JLabel healthyLabel;
    private JLabel deadLabel;
    private JLabel totalInfectionCasesLabel;
    private JLabel hospitalizedLabel;
    private JLabel currentHospitalizedCountLabel;
    private JLabel currentInfectedCountLabel;
    private JPanel simulationPanel;
    private JSpinner spreadingFactorSpinner;
    private JSpinner mortalityFactorSpinner;
    private JSpinner initialHumanCountSpinner;
    private Population population;
    private PopulationViewModel populationViewModel;
    private CollisionMediator collisionMediator;
    private HumanFactory humanFactory;
    private double spreadingFactor = 0;
    private double constantMortalityRate = 0;
    private int infectedCount = 0;
    private int deadCount;
    private int hospitalizedCount;
    private boolean isRunning;
    private int populationSize;
    private int initialPopulationSize;
    private EpidemicGraphWindow plotWindow;


    /**
     * Constructor that creates an Epidemic Simulator with a given update rate in milliseconds
     * @param tickPerMilliseconds Update rate in milliseconds
     */
    public EpidemicSimulator(int tickPerMilliseconds) {
        humanFactory = new HumanFactory();
        collisionMediator = new CollisionMediator(this);
        this.tickPerMilliseconds = tickPerMilliseconds;
        this.isRunning = false;
        plotWindow = new EpidemicGraphWindow();
    }

    /**
     * Returns if the simulation is running
     * @return True if the simulation is running, false otherwise
     */
    public boolean isRunning() {
        return isRunning;
    }

    /**
     * Returns the population in the simulation that is being simulated
     * @return Population in the simulation that is being simulated
     */
    public Population getPopulation() {
        return population;
    }

    /**
     * Returns the spreading factor used in the simulation
     * @return Spreading factor
     */
    public double getSpreadingFactor() {
        return spreadingFactor;
    }

    /**
     * Returns the constant mortality rate used in the simulation
     * @return Spreading factor
     */
    public double getConstantMortalityRate() {
        return constantMortalityRate;
    }

    /**
     * This class represents an action listener which updates the simulator.
     */
    private class EpidemicActionListener implements ActionListener {
        private EpidemicSimulator simulator;

        public EpidemicActionListener(EpidemicSimulator simulator) {
            this.simulator = simulator;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if(this.simulator.isRunning()) {
                this.simulator.onTick();
            }
        }
    }

    /**
     * Creates the simulation window
     */
    public void createWindow() {

        JFrame mainFrame = new JFrame("Epidemic Simulator");
        ImageIcon imgIcon = new ImageIcon(getClass().getResource("/Icons/baseline_coronavirus_black_18dp.png"));
        mainFrame.setIconImage(imgIcon.getImage());
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.getContentPane().setPreferredSize(new Dimension(1000, 750));

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.PAGE_AXIS));
        mainPanel.setBorder(new EmptyBorder(-1, -1, -1, -1));

        simulationPanel = createSimulationPanel();

        mainPanel.add(simulationPanel);


        JPanel statisticsPanel = createStatisticsPanel();
        mainPanel.add(statisticsPanel);

        mainFrame.add(mainPanel);
        mainFrame.setResizable(false);
        mainFrame.pack();
        mainFrame.setVisible(true);
        JOptionPane.showMessageDialog(mainFrame,
                "Welcome to Epidemic Simulator!\n" +
                        "Here are some basic tips on how to use this simulator before you start\n" +
                        "-Enter the initial population count and press OK.\n" +
                        "-Then enter spreading factor and mortality rate of your disease.\n" +
                        "-Press the play button and watch how it acts on a the generated population.\n" +
                        "-You can also use the pause button to stop the simulation and look up at your statistics and plotting.\n" +
                        "-Plotting is conducted in real time so you can look at it whenever you want." +
                        "-You can add people to the simulation by using the add humans button.\n"+
                        "Happy spreading?",
                "How To",
                JOptionPane.PLAIN_MESSAGE);

        JPanel humanCountPanel = new JPanel();
        JLabel humanCountLabel = new JLabel("Please enter initial human count (2-5000):");
        initialHumanCountSpinner = new JSpinner(new SpinnerNumberModel(2, 2, 5000, 1));
        humanCountPanel.add(humanCountLabel);
        humanCountPanel.add(initialHumanCountSpinner);
        JOptionPane.showMessageDialog(mainFrame, humanCountPanel, "Population Count", JOptionPane.PLAIN_MESSAGE, null);

    }

    /**
     * Creates the simulation panel of the simulator
     * @return Simulation panel
     */
    private JPanel createSimulationPanel(){
        JPanel simulationPanel = new JPanel();
        simulationPanel.setLayout(null);
        simulationPanel.setPreferredSize(new Dimension(1000,600));

        return simulationPanel;
    }

    /**
     * Creates the statistics panel of the simulator
     * @return Statistics panel
     */
    private JPanel createStatisticsPanel(){
        JPanel currentCountPanel = new JPanel(new GridLayout(3,2));
        currentCountPanel.setBorder(new EmptyBorder(10,0,0,0));

        timerLabel = new JLabel("Timer: - ");
        timerLabel.setFont (timerLabel.getFont().deriveFont (16f));
        timerLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        totalInfectionCasesLabel = new JLabel("Total Cases: -");
        totalInfectionCasesLabel.setFont (totalInfectionCasesLabel.getFont().deriveFont (16f));
        totalInfectionCasesLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        healthyLabel = new JLabel("Healthy: -");
        healthyLabel.setFont (healthyLabel.getFont().deriveFont (16f));

        hospitalizedLabel = new JLabel("Total Hospitalized Cases: -");
        hospitalizedLabel.setFont (hospitalizedLabel.getFont().deriveFont (16f));
        hospitalizedLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        deadLabel = new JLabel("Dead: -");
        deadLabel.setFont (deadLabel.getFont().deriveFont (16f));
        deadLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        currentHospitalizedCountLabel = new JLabel("Hospitalized: -");
        currentHospitalizedCountLabel.setFont(currentHospitalizedCountLabel.getFont().deriveFont(16f));

        currentInfectedCountLabel = new JLabel("Infected: -");
        currentInfectedCountLabel.setFont(currentInfectedCountLabel.getFont().deriveFont(16f));
        currentInfectedCountLabel.setBorder(BorderFactory.createEmptyBorder(0,20,0,0));

        currentCountPanel.add(timerLabel);
        currentCountPanel.add(healthyLabel);
        currentCountPanel.add(deadLabel);
        currentCountPanel.add(currentHospitalizedCountLabel);
        currentCountPanel.add(currentInfectedCountLabel);

        JPanel totalCountStats = new JPanel();
        GridLayout gridLayout = new GridLayout(2,1);
        gridLayout.setVgap(-30);
        totalCountStats.setLayout(gridLayout);
        totalCountStats.add(totalInfectionCasesLabel);
        totalCountStats.add(hospitalizedLabel);

        JPanel infoPanel = new JPanel();
        GridLayout layout = new GridLayout(2,1);
        layout.setVgap(10);
        infoPanel.setLayout(layout);
        infoPanel.add(currentCountPanel);
        infoPanel.add(totalCountStats);

        JPanel statisticsPanel = new JPanel();
        statisticsPanel.setLayout(new GridLayout(0,2));
        statisticsPanel.setBorder(BorderFactory.createStrokeBorder(new BasicStroke(8f)));
        statisticsPanel.setPreferredSize(new Dimension(1000,180));
        statisticsPanel.add(infoPanel);
        statisticsPanel.add(createControlPanel());

        return statisticsPanel;
    }

    /**
     * Creates the control panel of the simulation
     * @return Control panel
     */
    private JPanel createControlPanel(){

        JPanel spreadingFactorPanel = new JPanel();
        spreadingFactorPanel.setLayout(new BoxLayout(spreadingFactorPanel, BoxLayout.LINE_AXIS));
        spreadingFactorPanel.setBorder(new EmptyBorder(5,0,10,10));

        JLabel spreadingFactorLabel = new JLabel("Spreading Factor(R): ");
        spreadingFactorLabel.setFont (spreadingFactorLabel.getFont().deriveFont (16f));

        spreadingFactorSpinner = new JSpinner(new SpinnerNumberModel(0.5,0.5,1.0,0.1));
        JSpinner.DefaultEditor editor = (JSpinner.DefaultEditor)spreadingFactorSpinner.getEditor();
        editor.getTextField().setHorizontalAlignment(JTextField.CENTER);

        spreadingFactorPanel.add(spreadingFactorLabel);
        spreadingFactorPanel.add(spreadingFactorSpinner);

        JPanel mortalityFactorPanel = new JPanel();
        mortalityFactorPanel.setLayout(new BoxLayout(mortalityFactorPanel, BoxLayout.LINE_AXIS));
        mortalityFactorPanel.setBorder(new EmptyBorder(5,0,10,10));

        JLabel mortalityFactorLabel = new JLabel("Constant Mortality(Z): ");
        mortalityFactorLabel.setFont (mortalityFactorLabel.getFont().deriveFont (16f));

        mortalityFactorSpinner = new JSpinner(new SpinnerNumberModel(0.1,0.1,0.9,0.1));
        editor = (JSpinner.DefaultEditor)mortalityFactorSpinner.getEditor();
        editor.getTextField().setHorizontalAlignment(JTextField.CENTER);
        mortalityFactorPanel.add(mortalityFactorLabel);
        mortalityFactorPanel.add(mortalityFactorSpinner);

        JPanel spinnerPanel = new JPanel();
        spinnerPanel.setLayout(new BoxLayout(spinnerPanel,BoxLayout.LINE_AXIS));
        spinnerPanel.add(spreadingFactorPanel);
        spinnerPanel.add(mortalityFactorPanel);

        JButton plotButton = new JButton("Show Plot");
        plotButton.setEnabled(false);
        plotButton.addActionListener(e->{
            plotWindow.openPlot();
        });

        Icon pauseIcon = new ImageIcon(getClass().getResource("/Icons/baseline_pause_black_18dp.png"));
        JButton pauseButton = new JButton(pauseIcon);
        Icon playIcon = new ImageIcon(getClass().getResource("/Icons/baseline_play_arrow_black_18dp.png"));
        JButton playButton = new JButton(playIcon);

        pauseButton.setFocusPainted(false);
        pauseButton.addActionListener(e -> {
            isRunning = false;
            playButton.setEnabled(true);
            pauseButton.setEnabled(false);
        });
        pauseButton.setEnabled(false);

        playButton.setFocusPainted(false);
        playButton.addActionListener(e -> {
            if(spreadingFactor == 0){
                try {
                    spreadingFactorSpinner.commitEdit();
                    spreadingFactor = (double)spreadingFactorSpinner.getValue();
                    spreadingFactorSpinner.setEnabled(false);

                } catch (ParseException parseException) {
                    parseException.printStackTrace();
                }
            }
            if(constantMortalityRate == 0){
                try {
                    mortalityFactorSpinner.commitEdit();
                    constantMortalityRate = (double)mortalityFactorSpinner.getValue();
                    mortalityFactorSpinner.setEnabled(false);

                } catch (ParseException parseException) {
                    parseException.printStackTrace();
                }
            }
            pauseButton.setEnabled(true);
            plotButton.setEnabled(true);
            playButton.setEnabled(false);
            startSimulation();
        });


        JSpinner addHumanCountSpinner = new JSpinner(new SpinnerNumberModel(0,0,1000,1));
        editor = (JSpinner.DefaultEditor)addHumanCountSpinner.getEditor();
        editor.getTextField().setHorizontalAlignment(JTextField.CENTER);

        JButton addHumanButton = new JButton("Add Human(s)");
        addHumanButton.addActionListener(e->{
            try {
                addHumanCountSpinner.commitEdit();
                int humanCount = (int)addHumanCountSpinner.getValue();
                if(humanCount == 1){
                    population.addHuman(humanFactory.createHuman());
                    populationSize+=1;
                }
                else{
                    population.addHumanGroup(humanFactory.createHumanGroup(humanCount));
                    populationSize+=humanCount;
                }
                for(HumanViewModel humanViewModel : populationViewModel.getHumanViewModels()){
                    simulationPanel.remove(humanViewModel);
                }

                populationViewModel.updatePopulation(population);
                for(HumanViewModel humanViewModel : populationViewModel.getHumanViewModels()){
                    simulationPanel.add(humanViewModel);
                }

                simulationPanel.repaint();
                plotWindow.updatePopulationParameters(spreadingFactor,constantMortalityRate,population.getMaskUsagePercentage(),population.getAvgSocialDistance());

            } catch (ParseException parseException) {
                parseException.printStackTrace();
            }


        });

        JPanel buttonPanel = new JPanel();
        GridLayout layout = new GridLayout(2,3);
        layout.setHgap(20);
        layout.setVgap(10);
        buttonPanel.setLayout(layout);

        buttonPanel.add(playButton);
        buttonPanel.add(pauseButton);
        buttonPanel.add(plotButton);
        JLabel constraintLabel = new JLabel("(Between 1-1000)");
        constraintLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        buttonPanel.add(constraintLabel);
        buttonPanel.add(addHumanCountSpinner);
        buttonPanel.add(addHumanButton);

        JPanel controlPanel = new JPanel(new GridLayout(2,1));
        GridLayout cpLayout = new GridLayout(2,1);
        controlPanel.setLayout(cpLayout);

        controlPanel.setBorder(new EmptyBorder(10,10,10,10));
        controlPanel.add(spinnerPanel);
        controlPanel.add(buttonPanel);

        return controlPanel;
    }

    /**
     * Increases the total infected count
     */
    public void increaseInfectedCount(){
        infectedCount++;
    }

    /**
     * Starts a simulation
     */
    private void startSimulation(){
        if(timeElapsed == 0){
            population = new Population();
            try {
                initialHumanCountSpinner.commitEdit();
                populationSize = (int)initialHumanCountSpinner.getValue();
                initialPopulationSize = (int)initialHumanCountSpinner.getValue();
                population.addHumanGroup(humanFactory.createHumanGroup(populationSize));
                populationViewModel = new PopulationViewModel(population);
                Hospital.getInstance().initialize(initialPopulationSize/100);

                for(HumanViewModel humanViewModel : populationViewModel.getHumanViewModels()){
                    simulationPanel.add(humanViewModel);
                }
                Timer timer = new Timer(tickPerMilliseconds, new EpidemicActionListener(this));
                timer.start();

            } catch (ParseException e) {
                e.printStackTrace();
            }

            infectRandomHuman();
            plotWindow.setPopulationParameters(spreadingFactor,constantMortalityRate,population.getMaskUsagePercentage(), population.getAvgSocialDistance());
        }
        isRunning = true;
    }

    /**
     * Updates the simulation
     */
    private void onTick() {

        updateHumans();
        collisionMediator.checkCollisions();

        for(HumanViewModel humanViewModel : populationViewModel.getHumanViewModels()){
            humanViewModel.onTick();
        }

        if(timeElapsed % 1000 == 0){
            plotWindow.onTick(timeElapsed/1000, infectedCount, deadCount);
        }

        updateLabels();
        this.timeElapsed += this.tickPerMilliseconds;
    }

    /**
     * Infects a random human in the population
     */
    private void infectRandomHuman()
    {
        Human firstInfected = population.infectRandomHuman();
        double secondsToKill = 100 * (1 - constantMortalityRate);
        firstInfected.startCountdownAfterInfection(25, (int)secondsToKill);
        infectedCount++;
    }

    /**
     * Updates all humans in the simulation
     */
    private void updateHumans()
    {
        java.util.List<Human> humans = population.getHumans();

        for(int i = 0; i < humans.size(); i++){
            humans.get(i).onTick(this.tickPerMilliseconds);
            if(humans.get(i).isHospitalized() && humans.get(i).getTimeInHospital() == tickPerMilliseconds){
                hospitalizedCount++;
            }
            if(humans.get(i).isDead()){
                HumanViewModel viewToRemove = populationViewModel.getWithHuman(humans.get(i));
                populationViewModel.getHumanViewModels().remove(viewToRemove);
                simulationPanel.remove(viewToRemove);
                deadCount++;
                population.removeHuman(humans.get(i));
            }
        }
    }

    /**
     * Updates the labels in the simulation
     */
    private void updateLabels()
    {
        Date date = new Date(timeElapsed);
        DateFormat formatter = new SimpleDateFormat("HH:mm:ss");
        formatter.setTimeZone(TimeZone.getTimeZone("UTC"));
        String dateFormatted = formatter.format(date);
        timerLabel.setText("Timer: " + dateFormatted);
        totalInfectionCasesLabel.setText("Total Cases: " + infectedCount);
        healthyLabel.setText("Healthy: " + population.getHealthyCount() + "/" + populationSize);
        hospitalizedLabel.setText("Total Hospitalized Cases: " + hospitalizedCount);
        deadLabel.setText("Dead: " + deadCount + "/" + populationSize);
        currentInfectedCountLabel.setText("Infected: " + population.getInfectedCount() + "/" + populationSize);
        currentHospitalizedCountLabel.setText("Hospitalized: " + population.getHospitalizedCount() + "/" + initialPopulationSize/100);

    }
}
