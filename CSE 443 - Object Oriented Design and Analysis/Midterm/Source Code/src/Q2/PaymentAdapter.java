package Q2;

/**
 * This class is the adapter class which adapts TurboPayment interface to ModernPayment interface
 * @author Gokce Nur Erer
 */
public class PaymentAdapter implements ModernPayment {
    private TurboPayment payment;

    /**
     * Constructor for PaymentAdapter
     * @param payment Turbo payment to adapt
     */
    public PaymentAdapter(TurboPayment payment){
        this.payment = payment;
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
       return payment.payInTurbo(cardNo,amount,destination,installments);
    }
}
