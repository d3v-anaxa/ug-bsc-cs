#include <iostream>
using namespace std;
template<class T>
void selectionSort(T array[], int size){
    int i = size - 1,
        j = 0,
        max_idx;
    T temp;
    while(i > 0){
        j = 0;
        max_idx = i;
        while(j < i){
            if(array[j] > array[max_idx]){
                max_idx = j;
            }   j++;
        }
        if(max_idx != i){
            temp = array[i];
            array[i] = array[max_idx];
            array[max_idx] = temp;
        }   --i;
    }
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
    selectionSort(array, size);
    display(array, size);
}

int main(void){
    test();
}
