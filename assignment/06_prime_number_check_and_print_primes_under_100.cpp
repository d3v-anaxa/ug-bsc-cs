// Write a function to find whether a given no. is prime or not.
// Use the same to generate the prime numbers less than 100.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_prime(unsigned x){ // function for checking prime numbers
    bool is_prime{};
    for (unsigned i = 2; i < x ; i++) {
        if (x % i == 0){is_prime = false;break;}
        is_prime = true;
    }
    return is_prime;
}

void primeUnder100(){ // function for printing prime numbers under 100
  std::cout << "Prime Numbers under 100 : ";
  for (unsigned i = 0; i < 100; i++){std::cout << (is_prime(i) ? to_string(i) : "" ) << (is_prime(i) ? " " : "" );}
  std::cout << endl;
}

int main(void)
{
    unsigned i{};
    std::cout << "1. check prime or not " << std::endl;
    std::cout << "2. print prime numbers under 100 " << std::endl;
    std::cout << "Enter your choice : " && std::cin >> i;
    switch (i) {
        case 1: {
				    unsigned x{};
				    std::cout << "Enter a positive integer : ";
				    std::cin >> x;
                    std::cout << ((is_prime(x)) ? "Is a prime numer" : "Not a prime number") << std::endl;
                    break;
                }
        case 2: primeUnder100();break;
        default: std::cout << "Invalid choice" << std::endl; return -1;
    }
    return 0;
}
