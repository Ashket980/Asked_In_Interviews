import java.util.Arrays;
 
class Main
{
    // Function to find the length of the longest subarray with alternating
    // positive and negative elements
    public static void findLongestSubarray(int[] nums)
    {
        // base case
        if (nums == null || nums.length == 0) {
            return;
        }
 
        // stores length of longest alternating subarray found so far
        int maxLen = 1;
 
        // stores ending index of longest alternating subarray found so far
        int endIndex = 0;
 
        // stores length of longest alternating subarray ending at the current position
        int currLen = 1;
 
        // traverse the given array starting from the second index
        for (int i = 1; i < nums.length; i++)
        {
            // if the current element has an opposite sign than the previous element
            if (nums[i] * nums[i - 1] < 0)
            {
                // include the current element in the longest alternating subarray
                // ending at the previous index
                currLen++;
 
                // update result if the current subarray length is found to be greater
                if (currLen > maxLen)
                {
                    maxLen = currLen;
                    endIndex = i;
                }
            }
            // reset length if the current element has the same sign as the previous
            // element
            else {
                currLen = 1;
            }
        }
 
        int[] subarray = Arrays.copyOfRange(nums, (endIndex - maxLen + 1), endIndex + 1);
        System.out.println("The longest alternating subarray is "
                            + Arrays.toString(subarray));
    }
 
    public static void main (String[] args)
    {
        int[] nums = { 1, -2, 6, 4, -3, 2, -4, -3 };
 
        findLongestSubarray(nums);
    }
}
