#include <iostream>
unsigned long long factorialRecursion(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursion(n - 1);
}
unsigned long long factorialIteration(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}
void factorsRecursion(int n, int i) {
    if (i > n / 2) {
        std::cout << n << " ";
        return;
    }
    if (n % i == 0) {
        std::cout << i << " ";
    }
    factorsRecursion(n, i + 1);
}
void factorsIteration(int n) {
    std::cout << "Factors of " << n << ": ";
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << n << std::endl;
}
int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Factorial using recursion: " << factorialRecursion(num) << std::endl;
    std::cout << "Factorial using iteration: " << factorialIteration(num) << std::endl;
    std::cout << "Factors using recursion: ";
    factorsRecursion(num, 1);
    std::cout << std::endl;
    factorsIteration(num);
    return 0;
}
