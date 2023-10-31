#include <iostream>
#include <cmath>
using namespace std;

void printArmstrongNum(int num)
{
    int sum = 0, e = 0, temp = num;
    while (temp != 0)
    {
        ++e;
        temp /= 10;
    }

    temp = num;
    while (temp != 0)
    {
        sum += pow((temp % 10), e);
        temp /= 10;
    }
    if (sum == num)
        std::cout << num << " ";
}

int main(void)
{
    int n{};
    std::cout << "Enter a limit [Positive Integer Only] : " && std::cin >> n;
    if (n <= 0)
        EXIT_FAILURE;
    for (int i = 0; i <= n; ++i)
        printArmstrongNum(i);
    std::cout << std::endl;
    return 0;
}
