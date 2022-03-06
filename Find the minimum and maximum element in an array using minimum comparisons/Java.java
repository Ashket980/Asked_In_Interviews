class Main
{
    // Optimized solution to find the minimum and maximum number in an array
    public static void findMinAndMax(int[] nums)
    {
        // initialize minimum element by INFINITY and the maximum element by -INFINITY
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
 
        int n = nums.length;
 
        // if the array has an odd number of elements, ignore the last
        // element and consider it later
        boolean odd = (n & 1) == 1;
        if (odd) { n--; }
 
        // compare elements in pairs, i.e., nums[i] and nums[i+1]
        for (int i = 0; i < n; i = i + 2)
        {
            int maximum, minimum;
 
            // find the maximum and minimum among nums[i] and nums[i+1]
 
            if (nums[i] > nums[i + 1]) {      // 1st comparison
                minimum = nums[i + 1];
                maximum = nums[i];
            }
            else {
                minimum = nums[i];
                maximum = nums[i + 1];
            }
 
            // update max
            if (maximum > max) {        // 2nd comparison
                max = maximum;
            }
 
            // update min
            if (minimum < min) {        // 3rd comparison
                min = minimum;
            }
        }
 
        // handle the last element if the array has an odd number of elements
        if (odd)
        {
            if (nums[n] > max) {
                max = nums[n];
            }
 
            if (nums[n] < min) {
                min = nums[n];
            }
        }
 
        System.out.println("The minimum array element is " + min);
        System.out.println("The maximum array element is " + max);
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 4, 7, 5, 1, 3 };
 
        findMinAndMax(nums);
    }
}
