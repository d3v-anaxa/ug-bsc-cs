// WAP to print the factorial of integer between 0 - 9 and 
// throws/handles exception if input beyond range 
import java.util.*;
public class Two {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int num = 0;
		System.out.print("Enter an integer [0~9] -> ");
		try {
			num = in.nextInt();
			if (num < 0 || num > 9)
				throw new Excp();
			else
                System.out.println("Factorial of " + num + " -> " + factorial(num));
		} catch (Exception e) {
			System.out.println("[PROGRAM EXITED]");
		} finally {
			in.close();
		}
	}
	
	public static long factorial(int x){
        if (x == 0 || x == 1)
            return x;
        else 
            return x * factorial(x - 1);
	}
}

class Excp extends Exception{
	public Excp(){
		System.out.println("Exception caught : " + this + " : Input beyond range [0 ~ 9]!");
	}
}

// Output
// Enter an integer [0~9] -> 10
// Exception caught : Excp : Input beyond range [0 ~ 9]!
// [PROGRAM EXITED]

// Output
// Enter an integer [0~9] -> -10
// Exception caught : Excp : Input beyond range [0 ~ 9]!
// [PROGRAM EXITED]

// Output
// Enter an integer [0~9] -> 5
// Factorial of 5 -> 120
