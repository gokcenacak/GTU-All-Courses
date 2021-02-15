package Q2;

/**
 * This interface defines a modern payment method to payments.
 * @author Gokce Nur Erer
 */
public interface ModernPayment {
    /**
     * Executes a payment operation with given parameters
     * @param cardNo Card Number
     * @param amount Amount
     * @param destination Destination of the payment
     * @param installments Installments of the payment
     * @return Payment result 1 if successful 0 if not
     */
    public int pay(String cardNo, float amount, String destination, String installments);
}
