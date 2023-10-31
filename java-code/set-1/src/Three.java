// WAP to demonstrate the throw keyword

class Excp1 extends Exception {
	public Excp1(){
		System.out.println("Custom Exception : " + this);
	}
}

public class Three{
	public static void main(String[] args) {
		try { 
			System.out.println("Try Block initiated.");
			throw new Excp1(); 
		}
		catch ( Excp1 e ) {
			System.out.println("Catch Block initiated.");
		} 
	}
}

// Output
// Try Block initiated.
// Custom Exception : Excp1
// Catch Block initiated.
