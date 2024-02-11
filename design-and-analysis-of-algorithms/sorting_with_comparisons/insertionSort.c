#include "sort.h"
void insertion_sort(int array[], int size){
    int i = 1,
        j = 0,
        key = 0;
    while(i < size){
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            --j;
            comparisons++;
        }   array[j+1] = key;
        ++i;
    }   printf("INSERTION SORT COMPLETED!\n");
} 
