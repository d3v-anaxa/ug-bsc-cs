void bubble_sort(T* arr, int size){
    if(size < 2) return;
    T _t;
    for( int i = 0; i < size - 1; i++){
        for ( int j = i; j < size; j++){
            if (arr[i] <= arr[j]) continue;
            _t = arr[i];
            arr[i] = arr[j];
            arr[j] = _t;
        }
    }
}

void selection_sort(T* arr, int size){
    if (size < 2) return;
    int minIdx = 0;
    T _t;
    for( int i = 0; i < size - 1; i++){
        minIdx = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] >= arr[minIdx]) continue;
            minIdx = j;
        }
        _t = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = _t;
    }
}

void insertion_sort(T* arr, int size){
    if (size < 2) return;
    T key;
    for ( int i = 1, j = 0; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge_array( T*, int, int, int);
void merge_sort_recursion( T*, int, int);
void merge_sort(int arr[], int n) {
    int currentSize;  // Current size of subarrays to be merged
    int leftStart;    // Starting index of the left subarray
    for (currentSize = 1; currentSize <= n - 1; currentSize = 2 * currentSize) {
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
            int mid = leftStart + currentSize - 1;
            int rightEnd = (leftStart + 2 * currentSize - 1 < n - 1) ? (leftStart + 2 * currentSize - 1) : (n - 1);
            merge_array(arr, leftStart, mid, rightEnd);
        }
    }
}
/*
void merge_sort_recursion(T* arr, int start, int end){
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    merge_sort_recursion(arr, 0 , mid);
    merge_sort_recursion(arr, mid+1, end);
    merge_array(arr, start, mid, end);
}
*/
void merge_array(T* arr, int start, int mid, int end){
    int l_len = mid - start + 1,
        r_len = end - mid;
    T l_arr[l_len], r_arr[r_len];
    for(int i = 0; i < l_len; i++){
        l_arr[i] = arr[start + i];
    }
    for(int j = 0; j < r_len; j++){
        r_arr[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = start;
    while (i < l_len && j < r_len){
        if(l_arr[i] < r_arr[j]){
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    while (i < l_len){
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < r_len){
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void quick_sort(T* arr, int size){}

void shell_sort(T* arr, int size){}

void radix_sort(T* arr, int size){}

void bucket_sort(T* arr, int size){}
