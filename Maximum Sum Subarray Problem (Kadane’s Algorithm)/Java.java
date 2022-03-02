class Main
{
    // Function to find the maximum sum of a contiguous subarray
    // in a given integer array (handles negative numbers as well)
    public static int kadaneNeg(int[] A)
    {
        // stores the maximum sum subarray found so far
        int maxSoFar = Integer.MIN_VALUE;
 
        // stores the maximum sum of subarray ending at the current position
        int maxEndingHere = 0;
 
        // traverse the given array
        for (int i: A)
        {
            // update the maximum sum of subarray "ending" at index `i` (by adding the
            // current element to maximum sum ending at previous index)
            maxEndingHere = maxEndingHere + i;
 
            // maximum sum should be more than the current element
            maxEndingHere = Integer.max(maxEndingHere, i);
 
            // update the result if the current subarray sum is found to be greater
            maxSoFar = Integer.max(maxSoFar, maxEndingHere);
        }
 
        return maxSoFar;
    }
 
    public static void main(String[] args)
    {
        int[] A = { -8, -3, -6, -2, -5, -4 };
 
        System.out.println("The maximum sum of a contiguous subarray is " +
                kadaneNeg(A));
    }
}
