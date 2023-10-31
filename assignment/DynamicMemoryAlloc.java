import java.util.Scanner;
class DynamicMemoryAlloc{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int size = in.nextInt();
        in.close();
        if ( size < 0 ) { System.out.println("Invalid size for memory allocation!"); return; }
        int[] array = new int[size];
        for (int i = 0; i < size; i++){
            System.out.print("Enter elem-" + (i + 1) + " : ");
            array[i] = in.nextInt();
        }
        System.out.print("Array Elements -> ");
        for (int i = 0; i < size; i++){
            System.out.print(" " + array[i]);
        } System.out.println("");
    }
}
