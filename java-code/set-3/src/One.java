// WAP to show two uses of super keyword

public class One {
	public static void main(String[] args){
		new Dog().call();	
	}
}

class Animal {
	String type;
	Animal (String type){
		this.type = type;
	}
	 void sound(){
		switch (type){
			case "Dog":
				System.out.println("[Bark]");
				break;
			case "Cat":
				System.out.println("[Meow]");
				break;
			case "Pig":
				System.out.println("[Oink]");
				break;
			default:
				System.out.println("[Awee]");
				break;
		}
	}
}

class Dog extends Animal {
	Dog(){
		super("Dog"); // calling constructor of super class
		System.out.println("Instance of " + this.getClass().getSimpleName() + " has been created.");
	}

	void call() {
		super.sound(); // calling member function of super class
	}
}	

// Output
// sh-5.1$ javac src/One.java -d class; java -classpath class/ One
// Instance of Dog has been created.
// [Bark]
