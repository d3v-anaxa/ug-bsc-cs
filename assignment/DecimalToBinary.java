import java.util.Scanner;
class DecimalToBinary{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num;
        System.out.print("Enter the decimal integer : ");
        num = in.nextInt();
        int ptr = 1 << 30;
        System.out.print("Binary representation -> ");
        while ((ptr/=2) != 0){
            System.out.print((num & ptr) != 0 ? "1" : "0");
        }
        System.out.println("");
        in.close();
    }
}
