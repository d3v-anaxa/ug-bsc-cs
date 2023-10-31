// WAP to show try with multiple catch blocks
import java.util.Random;
public class Five {
    public static void main(String[] args){
		System.out.println("Choosing Random Exception!...");
	try {
	switch (new Random().nextInt(3)){
		case 0:
			throw new IndexOutOfBoundsException();
		case 1:
			throw new NullPointerException();
		case 2:
			throw new ArithmeticException();
	}
	} catch (ArithmeticException e){
		System.out.println("Exception caught -> " + e);
	} catch (IndexOutOfBoundsException e){
		System.out.println("Exception caught -> " + e);
	} catch (NullPointerException e){
		System.out.println("Exception caught -> " + e);
	} finally {
		System.out.println("[PROGRAM EXITED]");
	}
    }
}

// Output 
// Choosing Random Exception!...
// Exception caught -> java.lang.ArithmeticException
// [PROGRAM EXITED]

// Output
// Choosing Random Exception!...
// Exception caught -> java.lang.IndexOutOfBoundsException
// [PROGRAM EXITED]
