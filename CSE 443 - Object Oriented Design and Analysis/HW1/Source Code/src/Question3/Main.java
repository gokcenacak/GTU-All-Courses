package Question3;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Test equipment #1 with Ora suit having Laser and Flamethrower and Rocket Launcher add-ons");
        MilitaryEquipment testEq1 = new RocketLauncher(new Flamethrower(new Laser(new Ora())));
        System.out.println("Cost: " + testEq1.cost());
        System.out.println("Weight: " + testEq1.weight());
        System.out.println("-----------------------------------------");
        System.out.println("Test equipment #2 with Dec suit having Autorifle and Flamethrower add-ons");
        MilitaryEquipment testeq2 = new Flamethrower(new AutoRifle(new Dec()));
        System.out.println("Cost: " + testeq2.cost());
        System.out.println("Weight: " + testeq2.weight());
        System.out.println("-----------------------------------------");
        System.out.println("Test equipment #3 with Tor suit having Rocket Launcher and Laser add-ons");
        MilitaryEquipment testeq3 = new Laser(new RocketLauncher(new Tor()));
        System.out.println("Cost: " + testeq3.cost());
        System.out.println("Weight: " + testeq3.weight());
        System.out.println("-----------------------------------------");
    }

}
