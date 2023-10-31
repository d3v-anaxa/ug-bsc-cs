public class Nine{
	public static void main(String[] args){
        Distance n1 = new Distance(5 , 8);		
        Distance n2 = new Distance();	
        System.out.println("n1 -> " + n1.feet + " ft " + n1.inches );
        System.out.println("n2 -> " + n2.feet + " ft " + n2.inches );
        System.out.println();
        copyClass(n1, n2);
        System.out.println("n1 -> " + n1.feet + " ft " + n1.inches );
        System.out.println("n2 -> " + n2.feet + " ft " + n2.inches );
	}

    private static void copyClass(Distance X, Distance Y){
        Y.feet = X.feet;
        Y.inches = X.inches;
        System.out.println("Properties copied successfully!");
    }
}

class Distance{
	int feet, inches;
	public Distance(){
	}
	public Distance(int feet, int inches){
		this.feet = feet;
		this.inches = inches;
	}
}

// Output
// n1 -> 5 ft 8
// n2 -> 0 ft 0
// 
// Properties copied successfully!
// n1 -> 5 ft 8
// n2 -> 5 ft 8
