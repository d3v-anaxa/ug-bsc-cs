import java.util.Scanner;

class CheckPrime{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int num;
        boolean isPrimeFlag = true;
        while(true){
            System.out.print("Enter a positive integer : ");
            num = in.nextInt();
            if (num < 1) {
                System.out.println("Input a positive integer!");
                continue;
            }   
            in.close();
            break;
        }
        for (int i = 2; i*i <= num; i++){
            if(num % i == 0){
                isPrimeFlag = !isPrimeFlag;
                break;
            }
        }  
        System.out.println(num + ( isPrimeFlag ? " is prime!" : " is not prime!"));
    }
}
