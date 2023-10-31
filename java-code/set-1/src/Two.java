//Write a java program with proper design to demonstrate the need of a finally block

public class Two{
    public static void main(String[] args){
        try {
            System.out.println("Try block initiated.");
            System.out.println((10 / 0));
        } catch (Exception e) {
            System.out.println("Catch block initiated\n" + e);
        } finally {
		System.out.println("Finally block has been executed");
	}
    }
}

// Output
// Try block initiated.
// Catch block initiated
// java.lang.ArithmeticException: / by zero
// Finally block has been executed
