// WAP to compute the factors of a given number.

#include <iostream>
using namespace std;

int main(void){
  int n{};
  std::cout << "Enter an Integer : " && std::cin >> n;
  if (n == 0) exit(EXIT_SUCCESS);
  std::cout << "Factors of " << n << " is : ";
  if (n > 0){std::cout << " 1 ";}
  if (n < 0){std::cout << " -1 "; n /= -1;}
  while ( n != 1 ){
    static int f = 2;
    if (n % f == 0) {
        std::cout << f << " ";
        n /= f;
        continue;
    }
    ++f;
  }
  std::cout << std::endl;
}
