#include "array_stack.hpp"

int main(void){
    Stack<int> n1;
    bool cont = true;
    do {
        cont = n1.choose();
    } while (cont);
    return 0;
}
