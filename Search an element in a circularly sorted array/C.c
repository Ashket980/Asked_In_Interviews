#include <stdio.h>
 
// Function to find an element `target` in a circularly sorted array
int searchCircularArray(int nums[], int n, int target)
{
    // search space is nums[low…high]
    int low = 0, high = n - 1;
 
    // loop till the search space is exhausted
    while (low <= high)
    {
        // find the mid-value in the search space and
        // compares it with the target
        int mid = (low + high)/2;
 
        // if the target is found, return its index
        if (target == nums[mid]) {
            return mid;
        }
 
        // if right half nums[mid…high] is sorted and `mid` is not
        // the target element
        if (nums[mid] <= nums[high])
        {
            // compare target with nums[mid] and nums[high]to know
            // if it lies in nums[mid…high] or not
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;      // go searching in the right sorted half
            }
            else {
                high = mid - 1;     // go searching left
            }
        }
 
        // if left half nums[low…mid] is sorted, and `mid` is not
        // the target element
        else {
            // compare target with nums[low] and nums[mid] to know
            // if it lies in nums[low…mid] or not
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;     // go searching in the left sorted half
            }
            else {
                low = mid + 1;      // go searching right
            }
        }
    }
 
    // target not found or invalid input
    return -1;
}
 
int main(void)
{
    int nums[] = {9, 10, 2, 5, 6, 8};
    int target = 5;
 
    int n = sizeof(nums)/sizeof(nums[0]);
    int index = searchCircularArray(nums, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
