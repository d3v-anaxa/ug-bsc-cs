/*
PROBLEM 2 -> 
WAP to print to reverse a number. 
    • Algorithm :
        step-1:  Start
        step-2:  reverse := 0
        step-1:  Read integer i
        step-3:  While ( i != 0)
				reverse = ( reverse * 10 ) + ( i % 10 )
				i = i / 10
			end while
        step-4:  i := reverse
        step-5:  Print i
        step-6:  End
      
    • Program Code :
*/

#include <iostream>
using namespace std;

int main(void){
  int i{}, reverse = 0;
  std::cout << "Enter an Integer : " && std::cin >> i;
  while (i != 0)
  {
    reverse = (reverse * 10) + (i % 10);
    i /= 10;
  }
  i = reverse;
  std::cout << "Reverse of the given integer is : " << i << endl;
  return 0;
}
/*	
    • Output :

Enter an Integer : 120982
Reverse of the given integer is : 289021

    • Discussion : 
Time Complexity -> O(n).
Space Complexity -> O(1).
Program Limitation(s) -> Integer input beyond the range of -2147483648 to 2147483647 will return inaccurate results.
*/
