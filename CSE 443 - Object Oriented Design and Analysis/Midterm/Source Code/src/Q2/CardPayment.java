package Q2;

/**
 * This class is an implementation of the interface ModernPayment
 * @author Gokce Nur Erer
 */
public class CardPayment implements ModernPayment {
    /**
     * Executes a payment operation with given parameters
     * @param cardNo Card Number
     * @param amount Amount
     * @param destination Destination of the payment
     * @param installments Installments of the payment
     * @return Payment result 1 if successful 0 if not
     */
    @Override
    public int pay(String cardNo, float amount, String destination, String installments) {
        System.out.println("Payment by using the method in Modern Payment interface...");
        return 1;
    }
}
