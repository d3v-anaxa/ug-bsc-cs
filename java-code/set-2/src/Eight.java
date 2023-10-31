// WAP to illustrate IndexOutOfBoundsException
public class Eight {
    public static void main(String[] args){
        int[] array = new int[5];
        try {
            System.out.println(array[-1]);		
        } catch (Exception e) {
            System.out.println("Exception caught : " + e);		
            
        }
	}
}
// Output
// Exception caught : java.lang.ArrayIndexOutOfBoundsException: Index -1 out of bounds for length 5
