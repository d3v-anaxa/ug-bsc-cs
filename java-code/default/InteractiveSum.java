import java.util.Scanner;

public class
InteractiveSum {
    public static void main(String[] args) {
        if(args.length != 1){
            System.out.println("Invalid argument");
            return;
        }
        int sum = 0;
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < Integer.parseInt(args[0]); i++ ){
            System.out.print("Enter Intger-" + (i + 1) + " : ");
            sum += Integer.parseInt(in.next());

        }
        System.out.println("Sum = " + sum);
    }
}
