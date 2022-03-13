#include <stdio.h>
 
// Function to find the first or last occurrence of a given number in
// a sorted integer array. If `searchFirst` is true, return the
// first occurrence of the number; otherwise, return its last occurrence.
int binarySearch(int nums[], int n, int target, int searchFirst)
{
    // search space is nums[low…high]
    int low = 0, high = n - 1;
 
    // initialize the result by -1
    int result = -1;
 
    // loop till the search space is exhausted
    while (low <= high)
    {
        // find the mid-value in the search space and compares it with the target
        int mid = (low + high)/2;
 
        // if the target is found, update the result
        if (target == nums[mid])
        {
            result = mid;
 
            // go on searching towards the left (lower indices)
            if (searchFirst) {
                high = mid - 1;
            }
            // go on searching towards the right (higher indices)
            else {
                low = mid + 1;
            }
        }
 
        // if the target is less than the middle element, discard the right half
        else if (target < nums[mid]) {
            high = mid - 1;
        }
        // if the target is more than the middle element, discard the left half
        else {
            low = mid + 1;
        }
    }
 
    // return the found index or -1 if the element is not found
    return result;
}
 
int main(void)
{
    int nums[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int target = 5;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    // pass value 1 for the first occurrence
    int first = binarySearch(nums, n, target, 1);
 
    // pass value 0 for the last occurrence
    int last = binarySearch(nums, n, target, 0);
 
    int count = last - first + 1;
 
    if (first != -1) {
        printf("Element %d occurs %d times", target, count);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
