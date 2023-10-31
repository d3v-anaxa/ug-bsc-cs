// WAP to sort an array of 10 integers in ascending order
import java.util.*;
public class Four {
    final static int SIZE = 10;
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int[] array = new int[SIZE];
        try {
            for(int i = 0; i < SIZE; i++){
                System.out.print("Enter element " + i + " -> ");
                array[i] = in.nextInt();
            }
            System.out.println("BEFORE SORT : " + Arrays.toString(array));
            selection_sort(array);
            System.out.println("AFTER SORT  : " + Arrays.toString(array));
        } catch (Exception e) {
            System.out.println("Illegeal input!!");
        } finally {
            System.out.println("[PROGRAM EXITED]");
        }
    }

    private static void selection_sort(int[] array){
        for (int i = 0; i < array.length - 1;){
            if (array[i] > array[i+1]){
                array[i] ^= array[i+1];
                array[i+1] ^= array[i];
                array[i] ^= array[i+1];
                if (i != 0)
                    i--;
            } else i++;
        }
    }
}

// Output
// java -classpath class Four
// Enter element 0 -> 19
// Enter element 1 -> 17
// Enter element 2 -> a
// Illegeal input!!
// [PROGRAM EXITED]

// Output
// java -classpath class Four
// Enter element 0 -> 19
// Enter element 1 -> -10
// Enter element 2 -> 17
// Enter element 3 -> 10
// Enter element 4 -> 8
// Enter element 5 -> 0
// Enter element 6 -> -2
// Enter element 7 -> 8
// Enter element 8 -> -7
// Enter element 9 -> 16
// BEFORE SORT : [19, -10, 17, 10, 8, 0, -2, 8, -7, 16]
// AFTER SORT  : [-10, -7, -2, 0, 8, 8, 10, 16, 17, 19]
// [PROGRAM EXITED]
