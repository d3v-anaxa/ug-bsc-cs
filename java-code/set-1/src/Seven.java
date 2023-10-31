// WAP that creates a 2D array takes elements as user input 
// and counts the number of prime numbers in the array.
import java.util.*;
public class Seven{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int rows, cols;

        do {
            System.out.print("Enter row count -> ");
            rows = in.nextInt();
            System.out.print("Enter column count -> ");
            cols = in.nextInt();
            if ( rows < 1 || cols < 1){
                System.out.println("Invalid size entered");
continue;
            } else break;
        } while (true);

        System.out.println("2D Array of size " + (rows * cols) + " created successfully!!");
        int[][] _2Darray = new int[rows][cols]; 
        readElements(_2Darray);
        countPrime(_2Darray);
        in.close();
    } 

    private static void readElements(int[][] array){
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < array.length; i++){
            for (int j = 0; j < array[0].length; j++){
                System.out.print("Enter element - Array[" + i +"][" + j + "] -> ");
                array[i][j] = in.nextInt();
            }
        }
        in.close();
    }

    private static boolean checkPrime(int n){
        for(int i = 2; i*i <= n; i++){
            if ( n % i == 0 ) return false;
        } return true;
    }

    private static int countPrime(int[][] array){
        int counter = 0;
        for (int i = 0; i < array.length; i++){
            for (int j = 0; j < array[0].length; j++){
                if(checkPrime(array[i][j])) counter++;
            }
        }
        System.out.println("There are " + counter + " prime numbers inside this array!");
        return counter;
    }
}

// Output
// Enter row count -> 5
// Enter column count -> 2
// 2D Array of size 10 created successfully!!
// Enter element - Array[0][0] -> 10
// Enter element - Array[0][1] -> 11
// Enter element - Array[1][0] -> 12
// Enter element - Array[1][1] -> 13
// Enter element - Array[2][0] -> 14 
// Enter element - Array[2][1] -> 15
// Enter element - Array[3][0] -> 16
// Enter element - Array[3][1] -> 17
// Enter element - Array[4][0] -> 18
// Enter element - Array[4][1] -> 19
// There are 4 inside the array!
