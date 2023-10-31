/*
PROBLEM 4 -> 
WAP to compute the sum of the first n terms of the following series : S = 1 - 2 + 3 - 4 + ...
    • Algorithm :
        step-1:  Start
        step-2:  S := 0
        step-1:  Read integer i
        step-3:  if ( i % 2 == 0)
				S = S - (i / 2)
			else
				S = (i + 1)/2		
        step-4:  Print S
        step-5:  End
      
    • Program Code :
*/
#include <iostream>
using namespace std;

int main(){
  int i{}, S = 0;
  std::cout << "Enter the value of n : " && std::cin >> i;
  if (i < 1) return -1;
  S = ( i % 2 == 0) ? S - (i / 2) : ( i + 1) / 2;
  std::cout << "The obtained result is : " << S << endl;
  return 0;
}
/*	
    • Output :

Enter the value of n : 123
The obtained result is : 62

    • Discussion : 
Time Complexity -> O(1).
Space Complexity -> O(1).
Program Limitation(s) -> Input number is a Natural Number and beyond the range of 1 to 2147483647 will return inaccurate results.
*/
