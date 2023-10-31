/*
   Program 9 : WAP to calculate GCD of two numbers (i) with recursion (ii)
   without recursion.
Algorithm :
(i) Using recursion
STEP_1: Start
STEP_2: function GCD
STEP_2.1: input positive integer n1 and n2
STEP_2.2: if ( n1 == 0) then return n2
STEP_2.3:else return GCD ( n2 % n1, n1)
STEP_3:end function GCD
STEP_4: Read positive integer n1 and n2
STEP_5: call GCD function with n1 and n2 as parameters
STEP_6: Print the value returned by the function
STEP_7: End
*/

#include <iostream>
unsigned GCD (unsigned n1, unsigned n2) {
    if (n1 == 0) return n2;
    return GCD(n2 % n1 , n1);
}
int main(){
    unsigned n1 = 0, n2 = 0;
    std::cout << "Enter two positive integers : " && std::cin >> n1 >> n2;
    if ( n1 < 1 || n2 < 1) {
        std::cout << "invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "The GCD of " << n1 << " and " << n2 << " is : " << GCD(n1, n2) << std::endl;
    return 0;
}

/*
Output :
SET-1 :
Enter two positive integers : 72 63
The GCD of 72 and 63 is : 9
SET-2 :
Enter two positive integers : 32 48
The GCD of 32 and 48 is : 16

Discussion :
Time Complexity: O(n)
Space Complexity: (i) Using recursion : O(n) (ii) Without using recrsion : O (1)
Program Limitation: Input number is a Natural Number and beyond the range of 1 to
INT_MAX will return inaccurate results.
 */
