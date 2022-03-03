import java.util.Arrays;
import java.util.Stack;
 
class Main
{
    // Function to print all distinct combinations of length `k`, where the
    // repetition of elements is allowed
    public static void findCombinations(int[] A, int k, int i, Stack<Integer> output)
    {
        // base case: if the combination size is `k`, print it
        if (output.size() == k)
        {
            System.out.println(output);
            return;
        }
 
        // start from the previous element in the current combination
        // till the last element
        for (int j = i; j < A.length; j++)
        {
            // add current element `A[j]` to the solution and recur with the
            // same index `j` (as repeated elements are allowed in combinations)
            output.add(A[j]);
            findCombinations(A, k, j, output);
 
            // backtrack: remove the current element from the solution
            output.pop();
 
            // code to handle duplicates – skip adjacent duplicates
            while (j < A.length - 1 && A[j] == A[j + 1]) {
                j++;
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] A = { 1, 2, 1 };
        int k = 2;
 
        // if the array contains repeated elements, sort the array to
        // handle duplicates combinations
        Arrays.sort(A);
 
        Stack<Integer> output = new Stack<>();
        findCombinations(A, k, 0, output);
    }
}
