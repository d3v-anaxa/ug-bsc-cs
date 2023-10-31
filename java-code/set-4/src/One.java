// WAP to calculate the sum of all command line args

public class One {
	public static void main(String[] args){
		if (args.length == 0){
			System.out.println("No input found");
			return;
		}

		int sum = 0;
		try {
			for (String arg : args) sum += Integer.parseInt(arg);
			System.out.println("Sum -> " + sum);
		} catch(Exception e) {
			System.out.println("Exception caught!!");
		} finally {
			System.out.println("[PROGRAM EXITED]");
		}
	}
}

// Output 
// javac  src/One.java -d class; \
//	java -classpath class One 100 1000 180
// Sum -> 1280
// [PROGRAM EXITED]

// Output
// javac  src/One.java -d class; \
// 	java -classpath class One 100 abc
// Exception caught!!
// [PROGRAM EXITED]

