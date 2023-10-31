import java.util.Scanner;

public class CheckPrime {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter an integer : ");
        int num = in.nextInt();
        if (num == 0){
            System.out.println("Cannot be determined");
            return;
        } else if (num < 0) {
            System.out.println(num + " is not prime");
            return;
        }

        for (int i = 2; i * i <= num; i++){
            if(num % i == 0) {
                System.out.println(num + " is not prime");
                return;
            }
        }
        System.out.println(num + " is prime");
    }
}
