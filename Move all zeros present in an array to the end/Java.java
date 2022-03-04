import java.util.Arrays;
 
class Main
{
    // Function to move all zeros present in the array to the end
    public static void reorder(int[] A)
    {
        // `k` stores the index of the next available position
        int k = 0;
 
        // do for each element
        for (int i: A)
        {
            // if the current element is non-zero, put the element at the
            // next free position in the array
            if (i != 0) {
                A[k++] = i;
            }
        }
 
        // move all 0's to the end of the array (remaining indices)
        for (int i = k; i < A.length; i++) {
            A[i] = 0;
        }
    }
 
    public static void main(String[] args)
    {
        int[] A = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
 
        reorder(A);
        System.out.println(Arrays.toString(A));
    }
}
