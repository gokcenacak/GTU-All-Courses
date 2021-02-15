import org.knowm.xchart.XChartPanel;
import org.knowm.xchart.XYChart;
import org.knowm.xchart.XYChartBuilder;
import org.knowm.xchart.XYSeries;
import org.knowm.xchart.style.Styler;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

/**
 * This class represents a graph window for the epidemic. This class uses a third-party library xchart for the visuals.
 * @author Gokce Nur Erer
 */
public class EpidemicGraphWindow {
    private XYChart chart;
    private JFrame frame;
    private JPanel populationParameterPanel;
    private ArrayList<Integer> timeValues;
    private ArrayList<Integer> infectedValues;
    private ArrayList<Integer> deathValues;
    private JLabel spreadingFactorLabel;
    private JLabel mortalityFactorLabel;
    private JLabel percentageOfMaskUsage;
    private JLabel avgOfSocialDistance;

    /**
     * Constructor which creates a graph window
     */
    public EpidemicGraphWindow(){
        chart = createChart();
        frame = new JFrame("Epidemic Status Plot");

        JPanel mainPanel = new JPanel();

        populationParameterPanel = new JPanel(new GridLayout(4,1));

        JPanel chartPanel = new JPanel();
        chartPanel.add(new XChartPanel<>(chart));

        mainPanel.add(chartPanel);
        mainPanel.add(populationParameterPanel);

        frame.add(mainPanel);
        frame.pack();
        frame.setSize(900, 750);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        timeValues = new ArrayList<>();
        infectedValues = new ArrayList<>();
        deathValues = new ArrayList<>();
        createPlotSeries("Dead Count");
        createPlotSeries("Infected Count");
    }

    /**
     * Creates a chart
     * @return Chart
     */
    private XYChart createChart(){
        XYChart chart = new XYChartBuilder().width(750).height(600).xAxisTitle("Time").yAxisTitle("Count").build();
        chart.getStyler().setLegendPosition(Styler.LegendPosition.InsideNW);
        chart.getStyler().setAxisTitlesVisible(true);
        chart.getStyler().setDefaultSeriesRenderStyle(XYSeries.XYSeriesRenderStyle.Step);
        chart.getStyler().setToolTipsEnabled(true);
        chart.getStyler().setLegendSeriesLineLength(10);
        return chart;
    }

    /**
     * Creates a plot series for the graph
     * @param seriesName Name for the series
     */
    private void createPlotSeries(String seriesName) {
        chart.addSeries(seriesName, new double[] {1}, new double[] {1});
    }

    /**
     * Shows the graph window.
     */
    public void openPlot(){
        frame.setVisible(true);
    }

    /**
     * Sets the population parameters in the graph to visualize
     * @param spreadingFactor Spreading factor in the population
     * @param mortalityRate Mortality rate of the disease
     * @param maskUsage Mask usage percentage in the population
     * @param avgSocialDistance Average social distance that is held in the population
     */
    public void setPopulationParameters(double spreadingFactor, double mortalityRate, double maskUsage, double avgSocialDistance ){
        spreadingFactorLabel = new JLabel("Spreading Factor = " + spreadingFactor);
        mortalityFactorLabel = new JLabel("Mortality Rate = " + mortalityRate);
        percentageOfMaskUsage = new JLabel("Percentage of Mask Use = " + maskUsage * 100 + "%");
        avgOfSocialDistance = new JLabel("Average Social Distance = " + avgSocialDistance);

        populationParameterPanel.add(spreadingFactorLabel);
        populationParameterPanel.add(mortalityFactorLabel);
        populationParameterPanel.add(percentageOfMaskUsage);
        populationParameterPanel.add(avgOfSocialDistance);

        populationParameterPanel.repaint();
        frame.repaint();
    }

    /**
     * Updates the graph values with given time and counts
     * @param currentTime Current time
     * @param infectedCount Infected count at that instant
     * @param deathCount Death count at that instant
     */
    public void onTick(int currentTime, int infectedCount, int deathCount){
        timeValues.add(currentTime);
        infectedValues.add(infectedCount);
        deathValues.add(deathCount);
        chart.updateXYSeries("Infected Count",timeValues,infectedValues,null);
        chart.updateXYSeries("Dead Count",timeValues,deathValues,null);
        frame.repaint();
    }
    /**
     * Updates population parameters in the graph to visualize
     * @param spreadingFactor Spreading factor in the population
     * @param mortalityRate Mortality rate of the disease
     * @param maskUsage Mask usage percentage in the population
     * @param avgSocialDistance Average social distance that is held in the population
     */
    public void updatePopulationParameters(double spreadingFactor, double mortalityRate, double maskUsage, double avgSocialDistance){
        spreadingFactorLabel.setText("Spreading Factor = " + spreadingFactor);
        mortalityFactorLabel.setText("Mortality Rate = " + mortalityRate);
        percentageOfMaskUsage.setText("Percentage of Mask Use = " + maskUsage * 100 + "%");
        avgOfSocialDistance.setText("Average Social Distance = " + avgSocialDistance);
        populationParameterPanel.repaint();
        frame.repaint();
    }
}
