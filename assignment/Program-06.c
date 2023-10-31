// Function to check for prime numbers
#include <stdio.h>
#include <stdbool.h>
bool checkPrime(int n){
    for(int i = 2; i <= n / 2 ;i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(void){
    int n = 0;
    while(n++ != 100){
        if(checkPrime(n))printf("%d ", n); 
    }
    printf("\n");
    return 0;
}

