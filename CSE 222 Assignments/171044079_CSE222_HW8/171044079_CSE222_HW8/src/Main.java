import java.io.*;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Graph g = new Graph();
        File file = new File("input.txt");
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line;
            String[] arr;
            int vertexNum,relationNum,count=0;
            try {
                line = br.readLine();
                arr = line.split(" ");
                vertexNum = Integer.parseInt(arr[0]);
                relationNum = Integer.parseInt(arr[1]);
                g = new Graph(vertexNum);
                while(count!=relationNum){
                    line = br.readLine();
                    arr = line.split(" ");
                    g.insert(Integer.parseInt(arr[0]),Integer.parseInt(arr[1]));
                    count++;
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("The number of people who are considered popular by every other person:" + g.findPopular());
        System.out.println("Enter 1 to check the adjacency matrix:");
        Scanner scan = new Scanner(System.in);
        try {
            int choice = scan.nextInt();
            if(choice == 1) {
                g.printGraph();
            }
        }
        catch(InputMismatchException e){
            System.exit(0);
        }


    }
}
