class Main
{
    // Function to find the maximum subarray sum using divide-and-conquer
    public static int findMaximumSum(int[] nums, int left, int right)
    {
        // If the array contains 0 or 1 element
        if (right == left) {
            return nums[left];
        }
 
        // Find the middle array element
        int mid = (left + right) / 2;
 
        // Find maximum subarray sum for the left subarray,
        // including the middle element
        int leftMax = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            if (sum > leftMax) {
                leftMax = sum;
            }
        }
 
        // Find maximum subarray sum for the right subarray,
        // excluding the middle element
        int rightMax = Integer.MIN_VALUE;
        sum = 0;    // reset sum to 0
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            if (sum > rightMax) {
                rightMax = sum;
            }
        }
 
        // Recursively find the maximum subarray sum for the left
        // and right subarray, and take maximum
        int maxLeftRight = Integer.max(findMaximumSum(nums, left, mid),
                                    findMaximumSum(nums, mid + 1, right));
 
        // return the maximum of the three
        return Integer.max(maxLeftRight, leftMax + rightMax);
    }
 
    // Wrapper over findMaximumSum() function
    public static int findMaximumSum(int[] nums)
    {
        // base case
        if (nums == null || nums.length == 0) {
            return 0;
        }
 
        return findMaximumSum(nums, 0, nums.length - 1);
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 2, -4, 1, 9, -6, 7, -3 };
 
        System.out.println("The maximum sum of the subarray is " +
                findMaximumSum(nums));
    }
}
