package Question1;

/**
 * Implementation of matrix inversion strategy for solving linear equations.
 * @author Gokce Nur Erer
 */
public class MatrixInversionStrategy implements ILinearSolverStrategy {
    /**
     * Implementation of getting cofactors of an matrix with a given row and column
     * @param matrix Matrix whose cofactors will be calculated
     * @param givenRow Row of the element the cofactor will be calculated
     * @param givenColumn Column of the element which cofactor will be calculated
     * @return Cofactors of the given matrix
     */
    private double[][] getCofactor(double [][] matrix, int givenRow, int givenColumn)
    {
        int i = 0, j = 0;

        double [][] cofactor = new double[matrix.length][matrix.length];

        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix.length; col++) {
                if (row != givenRow && col != givenColumn) {
                    cofactor[i][j++] = matrix[row][col];

                    if (j == matrix.length - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        return cofactor;
    }

    /**
     * Implementation of getting adjoint of a matrix
     * @param matrix Matrix whose adjoint will be calculated
     * @return The adjoint of the matrix
     */
    private double[][] getAdjoint(double [][] matrix)
    {
        double [][] adj = new double[matrix.length][matrix.length];

        if (matrix.length == 1) {
            adj[0][0] = 1;
            return adj;
        }

        double [][]cofactors;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                //Getting cofactors of the matrix
                cofactors = getCofactor(matrix, i, j);
                //Sign of adj[j][i] is positive if sum of row and column indexes is even. Else it is negative.
                int sign = ((i + j) % 2 == 0)? 1: -1;
                // Getting the transpose of the cofactor matrix
                adj[j][i] = (sign)*(calculateDeterminant(cofactors, matrix.length-1));
            }
        }
        return adj;
    }

    /**
     * Implementation of determinant of a matrix calculation
     * @param matrix Matrix whose determinant will be calculated
     * @param size Size of the matrix
     * @return The determinant of the given matrix
     */
    private double calculateDeterminant(double [][]matrix, int size)
    {
        int det = 0;
        double [][]cofactors;

        if (size == 1) {
            return matrix[0][0];
        }

        int sign = 1;

        for (int f = 0; f < size; f++) {
            cofactors = getCofactor(matrix, 0, f);
            det += sign * matrix[0][f] * calculateDeterminant(cofactors, size - 1);

            sign = -sign;
        }

        return det;
    }

    /**
     *
     * @param matrix Matrix to be inverted
     * @param inverse Matrix who will be filled to represent the inverse of the given matrix
     */
    private void invertMatrix(double [][] matrix, double [][] inverse)
    {
        // Find determinant of matrix[][]
        double det = calculateDeterminant(matrix, matrix.length);

        //Check if the matrix has a inverse
        if (det == 0)
        {
            System.out.print("Singular matrix, can't find its inverse");
            return;
        }

        // Finding inverse by using the formula of inverse(A) = adjoint(A)/determinant(A)
        double [][]adj = getAdjoint(matrix);
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix.length; j++)
                inverse[i][j] = adj[i][j]/det;

    }

    /**
     * Solves an equation system with given coefficents and equation results.
     * @param coefficents Coefficents of the variables in the equations.
     * @param results Results of the equations.
     * @return An array of double numbers which contains the solution of the equation.
     */
    @Override
    public double[] solve(double[][] coefficents, double[] results) {
        double sum;

        double[] res = new double[coefficents.length];
        double[][] inverted = new double[coefficents.length][coefficents.length];
        invertMatrix(coefficents,inverted);

        for (int i = 0; i < coefficents.length; ++i) {
            sum = 0.0;
            for (int j = 0; j < coefficents.length; ++j) {
                sum += inverted[i][j]*results[j];
            }
            res[i] = sum;
        }
        return res;
    }
}
