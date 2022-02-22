import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
 
class Main
{
    public static int findMin(List<Integer> input, int low, int high)
    {
        // base case
        if (low > high) {
            return 0;
        }
 
        // find the minimum element in array `input[low…high]`
        int min = input.subList(low, high + 1)
                    .stream()
                    .min(Comparator.naturalOrder())
                    .get();
 
        // find the maximum element in array `input[low…high]`
        int max = input.subList(low, high + 1)
                    .stream()
                    .max(Comparator.naturalOrder())
                    .get();
 
        // if the array is not balanced
        if (2 * min <= max)
        {
            // remove the leftmost element from the array, and recur with the
            // remaining elements
            int L = 1 + findMin(input, low + 1, high);
 
            // remove the rightmost element from the array, and recur with the
            // remaining elements
            int R = 1 + findMin(input, low, high - 1);
 
            // return the minimum of two
            return Integer.min(L, R);
        }
 
        // we reach here if the array is already balanced
        return 0;
    }
 
    public static void main(String[] args)
    {
        List<Integer> input = Arrays.asList(4, 2, 6, 4, 9);
        System.out.println("The minimum number of removals is " +
                findMin(input, 0, input.size() - 1));
    }
}
