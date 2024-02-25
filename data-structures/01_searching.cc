#include <iostream>
using namespace std;
template<typename T>
bool isSorted(T array[], int size){
    for(int i = 0; i < size - 1; i++){
        if(array[i] > array[i+1])
            return false;
    }   return true;
}
template<typename T>
int linearSearch(T array[], T target, int size){
    for(int i = 0; i < size; i++){
        if(array[i] == target)
            return i;
    }   return -1;
}
template<typename T>
int binarySearch(T array[], T target, int size){
    int start = 0,
        end = size - 1,
        mid = 0;
    while(start < end){
        mid = start + (end - start)/2;
        if(array[mid] == target){
            return mid;
        }   else if (array[mid] < target){
            start = mid + 1;
        }   else {
            end = mid - 1;
        }
    }   return -1;
}
template<typename T>
void test(void){
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
    cout << "Enter target element: " && cin >> target;
    if(isSorted<T>(array, size)){
        cout 
            << "Binary search-> target found at: " 
            << binarySearch<T>(array, target, size)
            << endl;
    } else {
        cout 
            << "Linear search-> target found at: "
            << linearSearch<T>(array, target, size)
            << endl;
    }
}
int main(void){
    test<int>();
}
