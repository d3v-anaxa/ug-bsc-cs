import java.math.BigInteger;
import java.util.Scanner;

public class DecimalToBinary {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a decimal Integer : ");
        int num = in.nextInt();
        String bin = Integer.toBinaryString(num);
        System.out.println("Binary : " + bin);
    }
}
