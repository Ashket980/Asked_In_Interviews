import java.lang.Math;
 
class Main
{
    // Function to check if subarray `A[i…j]` is formed by consecutive integers.
    // Here, `min` and `max` denote the minimum and maximum element in the subarray.
    private static boolean isConsecutive(int[] A, int i, int j, int min, int max)
    {
        // for an array to contain consecutive integers, the difference
        // between the maximum and minimum element in it should be exactly `j-i`
        if (max - min != j - i) {
            return false;
        }
 
        // create a visited array (we can also use a set)
        boolean visited[] = new boolean[j - i + 1];
 
        // traverse the subarray and check if each element appears
        // only once
        for (int k = i; k <= j; k++)
        {
            // if the element is seen before, return false
            if (visited[A[k] - min]) {
                return false;
            }
 
            // mark the element as seen
            visited[A[k] - min] = true;
        }
 
        // we reach here when all elements in the array are distinct
        return true;
    }
 
    // Find the largest subarray formed by consecutive integers
    public static void findMaxSubarray(int[] A)
    {
        int len = 1;
        int start = 0, end = 0;
 
        // consider each subarray formed by `A[i…j]`
 
        // `i` denotes the beginning of the subarray
        for (int i = 0; i < A.length - 1; i++)
        {
            // stores the minimum and maximum element in subarray `A[i…j]`
            int min_val = A[i], max_val = A[i];
 
            // `j` denotes the end of the subarray
            for (int j = i + 1; j < A.length; j++)
            {
                // update the minimum and maximum elements of the subarray
                min_val = Math.min(min_val, A[j]);
                max_val = Math.max(max_val, A[j]);
 
                // check if `A[i…j]` is formed by consecutive integers
                if (isConsecutive(A, i, j, min_val, max_val))
                {
                    if (len < max_val - min_val + 1)
                    {
                        len = max_val - min_val + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
 
        // print the maximum length subarray
        System.out.println("The largest subarray is [" + start + ", " + end + "]");
    }
 
    public static void main (String[] args)
    {
        int[] A = { 2, 0, 2, 1, 4, 3, 1, 0 };
 
        findMaxSubarray(A);
    }
}
