import java.util.Scanner;
class OverloadedFunctionsWithTypeConversion{
    public static char func(short x){
        System.out.println( x + " --(short to char)--> " + (char)(x));
        return (char)(x);
    }
    public static void func(int x){
        System.out.println( x + " --(int to double)--> " + (double)(x));
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        byte num_b;
        System.out.print("Enter a byte code -> ");
        num_b = in.nextByte();
        in.close();
        char ch = func(num_b);
        func(ch);
    }
}
