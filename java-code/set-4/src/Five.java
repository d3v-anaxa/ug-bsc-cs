// WAP that returns account number, name, and balance of 10 customers with balance under 1000.
import java.util.*;
public class Five {
    public static void main(String[] args){
        final int SIZE = 10;
        Customer[] list = new Customer[SIZE];

        for (int i = 0; i < SIZE; i++){
            list[i] = new Customer();
        }

        for (Customer customer : list){
            if( customer.balance < 1000)
                System.out.println("Balance below 1000! -> " + customer.name + " | Acc. No. " + customer.accNo + " | Rs. " + customer.balance);
        }
    }
}

class Customer {
    long accNo;
    String name;
    long balance;

    Customer() {
        Scanner in = new Scanner(System.in);
        try {
            this.accNo = (int)(Math.random() * 100000000) + 100000000;
            System.out.print("ENTER NAME -> ");
            this.name = in.nextLine();
            System.out.print("ENTER BALANCE -> ");
            this.balance = in.nextLong();
            System.out.println("[A/C no. " + this.accNo + "]");
        } catch (Exception e) { 
            System.out.println("Illegal input found!");
        }
    }
}

// Output
//ENTER NAME -> Georgie
// ENTER BALANCE -> 100
// [A/C no. 152984561]
// ENTER NAME -> Alex
// ENTER BALANCE -> 500
// [A/C no. 185200990]
// Balance below 1000! -> Georgie | Acc. No. 152984561 | Rs. 100
// Balance below 1000! -> Alex | Acc. No. 185200990 | Rs. 500

// Output
// ENTER NAME -> Miles
// ENTER BALANCE -> Morals
// Illegal input found!
// ENTER NAME -> Gwen
// ENTER BALANCE -> 200
// [A/C no. 157267908]
// Balance below 1000! -> Miles | Acc. No. 113665167 | Rs. 0
// Balance below 1000! -> Gwen | Acc. No. 157267908 | Rs. 200
