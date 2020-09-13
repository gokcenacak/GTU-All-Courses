/**Graph class represents the data structure Graph with a boolean adjancency matrix.
 * @author Gokce Nur Erer
 */
public class Graph {
    private boolean [][] adjacencyMatrix;
    /**Constructs an Graph with a inner adjacency matrix with sizes vertexNum, vertexNum
     * @param vertexNum the vertex number
     * */
    public Graph(int vertexNum){
        adjacencyMatrix = new boolean[vertexNum][vertexNum];
    }
    /**Constructs an empty Graph*/
    public Graph(){
        //Intentionally empty
    }
    /**Inserts the edge to the adjacency matrix also checks for transitivity
     * @param source The source element of the edge.
     * @param destination The destination element of the edge.
     * */
    public void insert(int source , int destination){
        adjacencyMatrix[source-1][destination-1] = true;
        for(int i = 0 ; i < adjacencyMatrix.length ; i++){
            checkTransitivity(i);
        }
    }
    /**Checks if the elements have transitivity relation
     * @param source The source element which will be checked for transitivity relation.
     * */
    private void checkTransitivity(int source){
        for(int i = 0 ; i < adjacencyMatrix.length ; i++){
            if(adjacencyMatrix[i][source]){
                for(int j = 0 ; j < adjacencyMatrix[i].length ; j++){
                    if(adjacencyMatrix[source][j] && i!=j){
                        adjacencyMatrix[i][j] = true;
                    }
                }
            }
        }
    }
    /**Prints the adjacency matrix of the graph*/
    public void printGraph(){
        for(int i = 1 ; i<=adjacencyMatrix.length ; i++) {
            System.out.print("\t  "+i + "\t");
        }
        System.out.println();
        for(int i = 0 ; i < adjacencyMatrix.length ; i++){
            System.out.print((i+1) + "\t");
            for(int j = 0 ; j<adjacencyMatrix[i].length ; j++){
                System.out.print(adjacencyMatrix[i][j] + "\t");
            }
            System.out.println();
        }

    }
    /**Finds the number of people who are considered popular by every
     other person.*/
    public int findPopular(){
        int[] popularity = new int[adjacencyMatrix.length];
        int count = 0;
        for(int i = 0 ; i < adjacencyMatrix.length ; i++){
            for(int j = 0 ; j < adjacencyMatrix[i].length ; j++){
                if(adjacencyMatrix[i][j] && i!=j){
                    popularity[j]++;
                }
            }
        }
        for(int i = 0 ; i < popularity.length ; i++){
            if(popularity[i] == adjacencyMatrix.length-1){
                count++;
            }
        }
        System.out.println();
        return count;
    }
}
