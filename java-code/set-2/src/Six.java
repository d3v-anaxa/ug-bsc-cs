// WAP to show the calling sequence of construction
// of super and sub class
public class Six {
	public static void main(String[] args){
		new B();
	}
}

class A {
	public A(){
		System.out.println("The constructor of class A has been called!");
	}
}

class B extends A {
	public B(){
		System.out.println("The constructor of class B has been called!");
	}
}

// Output
// The constructor of class A has been called!
// The constructor of class B has been called!
