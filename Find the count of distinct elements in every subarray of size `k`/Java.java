import java.util.HashMap;
import java.util.Map;
 
class Main
{
    // Function to find the count of distinct elements in every subarray
    // of size `k` in the array
    public static void findDistinctCount(int[] A, int k)
    {
        // map to store the frequency of elements in the current window of size `k`
        Map<Integer, Integer> freq = new HashMap<>();
 
        // maintains the count of distinct elements in every subarray of size `k`
        int distinct = 0;
 
        // loop through the array
        for (int i = 0; i < A.length; i++)
        {
            // ignore the first `k` elements
            if (i >= k)
            {
                // remove the first element from the subarray by reducing its
                // frequency in the map
                freq.put(A[i - k], freq.getOrDefault(A[i - k], 0) - 1);
 
                // reduce the distinct count if we are left with 0
                if (freq.get(A[i - k]) == 0) {
                    distinct--;
                }
            }
 
            // add the current element to the subarray by incrementing its
            // count in the map
            freq.put(A[i], freq.getOrDefault(A[i], 0) + 1);
 
            // increment distinct count by 1 if element occurs for the first
            // time in the current window
            if (freq.get(A[i]) == 1) {
                distinct++;
            }
 
            // print count of distinct elements in the current subarray
            if (i >= k - 1)
            {
                System.out.println("The count of distinct elements in subarray [" +
                        (i - k + 1) + ", " + i + "]" + " is " + distinct);
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] input = { 1, 1, 2, 1, 3 };
        int k = 3;
 
        findDistinctCount(input, k);
    }
}
