// IMPLEMENTATION OF MERGE SORT ON AN ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 1000

typedef int T;
void mergesort(T[], int, int);
void merge(T[], int, int, int);

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
    mergesort(arr, 0, LEN-1);
    display(arr, LEN);
    return 0;
}

void mergesort(T arr[], int start, int end){
    if (start >= end) return;
    int mid = start + (end - start)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
}


void merge(T arr[], int start, int mid, int end){
    int llen = mid - start + 1,
        rlen = end - mid;
    int larr[llen], rarr[rlen];
    int i = 0,
        j = 0,
        k = start;
    while (i < llen){
        larr[i] = arr[start+i];
        i++;
    }   i = 0;
    while (i < rlen){
        rarr[i] = arr[mid+i+1];
        i++;
    }   i = 0;
    while (i < llen && j < rlen){
        if (larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }   else {
            arr[k] = rarr[j];
            j++;
        }   k++;
    }
    while (i < llen){
        arr[k] = larr[i];
        ++i;
        ++k;
    }
    while (j < rlen){
        arr[k] = rarr[j];
        ++j;
        ++k;
    }
}

