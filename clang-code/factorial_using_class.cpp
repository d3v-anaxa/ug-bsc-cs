#include <cstdlib>
#include <iostream>

using namespace std;

class number {
    private :
        int prev_num = 0;
        int f = 1;
        void get_num();
    public :
        void get_fib();
};

void number::get_num() {
    int x{};
    std::cout << "Enter a positive number : " && std::cin >> x; 
    if (x < 1) {std::cout << "Invalid Input" << std::endl; return number::get_num();}
    this->prev_num = x;
}

void number::get_fib() {
    number::get_num();
    int x = prev_num;
    while (x != 1) {
        f *= x;
        --x;
    }
    if (f < 1) {std::cout << "LIMIT EXCEEDED" << std::endl; exit(EXIT_SUCCESS);}
    std::cout << "The factorial of " << prev_num << " is : " << f << std::endl;
}

int main (void) {
    number n;
    n.get_fib();
    return 0;
}
