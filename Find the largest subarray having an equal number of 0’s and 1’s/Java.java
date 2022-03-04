import java.util.Map;
import java.util.HashMap;
 
class Main
{
    // Function to find the largest subarray having an equal number
    // of 0's and 1's
    public static void findLargestSubarray(int[] nums)
    {
        // create an empty `HashMap` to store the ending index of the first
        // subarray having some sum
        Map<Integer, Integer> map = new HashMap<>();
 
        // insert (0, -1) pair into the set to handle the case when a
        // subarray with zero-sum starts from index 0
        map.put(0, -1);
 
        // `len` stores the maximum length of subarray with zero-sum
        int len = 0;
 
        // stores ending index of the largest subarray having zero-sum
        int ending_index = -1;
 
        int sum = 0;
 
        // Traverse through the given array
        for (int i = 0; i < nums.length; i++)
        {
            // sum of elements so far (replace 0 with -1)
            sum += (nums[i] == 0)? -1: 1;
 
            // if the sum is seen before
            if (map.containsKey(sum))
            {
                // update length and ending index of largest subarray having zero-sum
                if (len < i - map.get(sum))
                {
                    len = i - map.get(sum);
                    ending_index = i;
                }
            }
            // if the sum is seen for the first time, insert the sum with its
            // index into the map
            else {
                map.put(sum, i);
            }
        }
 
        // print the subarray if present
        if (ending_index != -1)
        {
            System.out.println("[" + (ending_index - len + 1) + ", " +
                                    ending_index + "]");
        }
        else {
            System.out.println("No subarray exists");
        }
    }
 
    public static void main (String[] args)
    {
        int[] nums = { 0, 0, 1, 0, 1, 0, 0 };
 
        findLargestSubarray(nums);
    }
}
