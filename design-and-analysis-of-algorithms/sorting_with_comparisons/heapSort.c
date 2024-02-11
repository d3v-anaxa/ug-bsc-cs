#include "sort.h"
void heapify(int array[], int size, int i){
    int largest = i,
        left = 2 * i + 1,
        right = 2 * i + 2,
        temp = 0;
    if(left < size && array[left] > array[largest]){
        largest = left;
        comparisons++;
    }
    if(right < size && array[right] > array[largest]){
        largest = right;
        comparisons++;
    }
    if(largest != i){
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

void heap_sort(int array[], int size){
    int i = size / 2 - 1,
        temp = 0;
    for(; i >= 0; --i){
        heapify(array, size, i);
    }
    for(i = size - 1;i > 0; --i){
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }   printf("HEAP SORT COMPLETED!\n");
}
