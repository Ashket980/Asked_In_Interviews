import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;
 
class Main
{
    // Optimized method to find the equilibrium index of an array
    public static void findEquilibriumIndex(int[] A)
    {
        // `total` stores the sum of all the array elements
        int total = IntStream.of(A).sum();
 
        // `right` stores the sum of elements of subarray `A[i+1…n)`
        int right = 0;
 
        // maintain a list of indices
        List<Integer> indices = new ArrayList<>();
 
        // traverse the array from right to left
        for (int i = A.length - 1; i >= 0; i--)
        {
            /* `i` is an equilibrium index if the sum of elements of subarray
            `A[0…i-1]` is equal to the sum of elements of the subarray A[i+1…n),
            i.e., (A[0] + A[1] + … + A[i-1]) = (A[i+1] + A[i+2] + … + A[n-1]) */
 
            // sum of elements of the left subarray `A[0…i-1]` is
            // (total - (A[i] + right))
            if (right == total - (A[i] + right)) {
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
