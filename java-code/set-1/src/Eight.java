// WAP to print the characters of a string in alphabetical order.
import java.util.*;
public class Eight{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a string -> ");
        String input = in.nextLine();
        char[] inp_arr = input.toCharArray();
        Arrays.sort(inp_arr);
        System.out.println(new String(inp_arr));
        in.close();
    }
}

// Output
// Enter a string -> JAVA
// AAJV
