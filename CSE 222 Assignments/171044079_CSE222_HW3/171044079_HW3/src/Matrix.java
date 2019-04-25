import java.io.*;
import java.util.Scanner;
/**The Matrix class represents matrices which has to be read from a file*/
public class Matrix {
    private char matrix[][];
    /**Constructs a Matrix by reading a matrix from a file by getting the file name from the
     * user.*/
    public Matrix(){
        BufferedReader reader;
        try{
            System.out.println("Enter the file name:");
            Scanner scan = new Scanner(System.in);
            String fileName = scan.next();
            reader = new BufferedReader(new FileReader(fileName));
            StringBuilder line = new StringBuilder();
            String temp;
            while((temp = reader.readLine()) != null){
                line.append(temp);
                line.append("\n");
            }
            String[] rows = line.toString().split("\n");
            int columnCount = (rows[0].length()/2)+1;

            String[][] arr = new String[rows.length][columnCount];
            for(int i = 0 ; i<rows.length ; ++i){
                arr[i] = rows[i].split(" ");
            }

            matrix = new char[rows.length][columnCount];
            for(int i = 0 ; i<rows.length ; ++i){
                for(int j = 0 ; j<columnCount ; ++j){
                    matrix[i][j] = arr[i][j].charAt(0);
                }
            }

        }
        catch(IOException e){
            System.out.println("There is a problem with the file/reading from file.");
        }
    }
    /**Inner class Coordinate which represents x,y coordinates of the matrix*/
    private class Coordinate {
        int x;
        int y;

        public Coordinate(int x_entry, int y_entry) {
            x = x_entry;
            y = y_entry;
        }
    }
    /**Prints the matrix to the screen*/
    public void printting() {
        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[i].length; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
    /**Finds the white component's number represented by 1s in the matrix
     * @return white component count
     */
    public int whiteComponentFounder() {

        Stack<Coordinate> stack = new Stack<>();
        int total = 0;
        char mark = 'A';
        for(int i = 0 ; i < matrix.length ; ++i){
            for(int j = 0 ; j < matrix[i].length ; ++j){
                if(matrix[i][j] == '1'){
                   Coordinate coor = new Coordinate(i, j);
                   stack.push(coor);
                   matrix[i][j] = mark;

                   while(!stack.empty()) {
                        int x = stack.peek().x;
                        int y = stack.peek().y;
                        //Check for right
                        if (y + 1 < matrix[x].length && matrix[x][y + 1] == '1') {
                          matrix[x][y + 1] = mark;
                          Coordinate rightCoor = new Coordinate(x, y+1);
                          stack.push(rightCoor);

                        }
                        //Check for left
                        else if(y - 1 >= 0 && matrix[x][y - 1] == '1'){
                           matrix[x][y - 1] = mark;
                           Coordinate leftCoor = new Coordinate(x, y-1);
                           stack.push(leftCoor);

                        }
                        //Check for bottom
                        else if (x + 1 < matrix.length && matrix[x + 1][y] == '1') {
                            matrix[x + 1][y] = mark;
                            Coordinate bottomCoor = new Coordinate(x+1, y);
                            stack.push(bottomCoor);

                        }
                        //Check for top
                        else if (x - 1 >= 0 && matrix[x - 1][y] == '1') {
                            matrix[x - 1][y] = mark;
                            Coordinate topCoor = new Coordinate(x-1, y);
                            stack.push(topCoor);
                        }
                        else{
                            stack.pop();
                        }

                   }
                   mark++;
                   total++ ;
                }
            }
       }
       return total;
    }
}


