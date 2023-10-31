// WAP that takes array size as user input
// creates array dynamically
// reads array elements as user input 
// prints the array
// handles any exception
import java.util.*;
public class Three{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int size = 0;
        do {
            System.out.print("Enter the size of the array : ");
            size = in.nextInt();
            if (size < 1 || size > 256){
                System.out.println("Illegal array size![valid range 1~256]");
                continue;
            } break;
        } while (true);
        int[] array = new int[size];
        try{
            readElements(array);
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            in.close();
            System.out.println("Array elements -> " + Arrays.toString(array));
        }
    }

    public static void readElements(int[] array) throws Exception{
        Scanner in = new Scanner(System.in);
        try {
            for (int i = 0; i < array.length; i++){
                System.out.print("Enter element Array[" + i + "] -> ");
                array[i] = in.nextInt();
            }
        } catch (Exception e){
            System.out.println(e + " : Illegal input type!");
        } finally {
            in.close();
        }
    }
}

// Output 
// Enter the size of the array : 1
// Enter element Array[0] -> 10
// Array elements -> [10]

// Output 
// Enter the size of the array : 3
// Enter element Array[0] -> a
// java.util.InputMismatchException : Illegal input type!
// Array elements -> [0, 0, 0]
