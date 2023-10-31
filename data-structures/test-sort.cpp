#include "sort.hpp"

using namespace std;

void print(T* arr, int size){
    cout << "Array elements -> ";
    for(int i = 0; i < size; i++){
        cout << " " << arr[i];
        if ( i+1 >= size) continue;
        if ( arr[i] == arr[i+1]) cout << " " << "=";
        else if ( arr[i] < arr[i+1]) cout << " " << "<";
        else  cout << " " << ">";
    }   cout << endl;
}

void populate(T* arr, int size){
    for (int i = 0; i < size; i++){
        cout << "Enter elem-" << (i+1) << " -> ";
        cin >> arr[i];
    }
}

void populate_rand(T* arr, int size){
    srand(time(0));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % (T)1000 - 500;
    }
}

int main(void){
    T* arr = 0x0;
    int size = 0;
    int choice = 0;
    cout << "Enter the size of array : " && cin >> size;

    arr = new T[size];

    1 ? populate_rand( arr, size) : populate( arr, size);
    print( arr, size);

    cout 
        << "1. bubble sort\n"
        << "2. selection sort\n"
        << "3. insertion sort\n"
        << "4. merge sort\n"
        << "Enter choice : ";
    cin >> choice;
    switch(choice) {
        case 1:
            bubble_sort( arr, size);
            break;
        case 2:
            selection_sort( arr, size);
            break;
        case 3:
            insertion_sort( arr, size);
            break;
        case 4:
            merge_sort( arr, size);
            break;
        default:
            cout << "Array not sorted!\n";
            break;
    }
    
    print( arr, size);
    return 0;
}
