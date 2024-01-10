// IMPLEMENTATION OF INSERTION SORT ON AN ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 30

typedef int T;
void insertionsort(T[], int);

void display(T arr[], int size){
    printf("List : ");
    for (int i = 0; i < size; i++){
        if (i != 0)
            printf(arr[i-1] == arr[i] ? " =" : arr[i-1] < arr[i] ? " <" : " >");
        printf(" %d", arr[i]);
    }   printf("\n");
}

int main(void){
    srand(time(0));
    T arr[LEN];
    for (int i = 0; i < LEN; i++){
        arr[i] = rand() % LEN - (LEN/2);
    }
    display(arr, LEN);
    insertionsort(arr, LEN);
    display(arr, LEN);
    return 0;
}

void insertionsort(T arr[], int size){
    int i = 1,
        j = 0;
    T key = 0;
    while( i < size){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }   arr[j+1] = key;
        ++i;
    }
}
