import java.util.Arrays;
import java.util.Scanner;

public class Array {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the size of the array of integers : ");
        byte size = in.nextByte();
        if (size == 0) {
            System.out.println("Invalid size");
            return;
        }
        int[] arr = new int[size];
        for (byte i = 0 ; i < arr.length; i++){
            System.out.print("Enter value of index-" + (i + 1) + " : ");
            arr[i] = in.nextInt();
        }
        System.out.println(Arrays.toString(arr));
    }
}
