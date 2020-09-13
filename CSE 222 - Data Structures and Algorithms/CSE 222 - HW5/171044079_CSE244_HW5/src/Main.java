import java.awt.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Enter image path to be processed:");
        Scanner scan = new Scanner(System.in);
        String str = scan.next();
        ImageProcessor image = new ImageProcessor(str);
    }
}
