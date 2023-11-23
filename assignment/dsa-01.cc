/*
   Write a program to search an element from a list. Give user the option to perform Linear
   or Binary search. Use Template functions.
*/

/* ALGO
   Linear Search:
   1. Initialize a list 'vector' with elements.
   2. Initialize a variable 'searchElement' with the element to be searched.
   3. For each 'element' in 'vector':
   3.1. If 'element' is equal to 'searchElement':
   3.1.1. Print "Element found at position", current index + 1.
   3.1.2. End the search.
   4. If the loop completes without finding the 'searchElement':
   4.1. Print "Element not found in the vector."

   Binary Search:
   1. Initialize a sorted list 'vector' with elements.
   2. Initialize variables 'left' and 'right' to point to the start and end of 'vector' respectively.
   3. Initialize a variable 'searchElement' with the element to be searched.
   4. While 'left' is less than or equal to 'right':
   4.1. Calculate 'mid' as the average of 'left' and 'right'.
   4.2. If 'searchElement' is equal to the element at 'mid' in 'vector':
   4.2.1. Print "Element found at position", mid + 1.
   4.2.2. End the search.
   4.3. Else if 'searchElement' is less than the element at 'mid' in 'vector':
   4.3.1. Update 'right' to 'mid - 1'.
   4.4. Else:
   4.4.1. Update 'left' to 'mid + 1'.
   5. If the loop completes without finding the 'searchElement':
   a. Print "Element not found in the vector."

*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
int LinearSearch(const std::vector<T>& arr, const T& key){
    for (int i = 0; i < (int)arr.size(); i++)
        if (key == arr[i]) return i;
    return -1;
}

template<typename T>
int BinarySearch(const std::vector<T>& arr, const T& key){
    int left = 0,
        right = arr.size() - 1;

    while (left <= right){
        int mid = left + ( right - left )/2;

        if (key == arr[mid]) return mid;
        else if (key < arr[mid]) right = mid - 1;
        else if (key > arr[mid]) left = mid + 1;
    }
    return -1;
}

int main(void){
    vector<int> array = {};
    unsigned int size = 0;
    int target;

    cout << "Enter number of list elements -> " && cin >> size;
    for(int i = 0; i < (int)size; i++){
        int elem;
        cout << "Enter element-" << i << " -> " && cin >> elem;
        array.push_back(elem);
    }
    sort(array.begin(), array.end());
    cout << "Array -> ";
    for(int e : array)
        cout << e << " ";
    cout << endl;


    cout << "Enter target element -> " && cin >> target;

    int LinearSearchRes = LinearSearch(array, target);
    int BinarySearchRes = BinarySearch(array, target);

    int choice = 0;
    cout 
        << "Select searching algorithm\n"
        << "1. Linear search \n"
        << "2. Binary search \n"
        << "Enter choice -> ";
    cin >> choice;

    if (LinearSearchRes == -1 || BinarySearchRes == -1) {
        cout << "Target not found!\n";
        return 1;
    }
    switch (choice){
        case 2:
            cout << "Binary search -> index-" << BinarySearchRes << endl;
            break;

        default:
            cout << "Linear search -> index-" << LinearSearchRes << endl;
            break;
    }
    return 0;
}

/* OUTPUT
   Enter number of list elements -> 4
   Enter element-0 -> 10
   Enter element-1 -> 20
   Enter element-2 -> 30
   Enter element-3 -> 40
   Array -> 10 20 30 40 
   Enter target element -> 20
   Select searching algorithm
   1. Linear search 
   2. Binary search 
   Enter choice -> 2
   Binary search -> index-1
   */

/* OUTPUT
   Enter number of list elements -> 4
   Enter element-0 -> -10
   Enter element-1 -> 10
   Enter element-2 -> 20
   Enter element-3 -> 30
   Array -> -10 10 20 30
   Enter target element -> 20
   Select searching algorithm
   1. Linear search
   2. Binary search
   Enter choice -> 2
   Binary search -> index-2
   */
