// Demonstrate hierarchial inheritance

import java.util.*;
public class Six {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("1. Car");
        System.out.println("2. Bike");
        System.out.println("3. Exit");
        System.out.print("Enter choice -> ");
        try {
            switch (in.nextInt()){
                case 1:
                    new Car().info();
                    break;
                case 2:
                    new Bike().info();
                    break;
                default:
                    return;
            }
        } catch (Exception e) {
            System.out.println("Illegal input found");
        } finally {
            System.out.println("[PROGRAM EXITED]");
            in.close();
        }
    }
}

class Vehicle {
    int tyres, gear;
    String type = "UNKNOWN", name;

    Vehicle (String type, int tyres){
        Scanner in = new Scanner(System.in);
        try {
            this.type = type;
            this.tyres = tyres;
            System.out.print("Enter name -> ");
            this.name = in.nextLine();
            System.out.print("Number of gears -> ");
            this.gear = in.nextInt();
        } catch (Exception e) {
            System.out.print("Exception caught!");
        }
            
    }

    void info(){
        System.out.println("Name -> " + this.name + " [" + this.type + "]");
        System.out.println("No. of tyres -> " + this.tyres);
        System.out.println("No. of gear(s) -> " + this.gear);
    }
}

class Car extends Vehicle {
    Car(){
        super("Car", 4);
    }
}

class Bike extends Vehicle {
    Bike(){
        super("Bike", 2);
    }
}

// CHART
//           Vehicle [PARENT]
//              /     \
//             /       \
//      Car[child]   Bike[child]
//


// Output
// 1. Car
// 2. Bike
// 3. Exit
// Enter choice -> 1
// Enter name -> Honda i20
// Number of gears -> 5
// Name -> Honda i20 [Car]
// No. of tyres -> 4
// No. of gear(s) -> 5
// [PROGRAM EXITED]

// Output
// 1. Car
// 2. Bike
// 3. Exit
// Enter choice -> 3
// [PROGRAM EXITED]
