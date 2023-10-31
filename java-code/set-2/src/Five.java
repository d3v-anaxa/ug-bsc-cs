// WAP with class Length
// toFeet and toInch member functions
// and necessary constructors
import java.util.*;

public class Five {
    public static void main(String[] args){
        Length n1 = new Length();
        if (n1.inInch){
            n1.toFeet();
            n1.print();
        } else if (n1.inFeet){
            n1.toInch();
            n1.print();
        } else return;
    }
}

class Length {
    final static int Feet_Inch_Rel = 12;
    static double _length;
    static boolean inFeet = false, inInch = false;

    public Length(){
        Scanner in = new Scanner(System.in);
        boolean loop_switch = true;
        do {
            System.out.println("1. Length in inches.");
            System.out.println("2. Length in feet.");
            System.out.println("3. Exit.");
            System.out.print("Enter choice -> ");
            int choice = in.nextInt();
            switch (choice){
                case 1:
                    inInch = true;
                    System.out.print("Enter length in inches : ");
                    break;
                case 2:
                    inFeet = true;
                    System.out.print("Enter length in foot : ");
                    break;
                case 3:
                    loop_switch = false;
                    System.out.println("Exit!");
                default:
                    System.out.println("Invalid choice!");
                    continue;
            }
            _length = in.nextDouble();
            break;
        } while (loop_switch);
        in.close();    
    }

    public void toFeet (){
        if (inFeet) {
            System.out.println("Length already in Feet metric!");
            return;
        }
        inFeet = true;
        inInch = false;
        _length = _length / Feet_Inch_Rel;
        System.out.println("Converted from inches to feet!");
    }

    public void toInch (){
        if (inInch) {
            System.out.println("Length already in Inches metric!");
            return;
        }
        inFeet = false;
        inInch = true;
        _length = _length * Feet_Inch_Rel;
        System.out.println("Converted from feet to inches!");
    }
    
    public static void print(){

        System.out.print("Length -> ");
        System.out.print(_length + " ");
        System.out.println(inFeet ? "Ft(s)" : inInch ? "In(s)" : "");
    }
}

// Output
// 1. Length in inches.
// 2. Length in feet.
// 3. Exit.
// Enter choice -> 1
// Enter length in inches : 12
// Converted from inches to feet!
// Length -> 1.0 Ft(s)


// Output
// 1. Length in inches.
// 2. Length in feet.
// 3. Exit.
// Enter choice -> 2
// Enter length in foot : 192
// Converted from feet to inches!
// Length -> 2304.0 In(s)

// Output
// 1. Length in inches.
// 2. Length in feet.
// 3. Exit.
// Enter choice -> 3
// Exit!
// Invalid choice!
