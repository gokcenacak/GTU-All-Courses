package Q2;

public class Main {
    public static void main(String[] args) {
        System.out.println("---Client using the implementation of Turbo Payment for payment, adapter is used for compatibility---");
        OldCardPayment payment = new OldCardPayment();
        PaymentClient client = new PaymentClient(new PaymentAdapter(payment));
        client.pay("1111111", 500, "222-2245145-2124", "5");

        System.out.println("---Client using the implementation of Modern Payment for payment---");

        CardPayment modernPayment = new CardPayment();
        client = new PaymentClient(modernPayment);
        client.pay("1111111", 500, "222-2245145-2124", "5");
    }

}
