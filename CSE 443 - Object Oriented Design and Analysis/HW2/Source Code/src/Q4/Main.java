package Q4;

public class Main {

    public static void main(String[] args) {
        ITable table = new DatabaseTableProxy(new DatabaseTable(3,5));

        table.setElementAt(0,0,"Apples");
        table.setElementAt(0,1,"Brown");
        table.setElementAt(1,2,"Happy");
        table.setElementAt(2,4,"Sad");
        table.setElementAt(1,1,"Crying");

        Thread t = new Thread(() -> {
            while(true){
                System.out.println(table.getElementAt(0,0));
            }

        }, "thread1");
        Thread t2 = new Thread(() -> {
            while(true){
                table.setElementAt(0,0, "Thread2ChangedThis");
            }

        }, "thread2");
        Thread t3 = new Thread(() -> {
            while(true){
                table.setElementAt(0,0, "Thread3ChangedThis");
            }

        }, "thread3");

        t.start();
        t2.start();
        t3.start();


    }
}
