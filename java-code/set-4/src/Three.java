// WAP to print all prime numbers in given range
import java.util.Scanner;
public class Three {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int range;
        try {
            System.out.print("Enter range : ");
            range = in.nextInt();
            if (range < 1 || range  > 1000) {
                System.out.println("BEYOND RANGE!![1~1000]");
                return;
            }

            System.out.print("Prime numbers -> ");
            for (int i = 1; i <= range ; i++){
                if (checkPrime(i)) System.out.print(" " + i);
            } System.out.println("");
        } catch (Exception e){
            System.out.println("Exception caught!!");
        } finally {
            System.out.println("[PROGRAM EXITED]");
            in.close();
        }
    }

    static boolean checkPrime(int x){
        for (int i = 2; i*i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }
}

// Output
// Enter range : 100
// Prime numbers ->  1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
// [PROGRAM EXITED]

// Output
// Enter range : -100
// BEYOND RANGE!![1~1000]
// [PROGRAM EXITED]
