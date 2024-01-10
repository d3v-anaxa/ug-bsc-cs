// IMPLEMENTATION OF BUBBLE SORT ON AN ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 30

typedef int T;
void bubblesort(T[], int);

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
    bubblesort(arr, LEN);
    display(arr, LEN);
    return 0;
}

void bubblesort(T arr[], int size){
    T tmp;
    for(int i = 0; i < size-1; i++){
        for(int j = i; j < size; j++){
           if(arr[i] <= arr[j]) continue;
           tmp = arr[i];
           arr[i] = arr[j];
           arr[j] = tmp;
        }
    }
}
