class Main
{
    // Function to calculate the maximum difference between two elements in an
    // array such that a smaller element appears before a larger element
    public static int getMaxDiff(int[] A)
    {
        int diff = Integer.MIN_VALUE;
        int n = A.length;
 
        if (n == 0) {
            return diff;
        }
        int max_so_far = A[n-1];
 
        // traverse the array from the right and keep track of the maximum element
        for (int i = n - 2; i >= 0; i--)
        {
            // update `max_so_far` if the current element is greater than the
            // maximum element
            if (A[i] >= max_so_far) {
                max_so_far = A[i];
            }
            // if the current element is less than the maximum element,
            // then update the difference if required
            else {
                diff = Integer.max(diff, max_so_far - A[i]);
            }
        }
 
        // return difference
        return diff;
    }
 
    public static void main(String[] args)
    {
        int[] A = { 2, 7, 9, 5, 1, 3, 5 };
 
        int diff = getMaxDiff(A);
        if (diff != Integer.MIN_VALUE) {
            System.out.print("The maximum difference is " + diff);
        }
    }
}
