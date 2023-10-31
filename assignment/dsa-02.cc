// WAP using templates to sort a list of elements. Give user the option to perform sorting
// using Insertion sort, Bubble sort or Selection sort.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void InsertionSort(vector<T> &arr){
    int n = arr.size();
    for (int i = 1; i < n;i++){
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "Insertion Sort Completed!\n";
}

template<typename T>
void BubbleSort(vector<T> &arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            if (arr[i] > arr[j])
                swap(arr[i] , arr[j]);
        }
    }
    cout << "Bubble Sort Completed!\n";
}

template<typename T>
void SelectionSort(vector<T> &arr){
    for(int i = 0; i < arr.size() - 1;){
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            if (i != 0) i--;
        } else i++;
    }
    cout << "Selection Sort Completed!\n";
}

typedef double defType;
int main(void) {
    vector<defType> array = {};
    unsigned int size, choice;
    cout << "Enter list size -> " && cin >> size;

    for(int i = 0; i < size; i++){
        defType _t;
        cout << "Enter element-" << i << " -> " && cin >> _t;
        array.push_back(_t);
    }

    cout << "Array -> ";
    for (defType x : array)
        cout << x << " ";
    cout << endl;

    cout 
        << "Select sorting algorithm!\n"
        << "1. Insertion sort\n"
        << "2. Bubble Sort\n"
        << "3. Selection Sort.\n"
        << "Enter choice -> ";
    cin >> choice;

    switch (choice){
        case 1:
            InsertionSort(array);
            break;
        case 3:
            SelectionSort(array);
            break;
        default:
            BubbleSort(array);
            break;
    }
    cout << "Array -> ";
    for (defType x : array)
        cout << x << " ";
    cout << endl;
    return 0;
}

// Output
// Enter list size -> 5
// Enter element-0 -> -10
// Enter element-1 -> 17
// Enter element-2 -> 0
// Enter element-3 -> -5
// Enter element-4 -> 5
// Array -> -10 17 0 -5 5 
// Select sorting algorithm!
// 1. Insertion sort
// 2. Bubble Sort
// 3. Selection Sort.
// Enter choice -> 2
// Bubble Sort Completed!
// Array -> -10 -5 0 5 17 
 
// Output
// Enter list size -> 4
// Enter element-0 -> -10
// Enter element-1 -> 10
// Enter element-2 -> 0
// Enter element-3 -> -5
// Array -> -10 10 0 -5
// Select sorting algorithm!
// 1. Insertion sort
// 2. Bubble Sort
// 3. Selection Sort.
// Enter choice -> 3
// Selection Sort Completed!
// Array -> -10 -5 0 10
