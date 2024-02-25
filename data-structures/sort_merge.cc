#include <iostream>
using namespace std;

template<class T>
void merge(T array[], int start, int mid, int end){
    int i = 0, j = 0, k = start;
    int llen = mid - start + 1,
        rlen = end - mid;
    T larr[llen], rarr[rlen];
    while(i < llen){
        larr[i] = array[start + i];
        i++;
    }   i = 0;
    while(i < rlen){
        rarr[i] = array[mid+i+1];
        i++;
    }   i = 0;
    while(i < llen && j < rlen){
        if(larr[i] <= rarr[j]){
            array[k] = larr[i];
            i++;
        }   else {
            array[k] = rarr[j];
            j++;
        }   k++;
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

template<class T>
void mergeSortRecursion(T array[], int start, int end){
    if(start >= end) return;
    int mid = start + (end - start)/2;
    mergeSortRecursion(array, start, mid);
    mergeSortRecursion(array, mid+1, end);
    merge(array, start, mid, end);
}

template<class T>
void mergeSort(T array[], int size){
    mergeSortRecursion(array, 0, size - 1);
}

template<class T>
void display(T array[], int size){
    cout << "Array: ";
    for (int i = 0; i < size; i++){
        cout << " " << array[i];
    }   cout << endl;
}

template<class T = int>
void test(){
    int size = 0;
    T target;
    cout << "Enter array size: " && cin >> size;
    if(size < 1){
        cout << "Invalid array size\n";
        return;
    }
    T array[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element-" << i+1 << ": " && cin >> array[i];
    }
    display(array, size);
    mergeSortRecursion(array, 0, size-1);
    display(array, size);
}

int main(void){
    test();
}
