class Main
{
    // Function to find an element in a circularly sorted array
    public static int searchCircularArray(int[] nums, int target)
    {
        // search space is nums[left…right]
        int left = 0;
        int right = nums.length - 1;
 
        // loop till the search space is exhausted
        while (left <= right)
        {
            // find the mid-value in the search space and
            // compares it with the target
            int mid = (left + right) / 2;
 
            // if the key is found, return its index
            if (target == nums[mid]) {
                return mid;
            }
 
            // if right half nums[mid…right] is sorted and `mid` is not
            // the key element
            if (nums[mid] <= nums[right])
            {
                // compare key with nums[mid] and nums[right] to know
                // if it lies in nums[mid…right] or not
                if (target > nums[mid] && target <= nums[right])
                {
                    // go searching in the right sorted half
                    left = mid + 1;
                }
                else {
                    right = mid - 1;        // go searching left
                }
            }
 
            // if left half nums[left…mid] is sorted, and `mid` is not
            // the key element
            else {
                // compare key with nums[left] and nums[mid] to know
                // if it lies in nums[left…mid] or not
                if (target >= nums[left] && target < nums[mid])
                {
                    // go searching in the left sorted half
                    right = mid - 1;
                }
                else {
                    left = mid + 1;         // go searching right
                }
            }
        }
 
        // key not found or invalid input
        return -1;
    }
 
    public static void main(String[] args)
    {
        int[] nums = {9, 10, 2, 5, 6, 8};
        int key = 5;
 
        int index = searchCircularArray(nums, key);
 
        if (index != -1) {
            System.out.println("Element found at index " + index);
        }
        else {
            System.out.println("Element not found in the array");
        }
    }
}
