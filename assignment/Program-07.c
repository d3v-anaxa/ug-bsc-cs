// Compute the factors of a number
#include <stdio.h>
int main(void){
    int input = 0;
    printf("Enter integer : ");
    scanf("%i", &input);
    if(input == 0){
        printf("No Factors found\n");
        return 1;
    }
    printf("Factor(s)");
    if(input < 0){ 
        printf(" -1");
        input *= -1;
    }
    for (int i = 1; i <= input; i++){
        if ( input % i == 0) printf(" %d", i);
    }
    printf("\n");
}
