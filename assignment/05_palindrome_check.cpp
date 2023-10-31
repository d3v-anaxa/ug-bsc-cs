/*
PROBLEM 5 -> 
Write a function that checks whether a given string is Palindrome or not. Use this function to find whether the string entered by user is Palindrome or not.
    • Algorithm :
        step-1:  Start
        step-2:  function palindrome_check (string str)
                          for (i := 0; i < str.length / 2; ++i)
                              if (str[i] != str[str.length() - i - 1]) 	return false;
    				end for;
				return true	
			end palindrome_check
        step-3:  Read string str	
        step-4:  if (palindrome_check(str) == true)
				print “Is palindrome”
			else
				print “Not a palindrome”
        step-5:  End
      
    • Program Code :
*/
#include <iostream>
using namespace std;

bool check_if_palindrome(string str) {
    for (size_t i = 0; i < str.length() / 2; ++i) {
        if (str[i] != str[str.length() - i - 1]) return false;
        }
    return true;
}

int main(){
	string str{};
	std::cout << "Enter a string : " && std::cin >> str;
    	std::cout << (check_if_palindrome(str) ? "Is a palindrome" : "Not a palindrome") << std::endl;
    	return 0;
}
/*
    • Output :
Enter a string : dxd   
IS PALINDROME

    • Discussion : 
Time Complexity -> O(n).
Space Complexity -> O(1).
Program Limitation(s) -> Can check only one word at a time. The input of the program is case sensitive.
*/
