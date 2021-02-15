package Q2;

/**
 * This interface defines the old payment method turbo payment to payments.
 * @author Gokce Nur Erer
 */
public interface TurboPayment {
    /**
     * Executes a payment operation with given parameters
     * @param turboCardNo Card Number
     * @param turboAmount Amount
     * @param destinationTurboOfCourse Destination of the payment
     * @param installmentsButInTurbo Installments of the payment
     * @return Payment result 1 if successful 0 if not
     */
    public int payInTurbo(String turboCardNo, float turboAmount, String destinationTurboOfCourse, String installmentsButInTurbo);
}
