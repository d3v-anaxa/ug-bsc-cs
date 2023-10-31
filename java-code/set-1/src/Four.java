// WAP to demonstrate the throws keyword

class Excp2 extends Exception {
	public Excp2(){
		System.out.println("Custom Exception : " + this);
	}
}

public class Four{
	public static void main(String[] args){
		try { 
			System.out.println("Try Block initiated.");
            callException();
		}
		catch ( Excp2 e ) {
			System.out.println("Catch Block initiated.");
		} 
	}
    private static void callException() throws Excp2 {
			throw new Excp2(); 
    }
}

// Output
// Try Block initiated.
// Custom Exception : Excp2
// Catch Block initiated.
