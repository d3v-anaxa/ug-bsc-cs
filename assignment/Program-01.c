// Print sum and product of input integer digits 
#include <stdio.h>
int main(void){
    long long int input = 0, sum = 0, product = 1, veFlag = 0, _t = 0;
    printf("Enter the integer : ");
    scanf("%lld", &input);
    if(input < 0){
        veFlag = 1;
        input *= -1;
    }
    _t = input < 0 ? -input : input;
    while(_t != 0){
        sum += _t % 10;
        product *= _t % 10;
        _t /= 10;
    }
    if (veFlag){sum *= -1;product *= -1;}
    printf("sum = %lld\n", sum);
    printf("product = %lld\n", product);
    return 0;
}
