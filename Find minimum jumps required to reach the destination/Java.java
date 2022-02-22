class Main
{
    // Find minimum jumps required to reach the destination
    public static int findMinJumps(int[] nums, int i, int n, int[] lookup)
    {
        // base case: destination is reached
        if (i == n - 1) {
            return 0;
        }
 
        // base case: array index out of bound or destination is
        // unreachable from the source
        if (i >= n || nums[i] == 0) {
            return Integer.MAX_VALUE;
        }
 
        // if the subproblem is seen before
        if (lookup[i] != 0) {
            return lookup[i];
        }
 
        // find the minimum jumps required to reach the destination by considering
        // the minimum of all elements reachable from `nums[i]`
        int min_jumps = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + nums[i]; j++)
        {
            int cost = findMinJumps(nums, j, n, lookup);
            if (cost != Integer.MAX_VALUE) {
                min_jumps = Math.min(min_jumps, cost + 1);
            }
        }
 
        // if the subproblem is seen for the first time
        return (lookup[i] = min_jumps);
    }
 
    public static int findMinimumJumps(int[] nums)
    {
        // base case
        if (nums == null || nums.length == 0) {
            return 0;
        }
 
        // create an auxiliary array to store solutions to the subproblems and
        // initialize it with 0
        int[] lookup = new int[nums.length];
 
        return findMinJumps(nums, 0, nums.length, lookup);
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 1, 3, 6, 1, 0, 9 };
 
        System.out.println("The minimum jumps required to reach the destination are " +
                                    findMinimumJumps(nums));
    }
}
