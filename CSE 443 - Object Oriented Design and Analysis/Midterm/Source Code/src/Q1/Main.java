package Q1;

public class Main {
    public static void main(String[] args) {
        System.out.println("---------- IFLAS TECHNOLOGIES TURKEY ----------\n");
        RegionalSmartphoneFactory turkeyFactory = new TurkeySmartphoneFactory();
        System.out.println("Creating \"Maximum Effort Model Phone\"...\n");
        System.out.println(turkeyFactory.getMaximumEffortPhone().toString());
        System.out.println("Creating \"Iflas Deluxe Model Phone\"...\n");
        System.out.println(turkeyFactory.getIflasDeluxePhone().toString());
        System.out.println("Creating \"I-I-Aman Model Phone\"...\n");
        System.out.println(turkeyFactory.getIIAmanIflasPhone().toString());

        System.out.println("---------- IFLAS TECHNOLOGIES EU ----------\n");
        RegionalSmartphoneFactory EUFactory = new EUSmartphoneFactory();
        System.out.println("Creating \"Maximum Effort Model Phone\"...\n");
        System.out.println(EUFactory.getMaximumEffortPhone().toString());
        System.out.println("Creating \"Iflas Deluxe Model Phone\"...\n");
        System.out.println(EUFactory.getIflasDeluxePhone().toString());
        System.out.println("Creating \"I-I-Aman Model Phone\"...\n");
        System.out.println(EUFactory.getIIAmanIflasPhone().toString());

        System.out.println("---------- IFLAS TECHNOLOGIES GLOBAL ----------\n");
        RegionalSmartphoneFactory globalFactory = new GlobalSmartphoneFactory();
        System.out.println("Creating \"Maximum Effort Model Phone\"...\n");
        System.out.println(globalFactory.getMaximumEffortPhone().toString());
        System.out.println("Creating \"Iflas Deluxe Model Phone\"...\n");
        System.out.println(globalFactory.getIflasDeluxePhone().toString());
        System.out.println("Creating \"I-I-Aman Model Phone\"...\n");
        System.out.println(globalFactory.getIIAmanIflasPhone().toString());
    }
}
