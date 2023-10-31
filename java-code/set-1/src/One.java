//Write a java program with proper design to demonstrate a try-catch block which is nested within the catch block of outer try

public class One{
    public static void main(String[] args){
        try {
            System.out.println(10 / 0);
        } catch (Exception e) {
            try {
                System.out.println(e);
                String[] lang = {"JAVA"};
                System.out.println(lang[1]);
            } catch (Exception E) {
                System.out.println(E);
            }
        }
    }
}

// Output
// java.lang.ArithmeticException: / by zero
// java.lang.ArrayIndexOutOfBoundsException: Index 1 out of bounds for length 1
