#include <iostream>
int fibonacciRecursion(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}
void fibonacciIteration(int n) {
    int first = 0, second = 1, next;
    std::cout << "Fibonacci series using iteration: ";
    for (int i = 0; i < n; ++i) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        std::cout << next << " ";
    }
    std::cout << std::endl;
}
int main() {
    int terms;
    std::cout << "Enter the number of terms for Fibonacci series: ";
    std::cin >> terms;
    std::cout << "Fibonacci series using recursion: ";
    for (int i = 0; i < terms; ++i) {
        std::cout << fibonacciRecursion(i) << " ";
    }
    std::cout << std::endl;
    fibonacciIteration(terms);
    return 0;
}
