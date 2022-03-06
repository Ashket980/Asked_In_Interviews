#include <stdio.h>
#include <limits.h>
 
// Utility function to find the maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Function to find the maximum subarray sum using divide-and-conquer
int maximum_sum(int nums[], int low, int high)
{
    // If the array contains 0 or 1 element
    if (high <= low) {
        return nums[low];
    }
 
    // Find the middle array element
    int mid = (low + high) / 2;
 
    // Find maximum subarray sum for the left subarray,
    // including the middle element
    int left_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }
 
    // Find maximum subarray sum for the right subarray,
    // excluding the middle element
    int right_max = INT_MIN;
    sum = 0;    // reset sum to 0
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }
 
    // Recursively find the maximum subarray sum for the left
    // and right subarray, and take maximum
    int max_left_right = max(maximum_sum(nums, low, mid),
                            maximum_sum(nums, mid + 1, high));
 
    // return the maximum of the three
    return max(max_left_right, left_max + right_max);
}
 
int main(void)
{
    int arr[] = { 2, -4, 1, 9, -6, 7, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("The maximum sum of the subarray is %d",
            maximum_sum(arr, 0, n - 1));
 
    return 0;
}
