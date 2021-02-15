package Q2;

/**
 * This class represents the client which will do the payments
 * @author Gokce Nur Erer
 */
public class PaymentClient {
    /**
     * Method of the payment
     */
    private ModernPayment paymentMethod;

    /**
     * Constructor of PaymentClient
     * @param paymentMethod Payment method
     */
    public PaymentClient(ModernPayment paymentMethod){
        this.paymentMethod = paymentMethod;
    }

    /**
     * Executes a payment operation with given parameters
     * @param cardNo Card Number
     * @param amount Amount
     * @param destination Destination of the payment
     * @param installments Installments of the payment
     * @return Payment result 1 if successful 0 if not
     */
    public int pay(String cardNo, float amount, String destination, String installments){
        return paymentMethod.pay(cardNo, amount, destination, installments);
    }
}
