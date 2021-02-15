package Q2;

/**
 * This class is an implementation for TurboPayment interface
 * @author Gokce Nur Erer
 */
public class OldCardPayment implements TurboPayment{
    /**
     * Executes a payment operation with given parameters
     * @param turboCardNo Card Number
     * @param turboAmount Amount
     * @param destinationTurboOfCourse Destination of the payment
     * @param installmentsButInTurbo Installments of the payment
     * @return Payment result 1 if successful 0 if not
     */
    @Override
    public int payInTurbo(String turboCardNo, float turboAmount, String destinationTurboOfCourse, String installmentsButInTurbo) {
        System.out.println("Payment by using the method in Turbo Payment interface...");
        return 1;
    }
}
