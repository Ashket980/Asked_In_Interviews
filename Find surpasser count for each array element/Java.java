import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
 
class Main
{
    // Function to merge two sorted subarrays `arr[low … mid]` and
    // `arr[mid+1 … high]`
    public static void merge(int[] arr, int[] aux, int low, int mid, int high,
                            Map<Integer, Integer> count)
    {
        int k = low, i = low, j = mid + 1;
        int c = 0;
 
        // run if there are elements in the left and right runs
        while (i <= mid && j <= high)
        {
            if (arr[i] > arr[j])
            {
                // update surpasser count of `arr[i]`
                count.put(arr[i], count.getOrDefault(arr[i], 0) + c);
 
                aux[k++] = arr[i++];
            }
            else {
                aux[k++] = arr[j++];
                c++;
            }
        }
 
        // copy remaining elements
        while (i <= mid)
        {
            count.put(arr[i], count.getOrDefault(arr[i], 0) + c);
            aux[k++] = arr[i++];
        }
 
        /* no need to copy the second half (since the remaining items
           are already in their correct position in the temporary array) */
 
        // copy back to the original array to reflect sorted order
        while (low <= high)
        {
            arr[low] = aux[low];
            low++;
        }
    }
 
    // Function to sort array `arr[low…high]` in descending order
    public static void mergesort(int[] arr, int[] aux, int low, int high,
                                Map<Integer, Integer> count)
    {
        // base case: run size is less than or equal to 1
        if (high <= low) {
            return;
        }
 
        // find midpoint
        int mid = (low + ((high - low) >> 1));
 
        // recursively split runs into two halves until run size == 1,
        // merge them, and return up the call chain
 
        mergesort(arr, aux, low, mid, count);
        mergesort(arr, aux, mid + 1, high, count);
 
        merge(arr, aux, low, mid, high, count);
    }
 
    // Function to find the surpasser count for each array element
    public static Map<Integer, Integer> getSurpasserCount(int[] A)
    {
        Map<Integer, Integer> count = new HashMap<>();
 
        // create two copies of the original array
        int[] aux = Arrays.copyOf(A, A.length);
        int[] arr = Arrays.copyOf(A, A.length);
 
        // sort array `arr[]` in descending order using auxiliary array aux[]
        mergesort(arr, aux, 0, A.length - 1, count);
 
        return count;
    }
 
    public static void main(String[] args)
    {
        int[] A = { 4, 6, 3, 9, 7, 10 };
 
        // find the surpasser count for array elements
        Map<Integer, Integer> surpasserCount = getSurpasserCount(A);
 
        for (int value: A) {
            System.out.print(surpasserCount.get(value) + " ");
        }
    }
}
