class Main
{
    // Function to find the majority element present in a given array
    public static int findMajorityElement(int[] nums)
    {
        // `m` stores the majority element (if present)
        int m = -1;
 
        // initialize counter `i` with 0
        int i = 0;
 
        // do for each element `nums[j]` in the array
        for (int j = 0; j < nums.length; j++)
        {
            // if counter `i` becomes 0
            if (i == 0)
            {
                // set the current candidate to `nums[j]`
                m = nums[j];
 
                // reset the counter to 1
                i = 1;
            }
 
            // otherwise, increment the counter if `nums[j]` is a current candidate
            else if (m == nums[j]) {
                i++;
            }
            // otherwise, decrement the counter if `nums[j]` is a current candidate
            else {
                i--;
            }
        }
 
        return m;
    }
 
    public static void main (String[] args)
    {
        // assumption: valid input (majority element is present)
        int[] nums = { 1, 8, 7, 4, 1, 2, 2, 2, 2, 2, 2 };
 
        System.out.println("The majority element is " + findMajorityElement(nums));
    }
}
