package Question1;

/**
 * Base class which represents the linear equation solving strategies.
 * @author Gokce Nur Erer
 */
public interface ILinearSolverStrategy {
    /**
     * Solves an equation system with given coefficents and equation results.
     * @param coefficents Coefficents of the variables in the equations.
     * @param results Results of the equations.
     * @return An array of double numbers which contains the solution of the equation.
     */
    double[] solve(double[][] coefficents, double[] results);
}
