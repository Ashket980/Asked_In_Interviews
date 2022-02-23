import java.util.stream.IntStream;
 
class Main
{
    // Function to find index `i` in the array such that the sum of the left
    // subarray of `A[i]` is equal to the sum of its right subarray
    public static void findBreakPoint(int[] A)
    {
        // base case
        if (A.length == 0) {
            return;
        }
 
        // calculate the sum of all array elements
        int total = IntStream.of(A).sum();
 
        // stores sum of the left subarray
        int left_sum = A[0];
 
        // start from index 1 to find non-empty subarrays
        for (int i = 1; i < A.length - 1; i++)
        {
            // if the sum of `A[0…i-1]` is equal to `A[i+1, n-1]`
            if (left_sum == total - (A[i] + left_sum)) {
                System.out.println("The index is " + i);
            }
 
            // update the left subarray sum
            left_sum += A[i];
        }
    }
 
    public static void main(String[] args)
    {
        int[] A = { -1, 6, 3, 1, -2, 3, 3 };
 
        // divide the array into two non-empty subarrays with equal sum
        findBreakPoint(A);
    }
}
