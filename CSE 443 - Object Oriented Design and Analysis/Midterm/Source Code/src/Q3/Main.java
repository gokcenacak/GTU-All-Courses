package Q3;

public class Main {
    public static void main(String[] args) {
        Database db = new Database("BankDatabase");
        db.addTable("Transactions");
        db.addTable("Customers");
        db.addTable("Accounts");
        db.addColumnToTable("Transactions", "Sender Name");
        db.addColumnToTable("Transactions", "Reciever Name");
        db.addColumnToTable("Transactions", "Amount");
        db.addColumnToTable("Customers", "Name");
        db.addColumnToTable("Customers", "Surname");
        db.addColumnToTable("Accounts" , "Account Number");
        db.addColumnToTable("Accounts", "Account Type");

        DatabaseEngine dbEngine = new DatabaseEngine();
        System.out.println("Starting a transaction with 2 selects 1 update and 1 alter... ");
        dbEngine.select(db, "Transactions", "Sender Name", "");
        dbEngine.select(db, "Customers", "Name", "");
        dbEngine.update(db, "Customers", "Name", "where name = Matt");
        dbEngine.alter(db, "Accounts", "Account Number", "where Account Number = 012451-546521");
        System.out.println("Printing all successful operations...");
        dbEngine.printSuccessfulOperations();
        System.out.println("Applying a operation that will fail... ");
        dbEngine.select(db, "Transactions", "Customer ID", "");
        System.out.println("Printing all successful operations...");
        dbEngine.printSuccessfulOperations();


    }
}
