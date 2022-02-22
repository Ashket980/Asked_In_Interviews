import java.util.Arrays;
 
class Main
{
    // Merge two subarrays, `arr[low… mid]` and `arr[mid+1… high]`,
    // such that all positive numbers follow negative numbers
    public static void merge(int[] arr, int[] aux, int low, int mid, int high)
    {
        int k = low;
 
        // copy negative elements from the left subarray
        for (int i = low; i <= mid; i++)
        {
            if (arr[i] < 0) {
                aux[k++] = arr[i];
            }
        }
 
        // copy negative elements from the right subarray
        for (int j = mid + 1; j <= high; j++)
        {
            if (arr[j] < 0) {
                aux[k++] = arr[j];
            }
        }
 
        // copy positive elements from the left subarray
        for (int i = low; i <= mid; i++)
        {
            if (arr[i] >= 0) {
                aux[k++] = arr[i];
            }
        }
 
        // copy positive elements from the right subarray
        for (int j = mid + 1; j <= high; j++)
        {
            if (arr[j] >= 0) {
                aux[k++] = arr[j];
            }
        }
 
        // copy back to the original array to reflect sorted order
        for (int i = low; i <= high; i++) {
            arr[i] = aux[i];
        }
    }
 
    // Segregate positive and negative integers using a mergesort-like routine
    public static void partition(int[] arr, int[] aux, int low, int high)
    {
        // Base case
        if (high <= low) {
            return;
        }
 
        // find midpoint
        int mid = (low + ((high - low) >> 1));
 
        partition(arr, aux, low, mid);          // split/merge left half
        partition(arr, aux, mid + 1, high);     // split/merge right half
 
        merge(arr, aux, low, mid, high);        // join the two half runs
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 9, -3, 5, -2, -8, -6, 1, 3 };
        int[] aux = Arrays.copyOf(arr, arr.length);
 
        partition(arr, aux, 0, arr.length - 1);
 
        System.out.println(Arrays.toString(arr));
    }
}
