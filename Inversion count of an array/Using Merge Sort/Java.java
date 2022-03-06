import java.util.Arrays;
 
class Main
{
    // Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
    public static int merge(int[] arr, int[] aux, int low, int mid, int high)
    {
        int k = low, i = low, j = mid + 1;
        int inversionCount = 0;
 
        // while there are elements in the left and right runs
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j]) {
                aux[k++] = arr[i++];
            }
            else {
                aux[k++] = arr[j++];
                inversionCount += (mid - i + 1);    // NOTE
            }
        }
 
        // copy remaining elements
        while (i <= mid) {
            aux[k++] = arr[i++];
        }
 
        /* no need to copy the second half (since the remaining items
           are already in their correct position in the temporary array) */
 
        // copy back to the original array to reflect sorted order
        for (i = low; i <= high; i++) {
            arr[i] = aux[i];
        }
 
        return inversionCount;
    }
 
    // Sort array `arr[low…high]` using auxiliary array `aux`
    public static int mergesort(int[] arr, int[] aux, int low, int high)
    {
        // base case
        if (high <= low) {        // if run size <= 1
            return 0;
        }
 
        // find midpoint
        int mid = (low + ((high - low) >> 1));
        int inversionCount = 0;
 
        // recursively split runs into two halves until run size <= 1,
        // then merges them and return up the call chain
 
        // split/merge left half
        inversionCount += mergesort(arr, aux, low, mid);
 
        // split/merge right half
        inversionCount += mergesort(arr, aux, mid + 1, high);
 
        // merge the two half runs
        inversionCount += merge(arr, aux, low, mid, high);
 
        return inversionCount;
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 1, 9, 6, 4, 5 };
        int[] aux = Arrays.copyOf(arr, arr.length);
 
        // get the inversion count by performing merge sort on arr
        System.out.println("The inversion count is " +
                        mergesort(arr, aux, 0, arr.length - 1));
    }
}
