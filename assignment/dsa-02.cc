/*
   WAP using templates to sort a list of elements. Give user the option to perform sorting
   using Insertion sort, Bubble sort or Selection sort.
*/

/* ALGO
   1. Insertion Sort
   1.1. Initialize a list 'vector' with elements.
   1.2. For 'i' from 1 to length of 'vector':
   1.2.1. Initialize a variable 'key' with the element at index 'i' in 'vector'.
   1.2.2. Initialize a variable 'j' to 'i - 1'.
   1.2.3. While 'j' is greater than or equal to 0 and 'vector[j]' is greater than 'key':
   1.2.3.1. Move 'vector[j]' one step ahead to 'j + 1'.
   1.2.3.2. Decrease 'j' by 1.
   1.2.4. Place 'key' at 'j + 1' in 'vector'.

   2. Bubble Sort
   2.1. Initialize a list 'vector' with elements.
   2.2. For 'i' from 0 to length of 'vector' - 1:
   2.2.1. For 'j' from 0 to length of 'vector' - 'i' - 1:
   2.2.1.1. If 'vector[j]' is greater than 'vector[j + 1]':
   2.2.1.1.1. Swap 'vector[j]' and 'vector[j + 1]'.

   3. Insertion Sort
   3.1. Initialize a list 'vector' with elements.
   3.2. For 'i' from 0 to length of 'vector' - 1:
   3.2.1. Initialize a variable 'minIndex' with 'i'.
   3.2.2. For 'j' from 'i + 1' to length of 'vector':
   3.2.2.1. If 'vector[j]' is less than 'vector[minIndex]':
   3.2.2.1.1. Update 'minIndex' with 'j'.
   3.2.3. If 'minIndex' is not 'i':
   3.2.3.1. Swap 'vector[i]' and 'vector[minIndex]'.

 */

#include <bits/stdc++.h>
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
    for (int i = 0; i < (int)arr.size(); i++){
        for (int j = i; j < (int)arr.size(); j++){
            if (arr[i] > arr[j])
                swap(arr[i] , arr[j]);
        }
    }
    cout << "Bubble Sort Completed!\n";
}

template<typename T>
void SelectionSort(vector<T> &arr){
    for(int i = 0; i < (int)arr.size() - 1;){
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
    int size, choice;
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
        case 1: InsertionSort(array);
                break;
        case 3: SelectionSort(array);
                break;
        default: BubbleSort(array);
                 break;
    }   cout << "Array -> ";
    for (defType x : array)
        cout << x << " ";
    cout << endl;
    return 0;
}

/* OUTPUT
   Enter list size -> 5
   Enter element-0 -> 11
   Enter element-1 -> -10
   Enter element-2 -> 13
   Enter element-3 -> 010
   Enter element-4 -> -100
   Array -> 11 -10 13 10 -100
   Select sorting algorithm!
   1. Insertion sort
   2. Bubble Sort
   3. Selection Sort.
   Enter choice -> 3
   Selection Sort Completed!
   Array -> -100 -10 10 11 13
   */

/* OUTPUT
   Enter list size -> 4
   Enter element-0 -> 10
   Enter element-1 -> -100
   Enter element-2 -> 1024
   Enter element-3 -> -256
   Array -> 10 -100 1024 -256
   Select sorting algorithm!
   1. Insertion sort
   2. Bubble Sort
   3. Selection Sort.
   Enter choice -> 2
   Bubble Sort Completed!
   Array -> -256 -100 10 1024
   */
