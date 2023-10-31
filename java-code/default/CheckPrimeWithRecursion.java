import java.util.Scanner;

public class CheckPrimeWithRecursion {
    public static boolean _func(int x, int pointer){
        if (pointer * pointer > x) return true;
        if (x % pointer == 0) return false;
        pointer += 1;
        return _func(x , pointer);
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a positive integer : ");
        int inp = in.nextInt();
        int _pointer_int = 2;
        System.out.println(_func(inp, _pointer_int) ? "Is prime " : "Not prime");
    }
}
