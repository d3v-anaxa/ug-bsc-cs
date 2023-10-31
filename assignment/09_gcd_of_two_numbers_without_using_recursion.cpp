/*
Program 9 : WAP to calculate GCD of two numbers (i) with recursion (ii)
without recursion.

Algorithm :
Without using recursion
STEP_1: Start
STEP_2: Read positive integer n1 and n2
STEP_3: if ( n1 < 1 or n2 < 1) then print “Invalid Input” and exit Program
STEP_4: Set the minimum value between n1 and n2 inside variable named “min”
STEP_5: While ( min != 1)
STEP_5.1: if ( n1 % min == 0 and n2 % min == 0) then print min
STEP_5.2: --min
STEP_6: end While
STEP_7: End
*/

#include <iostream>
#include <algorithm>
int main(){
    int n1 = 0, n2 = 0;
    std::cout << "Enter two positive integers : " && std::cin >> n1 >> n2;
    if ( n1 < 1 || n2 < 1) {
        std::cout << "invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }
    int min = std::min(n1, n2);
    while (min != 1) {
        if (n1 % min == 0 && n2 % min == 0) break;
        --min;
    }
    std::cout << "The GCD of " << n1 << " and " << n2 << " is : " << min << std::endl;
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
