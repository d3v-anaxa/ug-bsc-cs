// IMPLEMENTATION OF SELECTION SORT ON AN ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 30

typedef int T;
void selectionsort(T[], int);

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
    selectionsort(arr, LEN);
    display(arr, LEN);
    return 0;
}

void selectionsort(T arr[], int size){
    T tmp;
    int min_idx = 0;
    for(int i = 0; i < size - 1; i++){
        min_idx = i;
        for(int j = i + 1; j < size; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}
