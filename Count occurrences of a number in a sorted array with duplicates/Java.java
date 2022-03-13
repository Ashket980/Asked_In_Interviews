class Main
{
    // Function to find the first or last occurrence of a given number in
    // a sorted integer array. If `searchFirst` is true, return the
    // first occurrence of the number; otherwise, return its last occurrence.
    public static int binarySearch(int[] nums, int target, boolean searchFirst)
    {
        // search space is nums[left…right]
        int left = 0;
        int right = nums.length - 1;
 
        // initialize the result by -1
        int result = -1;
 
        // loop till the search space is exhausted
        while (left <= right)
        {
            // find the mid-value in the search space and compares it with the target
            int mid = (left + right) / 2;
 
            // if the target is found, update the result
            if (target == nums[mid])
            {
                result = mid;
 
                // go on searching towards the left (lower indices)
                if (searchFirst) {
                    right = mid - 1;
                }
                // go on searching towards the right (higher indices)
                else {
                    left = mid + 1;
                }
            }
 
            // if the target is less than the middle element, discard the right half
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            // if the target is more than the middle element, discard the left half
            else {
                left = mid + 1;
            }
        }
 
        // return the found index or -1 if the element is not found
        return result;
    }
 
    public static void main(String[] args)
    {
        int[] nums = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
        int target = 5;
 
        // pass true for the first occurrence
        int first = binarySearch(nums, target, true);
 
        // pass false for the last occurrence
        int last = binarySearch(nums, target, false);
 
        int count = last - first + 1;
 
        if (first != -1) {
            System.out.println("Element " + target + " occurs " + count + " times");
        }
        else {
            System.out.println("Element not found in the array");
        }
    }
}
