package Question1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.util.ArrayList;


public class ApplicationWindow extends JFrame {
    private LinearSolverDeluxe linearSolver;

    private ArrayList<ArrayList<JTextField>> coefficients;
    private ArrayList<JTextField> results;

    public ApplicationWindow() {
        linearSolver = new LinearSolverDeluxe();

        setTitle("Linear Solver Deluxe");
        setResizable(false);

        coefficients = new ArrayList<>();
        results = new ArrayList<>();

        this.getContentPane().add((createWindow()));
        this.pack();
        this.setLocationRelativeTo(null);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private JPanel createWindow(){
        JPanel panel = new JPanel(); // the panel is not visible in output
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        // Top Panel
        JPanel topPanel = new JPanel();
        JLabel equationCountLabel = new JLabel("Enter equation count:");
        JTextField equationCount = new JTextField(5); // accepts upto 10 characters
        JLabel coeffCountLabel = new JLabel("Enter coefficient count:");
        JTextField coeffCount = new JTextField(5); // accepts upto 10 characters
        JButton equationAndCoefficientCountEnterButton = new JButton("Enter");
        topPanel.add(equationCountLabel); // Components Added using Flow Layout
        topPanel.add(equationCount);
        topPanel.add(coeffCountLabel);
        topPanel.add(coeffCount);
        topPanel.add(equationAndCoefficientCountEnterButton);
        topPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        panel.add(topPanel);

        JPanel equationsGridPanel = new JPanel(new GridLayout(1, 10));

        // Equation Panels
        ArrayList<JPanel> equationPanels = new ArrayList<>();
        ArrayList<JButton> coeffCountButtons = new ArrayList<>();

        equationAndCoefficientCountEnterButton.addActionListener(e->{
            equationAndCoefficientCountEnterButton.setEnabled(false);

            boolean isInputValid = true;

            try {
                if(Integer.parseInt(equationCount.getText())<= 0) {
                    throw new NumberFormatException();
                }
                if(Integer.parseInt(coeffCount.getText())<= 0) {
                    throw new NumberFormatException();
                }
            }
            catch (NumberFormatException ex) {
                isInputValid = false;
                JOptionPane.showMessageDialog(panel, "Invaild Number", "Error", JOptionPane.ERROR_MESSAGE);
            }

            if (!isInputValid) {
                equationAndCoefficientCountEnterButton.setEnabled(true);
                return;
            }

            for(int i = 0; i < Integer.parseInt(equationCount.getText());  i++){
                equationPanels.add(new JPanel());
                JPanel currentPanel = equationPanels.get(i);
                currentPanel.setLayout(new BoxLayout(currentPanel, BoxLayout.PAGE_AXIS));

                // Equation Header
                JPanel currentPanelHeaderPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
                JLabel equationLabel = new JLabel("Eq. #" + (i+1));
                currentPanelHeaderPanel.add(equationLabel);
                currentPanel.add(currentPanelHeaderPanel);

                coefficients.add(new ArrayList<>());
                ArrayList<JTextField> currentCoefficients = coefficients.get(i);

                // Coefficient Input Section
                for(int j = 0; j < Integer.parseInt(coeffCount.getText()) ; j++){
                    JLabel coefficientLabel = new JLabel("Coefficient #" + (j+1), SwingConstants.RIGHT);
                    JTextField coefficient = new JTextField(5);
                    JPanel coeffInputPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
                    coeffInputPanel.add(coefficientLabel); // Components Added using Flow Layout
                    coeffInputPanel.add(coefficient);
                    currentCoefficients.add(coefficient);
                    currentPanel.add(coeffInputPanel);
                }

                // Result Input Section
                JPanel resultInputPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
                JLabel resultCountLabel = new JLabel("Result:");
                JTextField resultCount = new JTextField(5); // accepts upto 10 characters
                resultInputPanel.add(resultCountLabel);
                resultInputPanel.add(resultCount);
                results.add(resultCount);
                currentPanel.add(resultInputPanel);

                revalidate();
                repaint();
                this.pack();

                equationsGridPanel.add(currentPanel);
            }

            panel.add(equationsGridPanel);

            JPanel calculationPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
            JButton calculateButton = new JButton("Calculate");
            JComboBox<String> equationMethodDropdown = new JComboBox<>();

            equationMethodDropdown.addItemListener(e3 -> {
                if (e3.getStateChange() == ItemEvent.SELECTED) {
                    int index = equationMethodDropdown.getSelectedIndex();
                    if (index == 0){
                        linearSolver.setSolutionStrategy(new GaussianEliminationStrategy());
                    }
                    else if (index == 1) {
                        linearSolver.setSolutionStrategy(new MatrixInversionStrategy());
                    }
                }
            });

            equationMethodDropdown.addItem("Gaussian Elimination");
            equationMethodDropdown.addItem("Matrix Inversion");

            calculateButton.addActionListener(e4 -> {
                boolean areCoeffsValid = validateCoefficients();
                boolean allCoeffCountsEntered = true;
                boolean areResultsValid = validateResults();

                for(JButton button : coeffCountButtons){
                    if(button.isEnabled()){
                        allCoeffCountsEntered = false;
                    }
                }
                if(!allCoeffCountsEntered){
                    JOptionPane.showMessageDialog(panel, "Please Enter Coefficients for All Equations!", "Error", JOptionPane.ERROR_MESSAGE);
                }
                else{
                    if (!areCoeffsValid)
                    {
                        JOptionPane.showMessageDialog(panel, "Invaild Coefficients", "Error", JOptionPane.ERROR_MESSAGE);
                    }
                    else {
                        if(!areResultsValid){
                            JOptionPane.showMessageDialog(panel, "Invaild Results", "Error", JOptionPane.ERROR_MESSAGE);
                        }
                        else{
                            double[][] coefficientArray = new double[Integer.parseInt(equationCount.getText())][Integer.parseInt(coeffCount.getText())];
                            double [] resultArray = new double[Integer.parseInt(equationCount.getText())];
                            int row = 0;

                            for (ArrayList<JTextField> coeffTextFields : coefficients)
                            {
                                int col = 0;
                                for (JTextField coeffTextField : coeffTextFields)
                                {
                                    coefficientArray[row][col] = Double.parseDouble(coeffTextField.getText());
                                    col++;
                                }
                                row++;
                            }
                            row = 0;
                            for(JTextField resTextField : results){
                                resultArray[row] = Double.parseDouble(resTextField.getText());
                                row++;

                            }
                            double [] solutions = linearSolver.getSolutionStrategy().solve(coefficientArray,resultArray);

                            StringBuilder builder = new StringBuilder();
                            for (int i = 0; i < solutions.length; i++) {
                                builder.append("Solution #").append(i + 1).append(": ").append(String.format("%.2f",solutions[i])).append("\n");
                            }
                            JOptionPane.showMessageDialog(panel, builder.toString(), "Solutions",JOptionPane.INFORMATION_MESSAGE);
                        }
                    }
                }

            });

            calculationPanel.add(equationMethodDropdown);
            calculationPanel.add(calculateButton);
            panel.add(calculationPanel);

            revalidate();
            repaint();
            this.pack();
        });

        revalidate();
        repaint();
        this.pack();
        return panel;
    }

    private boolean validateCoefficients() {
        boolean result = true;

        for (ArrayList<JTextField> coeffs : coefficients) {
            for (JTextField coeff : coeffs) {
                try {
                    Integer.parseInt(coeff.getText());
                }
                catch (NumberFormatException ex) {
                    result = false;
                }
            }
        }

        return result;
    }
    private boolean validateResults() {
        boolean result = true;

        for (JTextField res : results) {
            try {
                Integer.parseInt(res.getText());
            }
            catch (NumberFormatException ex) {
                result = false;
            }

        }

        return result;
    }



}
