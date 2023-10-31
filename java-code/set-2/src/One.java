// WAP to print the sum of command line args and check for illegal inputs
public class One {
	public static void main(String[] args){
		if (args.length == 0){
			System.out.println("No input integers found!");
            return;
        }
		int sum = 0;
		try {
		for (String n : args)
			sum += Integer.parseInt(n);
			System.out.println("Sum of arguments -> " + sum);
		} catch (Exception e) {
			System.out.println("Illegal input detected!");
		}
	}
}
// Output
// $ java -classpath class/ One 
// No input integers found!

// Output 
// $ java -classpath class/ One e 13
// Illegal input detected!
// Sum of arguments -> 0

// Output
// $ java -classpath class/ One 10 50 -30
// Sum of arguments -> 30
