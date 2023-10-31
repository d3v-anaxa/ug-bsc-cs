// WAP to calculate factorial by taking input using
// i. DataInputStream
// ii. BufferedReader
// iii. Scanner
import java.util.*;
import java.io.*;
public class Two {
    public static void main(String[] args){
        new Factorial();
    }
}

class Factorial {
    int num,
        factorial = 1;

    Factorial(){
        DataInputStream dis = new DataInputStream(System.in);
        BufferedReader bis =  new BufferedReader(new InputStreamReader(System.in));
        Scanner in = new Scanner(System.in);
        int choice;
        System.out.println("1. DataInputStream");
        System.out.println("2. BufferedReader");
        System.out.println("3. Scanner");
        System.out.println("4. EXIT!");
        System.out.print("Enter choice -> ");
        try {
            choice = in.nextInt();
            switch(choice){
                case 1:
                    System.out.print("Enter num [1~16] : ");
                    num = Integer.parseInt(dis.readLine());
                    break;
                case 2:
                    System.out.print("Enter num [1~16] : ");
                    num = Integer.parseInt(bis.readLine());
                    break;
                case 3:
                    System.out.print("Enter num [1~16] : ");
                    num = in.nextInt();
                    break;
                case  4:
                    return;
                default:
                    throw new Exception();
            }
            if (num < 1 || num > 16) {
                System.out.println("Input Beyond range!");
                return;
            }
            factorial = getFactorial(num);
            System.out.println("Factorial -> " + factorial);
        } catch (Exception e) {
            System.out.println("Exception caught!!");
        } finally {
            try {
                dis.close();
                bis.close();
                in.close();
            } catch (Exception e) { 
                System.out.println("Unable to close streams!");
            } finally {
                System.out.println("[PROGRAM EXITED]");
            }
        }

    }

    private static int getFactorial(int x){
        if (x == 0 || x == 1){
            return x;
        } else {
            return x * getFactorial(x - 1);
        }
    }
}

// Output 
// 1. DataInputStream
// 2. BufferReader
// 3. Scanner
// 4. EXIT!
// Enter choice -> 1
// Enter num [1~16] : 5
// Factorial -> 120
// [PROGRAM EXITED]

// Output 
// 1. DataInputStream
// 2. BufferReader
// 3. Scanner
// 4. EXIT!
// Enter choice -> 2
// Enter num [1~16] : 5
// Factorial -> 120
// [PROGRAM EXITED]

// Output 
// 1. DataInputStream
// 2. BufferReader
// 3. Scanner
// 4. EXIT!
// Enter choice -> 3
// Enter num [1~16] : 5
// Factorial -> 120
// [PROGRAM EXITED]

// Output 
// 1. DataInputStream
// 2. BufferReader
// 3. Scanner
// 4. EXIT!
// Enter choice -> 4
// [PROGRAM EXITED]


// Output 
// 1. DataInputStream
// 2. BufferReader
// 3. Scanner
// 4. EXIT!
// Enter choice -> 15
// Exception caught!!
// [PROGRAM EXITED]
