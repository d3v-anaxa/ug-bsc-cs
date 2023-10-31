/*
PROBLEM 3 -> 
WAP to compute the sum of the first n terms of the following series : S = 1 + 1/2 + 1/3 + 1/4 + ...
    • Algorithm :
        step-1:  Start
        step-2:  S := 0
        step-1:  Read integer i
        step-3:  While ( i != 0)
				S = S + (1 / i)
				i = i - 1
			end while
        step-4:  Print S
        step-5:  End
      
    • Program Code :
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
int i{};
double S = 0;
std::cout << "Enter the value of n : " && std::cin >> i;
if (i< 1) return -1;
while ( i != 0) {
     S += ( 1 / double(i));
     --i;
}
std::cout << fixed << setprecision(2) << "The required sum is : " << S << std::endl;
return 0;
}
/*	
    • Output :

Enter the value of n : 65
The required sum is : 4.76

    • Discussion : 
Time Complexity -> O(n).
Space Complexity -> O(1).
Program Limitation(s) -> Input number is a Natural Number and beyond the range of 1 to 2147483647 will return inaccurate results.
*/
