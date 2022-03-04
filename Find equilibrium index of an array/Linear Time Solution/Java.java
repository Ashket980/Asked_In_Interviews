
import java.util.ArrayList;
import java.util.List;
 
class Main
{
    // Function to find the equilibrium index of an array
    public static void findEquilibriumIndex(int A[])
    {
        // `left[i]` stores the sum of elements of subarray `A[0…i-1]`
        int left[] = new int[A.length];
 
        left[0] = 0;
 
        // traverse the array from left to right
        for (int i = 1; i < A.length; i++) {
            left[i] = left[i - 1] + A[i - 1];
        }
 
        // `right` stores the sum of elements of subarray `A[i+1…n)`
        int right = 0;
 
        // maintain a list of indices
        List<Integer> indices = new ArrayList<>();
 
        // traverse the array from right to left
        for (int i = A.length - 1; i >= 0; i--)
        {
            /* If the sum of elements of subarray `A[0…i-1]` is equal to
               the sum of elements of the subarray `A[i+1…n)` i.e.
               (A[0] + … + A[i-1]) = (A[i+1] + A[i+2] + … + A[n-1]) */
 
            if (left[i] == right) {
                indices.add(i);
            }
 
            // new right is `A[i] + (A[i+1] + A[i+2] + … + A[n-1])`
            right += A[i];
        }
 
        System.out.println("Equilibrium Index found at " + indices);
    }
 
    public static void main (String[] args)
    {
        int[] A = { 0, -3, 5, -4, -2, 3, 1, 0 };
 
        findEquilibriumIndex(A);
    }
}
