import java.util.Scanner;
public class Factorial {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter an integer [ n > 0 ] : ");
        int num = in.nextInt();
        int factorial = 1;
        for ( int i = num ; i != 1; i--)
            factorial *= i;
        System.out.println("Factorial = " + factorial);
        return;
    }
}
