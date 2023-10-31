import java.util.Scanner;
class Factorial{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num, factorial = 1;
        while(true){
            System.out.print("Enter a positive integer : ");
            num = in.nextInt();
            if (num < 1){ System.out.println("Input beyond range!!"); continue; }
            factorial = num;
            break;
        }
        while(num-- != 1){ factorial *= num; }
        if (factorial > 0) { System.out.println("Factorial : " + factorial); }
        else { System.out.println("Precision lost! Factorial input range -> 1~16"); }
        in.close();
    }
}
