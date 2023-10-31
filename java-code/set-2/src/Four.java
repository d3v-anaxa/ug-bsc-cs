// WAP to convert an input integer from input base to target base
// with base range of 2~10
// and exception handling

import java.util.*;
public class Four{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		try {
            do {
                System.out.print("Input base -> ");
                int inp_base = in.nextInt();

                System.out.print("Output base -> ");
                int out_base = in.nextInt();

                if ((inp_base < 2 || inp_base > 10) || ( out_base < 2 || out_base > 10)){
                    System.out.println("Range exceeded [2~10]!");
                    continue;
                }

                System.out.print("Input integer -> ");
                String inp = in.next(); 

                int deciVal = Integer.parseInt(inp, inp_base);
                String out = Integer.toString(deciVal, out_base);

                System.out.println("Output integer -> " + out);
                break;
            } while (true);

		} catch (Exception e) {
            System.out.println("Exception caught : " + e );
		} finally {
			in.close();
			System.out.println("[PROGRAM EXITED]");
		}
	}
}

// Output
// Input base -> 2
// Output base -> 8
// Input integer -> 1010
// Output integer -> 12
// [PROGRAM EXITED]
 
// Output
// Input base -> 8
// Output base -> 2
// Input integer -> 88
// Exception caught : java.lang.NumberFormatException: For input string: "88" under radix 8
// [PROGRAM EXITED]

// Output
// Input base -> 4
// Output base -> 16
// Range exceeded [2~10]!
// Input base -> 4
// Output base -> 2
// Input integer -> 333
// Output integer -> 111111
// [PROGRAM EXITED]
