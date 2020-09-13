public class Main {
    public static void main(String[] args) {
        System.out.println("PART 1 - COUNTING COMPONENTS");
        Matrix m = new Matrix();
        System.out.println("Component Map:");
        m.printting();
        System.out.println("The number of the white components are:" + m.whiteComponentFounder());
        System.out.println("PART 2 - A CALCULATOR");
        Calculator c = new Calculator();
        System.out.println("The Postfix Notation is: " + c.infixToPostfix());
        System.out.println("Evaluated value is : " + c.calculate());

    }
}
