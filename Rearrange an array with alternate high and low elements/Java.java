import java.util.Arrays;
 
class Main
{
    // Utility function to swap elements `A[i]` and `A[j]` in the array
    private static void swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
 
    // Function to rearrange the array such that every second element
    // of the array is greater than its left and right elements
    public static void rearrangeArray(int[] A)
    {
        // start from the second element and increment index
        // by 2 for each iteration of the loop
        for (int i = 1; i < A.length; i += 2)
        {
            // if the previous element is greater than the current element,
            // swap the elements
            if (A[i - 1] > A[i]) {
                swap(A, i - 1, i);
            }
 
            // if the next element is greater than the current element,
            // swap the elements
            if (i + 1 < A.length && A[i + 1] > A[i]) {
                swap(A, i + 1, i);
            }
        }
    }
 
    public static void main (String[] args)
    {
        int[] A = { 9, 6, 8, 3, 7 };
 
        rearrangeArray(A);
 
        // print output array
        System.out.println(Arrays.toString(A));
    }
}
