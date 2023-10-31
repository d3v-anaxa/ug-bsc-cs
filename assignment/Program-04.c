// Print result of series 1 - 2+ 3 - 4 + ... +/- n
#include<stdio.h>
int main(void){
    int range = 0;
    int res = 0;
    printf("Enter range [ >0 ] : ");
    scanf("%ud", &range);
    if(range < 1) {
        printf("Invalid Range\n");
        return 0;
    }
    for(int i = 1; i <= range; i++){
        if ( i % 2 ){
            printf(" + %d", i);
            res += i;
            continue;
        }
        printf(" - %d", i);
        res -= i;
    }
    printf(" = %d\n", res);
    return 0;
}
