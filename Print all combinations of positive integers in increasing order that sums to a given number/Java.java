import java.util.Arrays;
import java.util.stream.Collectors;
 
class Main
{
    // Recursive function to print all combinations of positive integers
    // in increasing order that sum to a given number
    public static void printCombinations(int[] nums, int i, int sum, int sum_left)
    {
        // to maintain the increasing order, start the loop from the
        // previous number stored in `nums[]`
        int prev_num = (i > 0) ? nums[i - 1] : 1;
        for (int k = prev_num; k <= sum; k++)
        {
            // set the next array element to `k`
            nums[i] = k;
 
            // recur with the sum left and the next location in the array
            if (sum_left > k) {
                printCombinations(nums, i + 1, sum, sum_left - k);
            }
 
            // if the sum is found
            if (sum_left == k)
            {
                System.out.println(Arrays.stream(nums).limit(i + 1).boxed()
                                .collect(Collectors.toList()));
            }
        }
    }
 
    // Wrapper over `printCombinations()` method
    public static void findCombinations(int sum)
    {
        // create a temporary array for storing the combinations
        int[] nums = new int[sum];
 
        // recur for all combinations
        int starting_index = 0;
        printCombinations(nums, starting_index, sum, sum);
    }
 
    public static void main(String[] args)
    {
        int sum = 5;
        findCombinations(sum);
    }
}
