#include "sort.h"

int partition(int array[], int low, int high){
    int rand_idx = low + rand() % (high - low + 1);
    int pivot = array[rand_idx],
        i = low - 1,
        j = low,
        temp = 0;
    temp = array[rand_idx];
    array[rand_idx] = array[high];
    array[high] = temp;
    while(j < high){
        if (array[j] < pivot){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }   j++;
        comparisons++;
    }   ++i;
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    return i;
}

void quick_sort_rec(int array[], int start, int end){
    if(end <= start) return;
    int pivot_idx = partition(array, start, end);
    quick_sort_rec(array, start, pivot_idx - 1);
    quick_sort_rec(array, pivot_idx + 1, end);
}

void quick_sort(int array[], int size){
    srand(time(0));
    quick_sort_rec(array, 0, size - 1);
    printf("QUICK SORT COMPLETED!\n");
}
