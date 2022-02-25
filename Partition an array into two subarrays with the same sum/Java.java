import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
 
class Main
{
    // Partition the array into two subarrays with the same sum
    public static int partition(int[] arr)
    {
        // calculate the sum of all array elements
        int total_sum = Arrays.stream(arr).sum();
 
        // variable to maintain the sum of processed elements
        int sum_so_far = 0;
 
        // do for each array element
        for (int i = 0; i < arr.length; i++)
        {
            // if sum of `A[0…i-1]` is equal to `A[i, n-1]`
            if (sum_so_far == total_sum - sum_so_far) {
                return i;
            }
 
            // update `sum_so_far` by including the value of the current element
            sum_so_far += arr[i];
        }
 
        return -1;
    }
 
    // Utility function to print subarray `arr[i, j]`
    public static void printSubarray(int[] arr, int i, int j)
    {
        System.out.println(IntStream.range(i, j + 1)
                    .mapToObj(k -> arr[k])
                    .collect(Collectors.toList()));
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 6, -4, -3, 2, 3 };
 
        // get index `i` that points to the starting of the second subarray
        int i = partition(arr);
 
        if (i != -1)
        {
            // print the first subarray, `arr[0, i-1]`
            printSubarray(arr, 0, i - 1);
 
            // print the second subarray, `arr[i, arr.length)`
            printSubarray(arr, i, arr.length - 1);
        }
        else {
            System.out.print("The array can't be partitioned");
        }
    }
}
