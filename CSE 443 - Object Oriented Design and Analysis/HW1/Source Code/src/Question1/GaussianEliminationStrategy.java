package Question1;

/**
 * Implementation of gaussian elimination strategy for solving linear equations.
 * @author Gokce Nur Erer
 */
public class GaussianEliminationStrategy implements ILinearSolverStrategy {

    /**
     * Implementation of forward substitution method
     * @param coefficents Coefficents of the variables in the equations.
     * @param results Results of the equations.
     * @return If the forward substitution can be done it returns false which indicates the coefficient matrix is not singular, else it returns true which indicated the coefficient matrix is singular.
     */
    private boolean forwardSubstitution(double[][] coefficents, double[] results){
        for(int k = 0; k < results.length; k++) {
            int max = k;
            //Looking for a pivot
            for (int i = k + 1; i < results.length; i++) {
                if (Math.abs(coefficents[i][k]) > Math.abs(coefficents[max][k])) {
                    max = i;
                }
            }
            //If a diagonal element is 0 it denotes that the matrix is singular
            if (Math.abs(coefficents[k][k]) <= 0) {
                System.err.println("Matrix is singular or nearly singular");
                return true;
            }
            //Swapping rows
            double[] coeffTemp = coefficents[k];
            coefficents[k] = coefficents[max];
            coefficents[max] = coeffTemp;

            double resTemp = results[k];
            results[k] = results[max];
            results[max] = resTemp;

            for(int i = k + 1; i < results.length; i++){
                double alpha = coefficents[i][k] / coefficents[k][k];
                results[i] -= alpha * results[k];
                for(int j = k; j < results.length; j++){
                    coefficents[i][j] -= alpha * coefficents[k][j];
                }
            }
        }
        return false;
    }

    /**
     * Implementation of backward substitution method
     * @param coefficents Coefficents of the variables in the equations.
     * @param results Results of the equations.
     * @return An array of double numbers which contains the solutions of the equation.
     */
    private double [] backwardSubstitution(double[][] coefficents, double[] results){
        double [] solutionArray = new double[results.length];
        for(int i = results.length - 1; i >= 0; i--){
            double sum = 0.0;
            for(int j = i + 1; j < results.length ; j++){
                sum+=coefficents[i][j] * solutionArray[j];
            }
            solutionArray[i] = (results[i] - sum) /  coefficents[i][i];
        }
        return solutionArray;
    }

    /**
     * Solves an equation system with given coefficents and equation results.
     * @param coefficents Coefficents of the variables in the equations.
     * @param results Results of the equations.
     * @return An array of double numbers which contains the solution of the equation.
     */
    @Override
    public double[] solve(double[][] coefficents, double[] results) {
        boolean isSingular = forwardSubstitution(coefficents,results);
        if(isSingular){
            return null;
        }
        else{
            return backwardSubstitution(coefficents,results);
        }
    }
}
