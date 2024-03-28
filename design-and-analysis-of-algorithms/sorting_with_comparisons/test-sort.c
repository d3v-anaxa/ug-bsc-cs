#include "sort.h"
// Further user of function idexing through enums
enum {
    INSERTION,
    MERGE,
    HEAP,
    QUICK,
    COUNTING,
    ALGO_COUNT,
}   sort_methods_t;
// Array display method
void display(int array[], int size){
    printf("List [%d]:", size);
    for(int i = 0; i < size; i++){
        if(i > 0){
            printf(array[i-1] <= array[i] ? " <=" : " >");
        }
        printf(" %d", array[i]);
    }   printf("\n");
    printf("Total comparisons : %d\n", comparisons);
}
// Driver code
int main(void){
    srand(time(0));
    // Define array
    int array[] = {[ 0 ... SIZE ] = 0},
        duplicate[] = {[ 0 ... SIZE ] = 0};
    // add random integers
    for(int i = 0; i < SIZE; i++){
        array[i] = rand() % 200;
        duplicate[i] = array[i];
    }
    // Sorting methods
    void (*sort_algo[])(int[], int) = {
        [INSERTION] = insertion_sort,
        [MERGE] = merge_sort,
        [HEAP] = heap_sort,
        [QUICK] = quick_sort,
        [COUNTING] = counting_sort,
    };
    // Display OG array
    display(array, SIZE);
    // Performing all sorting algorithms
    for(int i = 0; i < ALGO_COUNT; i++){
        printf("%s\n", "---");
        sort_algo[i](array, SIZE);
        display(array, SIZE);
        // Returning to OG state
        for(int i = 0; i < SIZE; i++){
            array[i] = duplicate[i];
        }   comparisons = 0;
    }
    return 0;
}
