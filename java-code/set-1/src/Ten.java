// WAP to show the use of static functions with variable args
public class Ten{
	public static void main(String[] args){
        int result1 = sumVarArgs(10, 20, -30, 50, -100);
        int result2 = sumVarArgs(10, 20, -30, 50, -100, 200, -500, 800);
        System.out.println("Result of function 5 arguments -> " + result1);
        System.out.println("Result of function 8 arguments -> " + result2);
	}

    public static int sumVarArgs(int... nums){
        int total = 0;
        for (int num : nums)
            total += num;
        return total;
    }
}

// Output
// Result of function 5 arguments -> -50
// Result of function 8 arguments -> 450
