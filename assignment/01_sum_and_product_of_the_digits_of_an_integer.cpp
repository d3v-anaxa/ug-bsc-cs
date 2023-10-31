/*
PROBLEM 1 -> 
WAP to print the sum and product of digits of an integer. 
    • Algorithm :
        step-1:  Start
        step-2:  Set sum to 0 and product to 1
        step-1:  Read integer i
        step-3:  While ( i != 0)
				sum = sum + ( i % 10 )
				product = product * ( i % 10)
				i = i / 10
			end while
        step-4:  Print sum and product
        step-5:  End
      
    • Program Code :
*/
#include<iostream>
using namespace std;
int main(){
    int sum = 0, product = 1, i{};
    std::cout << "Enter an Integer : " && std::cin >> i;
    while (i != 0) {
        sum += (i % 10);
        product *= (i % 10);
        i /= 10;
    }
   	std::cout << "The sum is : " << sum << std::endl;
	std::cout << "The product is : " << product << std::endl;
	return 0;
}
	
/*
    • Output :

Enter an Integer : 2001
The sum is : 3
The product is : 0

    • Discussion : 
Time Complexity -> O(n).
Space Complexity -> O(1).
Program Limitation(s) -> Integer input beyond the range of -2147483648 to 2147483647 will return inaccurate results.
*/
