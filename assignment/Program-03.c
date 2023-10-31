// comput series 1 + 1/2 + 1/3 + ... + 1/n and print result
#include <stdio.h>
int main(void){
    int input = 0;
    double res = 0;
    printf("Input range [n>0] : ");
    scanf("%i", &input);
    if(input < 1){
        printf("Invalid Input!!\n");
        return 1;
    }
    while(input > 0){
        res += 1/ (double)input;
        input -= 1;
    }
    printf("result %f\n", res);
    return 0;
}
