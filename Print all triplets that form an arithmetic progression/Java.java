class Main
{
    // Function to print all triplets that forms arithmetic progression
    // in a given sorted array
    public static void findAllTriplets(int[] A)
    {
        if (A.length < 3) {
            return;
        }
 
        // consider `A[j]` as the middle element of AP
        for (int j = 1; j < A.length - 1; j++)
        {
            // start with the left and right index of `j`
            int i = j - 1, k = j + 1;
 
            // Find all `i` and `k` such that `(i, j, k)` form an AP triplet
            while (i >= 0 && k < A.length)
            {
                // if `(A[i], A[j], A[k])` forms a triplet
                if (A[i] + A[k] == 2 * A[j])
                {
                    // print the triplet
                    System.out.println(A[i] + " " + A[j] + " " + A[k]);
 
                    // Since the array is sorted and elements are distinct
                    k++; i--;
                }
                // otherwise, if `(A[i] + A[k])` is less than `2×A[j]` then
                // try next `k`. Else, try the previous `i`.
                else if (A[i] + A[k] < 2 * A[j]) {
                    k++;
                }
                else {
                    i--;
                }
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] A = { 1, 3, 5, 6, 8, 9, 15 };
 
        findAllTriplets(A);
    }
}
