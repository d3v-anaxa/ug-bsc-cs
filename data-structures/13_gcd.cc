#include <iostream>
int gcdRecursion(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursion(b, a % b);
}
int gcdIteration(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "GCD of " << num1 << " and " << num2 << " using recursion: " << gcdRecursion(num1, num2) << std::endl;
    std::cout << "GCD of " << num1 << " and " << num2 << " without recursion: " << gcdIteration(num1, num2) << std::endl;
    return 0;
}
