#include <iostream>
#include <climits>
using namespace std;
 
// Function to find the maximum sum of a contiguous subarray
// in a given integer array (handles negative numbers as well)
int kadaneNeg(int arr[], int n)
{
    // stores the maximum sum subarray found so far
    int max_so_far = INT_MIN;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    // traverse the given array
    for (int i = 1; i < n; i++)
    {
        // update the maximum sum of subarray "ending" at index `i` (by adding the
        // current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + arr[i];
 
        // maximum sum should be more than the current element
        max_ending_here = max(max_ending_here, arr[i]);
 
        // update the result if the current subarray sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here);
    }
 
    return max_so_far;
}
 
int main()
{
    int arr[] = { -8, -3, -6, -2, -5, -4 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "The maximum sum of a contiguous subarray is " << kadaneNeg(arr, n);
 
    return 0;
}
