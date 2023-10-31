import java.util.Scanner;

public class LengthOfTwoDArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter row length : ");
        byte row = in.nextByte();
        System.out.print("Enter column length : ");
        byte column = in.nextByte();
        int[][] arr = new int[row][column];
        System.out.println("Array length : " + (arr.length * arr[0].length));
    }
}
