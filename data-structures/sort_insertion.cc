#include <iostream>
using namespace std;

template<class T>
void insertionSort(T array[], int size){
    int i = 1,
        j = 0;
    T key;
    while(i < size){
        j = i - 1;
        key = array[i];
        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            --j;
        }   array[j+1] = key;
        i++;
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
    insertionSort(array, size);
    display(array, size);
}

int main(void){
    test();
}
