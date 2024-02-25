#include <iostream>
using namespace std;
template<class T>
void bubbleSort(T array[], int size){
    int i = 0,
        j = i;
    T temp;
    while(i < size - 1){
        j = i;
        while(j < size){
            if(array[j] < array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }   j++;
        }   i++;
    }
}

template<class T = int>
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
    bubbleSort(array, size);
    display(array, size);
}

int main(void){
    test();
}
