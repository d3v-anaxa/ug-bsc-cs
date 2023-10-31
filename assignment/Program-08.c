// Macro to swap to integer
#include <stdio.h>
#define swap(x, y) { int _t = x; x = y; y = _t;}
int main(void){
    int n1 = 10, n2 = 5;
    printf("n1 %d, n2 %d\n", n1, n2);
    swap(n1, n2);
    printf("n1 %d, n2 %d\n", n1, n2);
}
