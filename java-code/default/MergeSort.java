import java.util.Arrays;

public class MergeSort {

    public  static void merge_sort(int[] array){
        MergeSortRec(array, 0, array.length - 1);
    }
    public static void MergeSortRec(int[] array, int start, int end){
        if(start >= end) return;
        int mid = start + (end - start) / 2;
        MergeSortRec(array, start, mid);
        MergeSortRec(array, mid + 1, end);

        SortArrays(array, start, mid, end);
    }

    private static void SortArrays(int[] array, int start, int mid, int end) {
        int left_length = mid - start + 1;
        int right_length = end - mid;
        int[] left_array = new int[left_length] ;
        int[] right_array = new int[right_length] ;

        System.arraycopy(array, start, left_array, 0, left_length);
        System.arraycopy(array, start + left_length , right_array, 0, right_length);

        for (int i = 0 ; i < right_length; i++)
            right_array[i] = array[mid + i + 1];

        for(int i = 0, j = 0, k = start; k <= end; k++){
            if((i < left_length) &&
                    (j >= right_length || left_array[i] <= right_array[j])){
                array[k] = left_array[i];
                i++;
            } else {
                array[k] = right_array[j];
                j++;
            }
        }

    }

    public static void main(String[] args) {
        int[] array = {-9, 0, 6, -4, 8, 3, -2};
        System.out.println(Arrays.toString(array));
        merge_sort(array);
        System.out.println(Arrays.toString(array));
    }
}
