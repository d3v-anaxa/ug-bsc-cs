#include <iostream>
using namespace std;
template<typename T>
void display(T array[], int size){
    cout << "List[" << size << "]: ";
    for(int i = 0; i < size; i++){
        cout << " " << array[i];
    }   cout << endl;
}
template<typename T>
void insertionSort(T array[], int size){
    int i = 1,
        j = 0;
    T key;
    while(i < size){
        key = array[i];
        j = i - 1;
        while( j >= 0 && array[j] > key){
            array[j+1] = array[j];
            --j;
        }   array[j+1] = key;
        i++;
    }
}
template<typename T>
void bubbleSort(T array[], int size){
    T temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = i; j < size; j++){
            if(array[j] < array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    
}
template<typename T>
void selectionSort(T array[], int size){
    int min_idx = 0;
    T temp;
    for(int i = 0; i < size - 1; i++){
        min_idx = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min_idx])
                min_idx = j;
        }
        if(min_idx == i) continue;
        temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }    
}
template<typename T>
void test(void){
    int size = 0;
    int target;
    cout << "Enter array size: " && cin >> size;
    if(size < 1){
        cout << "Invalid array size\n";
        return;
    }
    T array[size];
    for (int i = 0; i < size; i++){
        cout << "Enter element-" << i+1 << ": " && cin >> array[i];
    }
    void (*sort_algo[])(T[], int) = {
        insertionSort,
        bubbleSort,
        selectionSort
    };
    display<T>(array, size);
    cout << "Insertion Sort/ Bubble Sort/ Selection Sort[0,1,2]: " && cin >> target;
    sort_algo[target](array, size);
    display<T>(array, size);
}
int main(void){
    test<int>();
}
