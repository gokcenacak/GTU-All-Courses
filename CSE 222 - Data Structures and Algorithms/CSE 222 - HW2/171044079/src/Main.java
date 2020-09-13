import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        DateFormat dateFormat = new SimpleDateFormat("hh:mm:ss");
        Date date = new Date();
        String time=dateFormat.format(date);

        ExperimentList explist = new ExperimentList();
        Experiment exp1 = new Experiment("E1" , 1 , time , false , 1f );
        Experiment exp2 = new Experiment("E2" , 2 , time , true , 61.45f );
        Experiment exp3 = new Experiment("E3" , 2 , time , true , 53.45f );
        Experiment exp4 = new Experiment("E4" , 3 , time , true , 5.45f );
        Experiment exp5 = new Experiment("E5" , 4 , time , true , 54.45f );
        Experiment exp8 = new Experiment("E8", 3, time, true , 16.54f);

        Experiment exp6 = new Experiment("E6", 5, time, true , 16.54f);
        Experiment exp7 = new Experiment("E7", 4, time, true , 26.54f);
        Experiment exp9 = new Experiment("E9", 6, time, true , 1.54f);


        explist.addExp(exp1);
        explist.addExp(exp2);
        explist.addExp(exp3);
        explist.addExp(exp4);
        explist.addExp(exp8);
        explist.addExp(exp5);
        explist.addExp(exp6);
        System.out.println("---------------------CONSTRUCTING THE LIST---------------------");
        System.out.println(explist.toString());

        System.out.println("---------------------ADD TEST---------------------");
        explist.addExp(exp7);
        explist.addExp(exp9);
        System.out.println(explist.toString());

        System.out.println("---------------------GET EXP TEST---------------------");
        try {
            System.out.println(explist.getExp(3, 1));
            System.out.println("--Testing with wrong index--");
            System.out.println(explist.getExp(3, 9));
            System.out.println("--Testing with wrong day--");
            System.out.println(explist.getExp(9, 3));

        }
        catch(IndexOutOfBoundsException e){
            System.out.println("No such index");
        }
        catch(ArithmeticException e){
            System.out.println("No such day");
        }
        System.out.println("---------------------SET EXP TEST---------------------");

        try {
            explist.setExp(2,1,exp3);
            System.out.println(explist.toString());
            System.out.println("--Testing to set a experiment with a different day value to check exception handling--");
            explist.setExp(2, 1, exp6);
            System.out.println(explist.toString());
        }
        catch(ArithmeticException e){
            System.out.println("Mismatch of given experiment and chosen experiment\n");
        }
        catch(NullPointerException e){
            System.out.println("List is empty.");
        }
        System.out.println("---------------------REMOVE EXP TEST---------------------");
        try {
            explist.removeExp(5, 1);
            System.out.println(explist.toString());
            System.out.println("--Testing invalid day--");
            explist.removeExp(8, 1);
            System.out.println(explist.toString());

        }
        catch(IndexOutOfBoundsException e){
            System.out.println("Index or day mismatch");
        }
        catch(NullPointerException e){
            System.out.println("List is empty.");
        }
        System.out.println("---------------------LIST EXP TEST---------------------");
        try{
            explist.listExp(4);
            System.out.println("\n--Testing invalid day--");
            explist.listExp(8);
        }
        catch(ArithmeticException e){
            System.out.println("Invalid day");
        }
       catch(NullPointerException e){
           System.out.println("List is empty.");
       }
       try {
           System.out.println("---------------------REMOVE DAY TEST---------------------");
           explist.removeDay(3);
           System.out.println(explist.toString());
           System.out.println("--Testing with an invalid day--");
           explist.removeDay(5);
           System.out.println(explist.toString());
       }
       catch(ArithmeticException e){
           System.out.println("There is no such given day in the list.");
       }
       catch(NullPointerException e){
           System.out.println("List is empty.");
       }
       try {
            System.out.println("---------------------ORDER DAY TEST---------------------");
            explist.orderDay(2);
           System.out.println(explist.toString());
           System.out.println("--Testing with a invalid day--");
           explist.orderDay(8);
           System.out.println(explist.toString());
       }
       catch (NullPointerException e){
           System.out.println("List is empty.");
       }
       catch (IndexOutOfBoundsException e){
           System.out.println("There is no such day.");
       }
       System.out.println("---------------------ORDER EXPERIMENTS TEST---------------------");
       ExperimentListNode e = explist.orderExperiments();
       System.out.println(e.getExperiment().toString());

    }
}
