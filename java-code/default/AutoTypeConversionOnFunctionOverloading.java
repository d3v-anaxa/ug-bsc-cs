import java.util.Scanner;

public class AutoTypeConversionOnFunctionOverloading {
    public static void func(float i){
        System.out.println("entered float as argument -> "+ i);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        func(in.nextByte());
    }
}
