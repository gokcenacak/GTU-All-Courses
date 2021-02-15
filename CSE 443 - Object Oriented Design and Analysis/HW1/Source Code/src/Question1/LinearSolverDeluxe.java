package Question1;

/**
 * Implementation of a Linear equation solver class.
 * @author Gokce Nur Erer
 */
public class LinearSolverDeluxe {
    /**
     * Linear equation solving strategy
     */
    private ILinearSolverStrategy solutionStrategy;

    /**
     * Setter of the linear equation solving strategy
     * @param solutionStrategy A linear equation solving strategy
     */
    public void setSolutionStrategy(ILinearSolverStrategy solutionStrategy) {
        this.solutionStrategy = solutionStrategy;
    }

    /**
     * Getter for the linear equation solving strategy
     * @return The linear equation solving strategy that is assigned.
     */
    public ILinearSolverStrategy getSolutionStrategy(){
        return solutionStrategy;
    }
}
