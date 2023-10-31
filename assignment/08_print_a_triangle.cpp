// WAP to print a triangle of stars as follows (take number of lines from user) ->
//        *
//      * * *
//    * * * * *
//  * * * * * * *

#include <iostream>
using namespace std;

int main(void){
  int lines{};
  std::cout << "Enter the height of the triangle : " && std::cin >> lines;
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j <= lines; j++)
      std::cout << (i + j >= lines ? "* " : "  ");
    for (int j = 0; j < i; j++)
      std::cout << "* ";
    std::cout << endl;
  }
}
