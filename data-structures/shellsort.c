// IMPLEMENTATION OF SHELL SORT ON AN ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 30

typedef int T;
void shellsort(T[], int);

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
    shellsort(arr, LEN);
    display(arr, LEN);
    return 0;
}

void shellsort(T arr[], int size){
    int gap = size/2,
        i, j;
    T tmp;
    while(gap > 0){
        i = gap;
        while(i < size){
            tmp = arr[i];
            j = i;
            while(j >= gap && arr[j - gap] > tmp){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
            i++;
        }   gap /= 2;
    }
}
