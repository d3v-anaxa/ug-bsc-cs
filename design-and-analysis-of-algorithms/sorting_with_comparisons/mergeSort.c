#include "sort.h"
void merge(int array[], int start, int mid, int end){
    int llen = mid - start + 1,
        rlen = end - mid;
    int larr[llen], 
        rarr[rlen];
    int i = 0,
        j = 0,
        k = start;
    while(i < llen){
        larr[i] = array[start + i];
        i++;
    }   i = 0;
    while(i < rlen){
        rarr[i] = array[mid + 1 + i];
        i++;
    }   i = 0;
    while( i < llen && j < rlen){
        if(larr[i] <= rarr[j]){
            array[k] = larr[i];
            i++;
        }   else {
            array[k] = rarr[j];
            j++;
        }   k++;
        comparisons++;
    }
    while(i < llen){
        array[k] = larr[i];
        i++;
        k++;
    }
    while(j < rlen){
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void merge_sort_recursion(int array[], int start, int end){
    if (end <= start) return;
    int mid = start + (end - start) / 2;
    merge_sort_recursion(array, start, mid);
    merge_sort_recursion(array, mid+1, end);
    merge(array, start, mid, end);
}

void merge_sort(int array[], int size){
    merge_sort_recursion(array, 0, size - 1);
    printf("MERGE SORT COMPLETED!\n");
}
