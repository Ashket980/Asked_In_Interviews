class Main
{
    // Function to find the length of the longest subsequence with alternate
    // low and high elements.
    public static int findLongestSequence(int[] A)
    {
        // base case
        if (A.length <= 1) {
            return A.length;
        }
 
        // lookup table to store solutions to subproblems
        int T[][] = new int[A.length][2];
 
        /*
            `T[i][0]` stores the longest alternating subsequence till `A[0…i]`
            where `A[i]` is greater than `A[i-1]`
 
            `T[i][1]` stores the longest alternating subsequence till `A[0…i]`
            where `A[i]` is smaller than `A[i-1]`
        */
 
        // stores result
        int result = 1;
 
        // base case: the first element will always be part of LAS
        T[0][0] = T[0][1] = 1;
 
        // fill the lookup table in a bottom-up manner
        for (int i = 1; i < A.length; i++)
        {
            // do for each element `A[j]` before `A[i]`
            for (int j = 0; j < i; j++)
            {
                // If `A[i]` is greater than `A[j]`, update `T[i][0]`
                if (A[i] > A[j]) {
                    T[i][0] = Math.max(T[i][0], T[j][1] + 1);
                }
 
                // If `A[i]` is smaller than `A[j]`, update `T[i][1]`
                if (A[i] < A[j]) {
                    T[i][1] = Math.max(T[i][1], T[j][0] + 1);
                }
            }
 
            // update result by taking a maximum of both values
            if (result < Math.max(T[i][0], T[i][1])) {
                result = Math.max(T[i][0], T[i][1]);
            }
        }
 
        // return result
        return result;
    }
 
    public static void main(String[] args)
    {
        int[] A = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
 
        System.out.println("The length of the longest alternating subsequence is "
                + findLongestSequence(A));
    }
}
