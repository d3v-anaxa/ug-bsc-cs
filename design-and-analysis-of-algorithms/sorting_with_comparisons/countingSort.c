#include "sort.h"
void counting_sort(int array[], int size){
    int min = 2147483647, max = -2147483648;
    for(int i = 0; i < size; i++){
        if(array[i] < min) min = array[i];
        if(array[i] > max) max = array[i];
        comparisons+=2;
    }
    int newSize = max - min + 1;
    int *ctr = (int*) calloc(newSize, sizeof(int));
    for(int i = 0; i < size; i++){
        ctr[array[i] - min]++;
    }
    int idx = 0;
    for(int i = 0; i < newSize; i++){
        while(ctr[i] > 0){
            array[idx] = i + min;
            ctr[i]--;
            idx++;
            comparisons++;
        }   comparisons++;
    }   free(ctr);
    printf("COUNTING SORT COMPLETED!\n");
}
