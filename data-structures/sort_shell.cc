#include <iostream>
using namespace std;

template<class T>
void shellSort(T array[], int n) {
    T temp;
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
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
    shellSort(array, size);
    display(array, size);
}

int main(void){
    test();
}
