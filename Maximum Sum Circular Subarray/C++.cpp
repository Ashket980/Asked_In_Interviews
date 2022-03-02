#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
 
// Function to find contiguous subarray with the largest sum
// in a given set of integers
int kadane(int arr[], int n)
{
    // stores the sum of maximum subarray found so far
    int max_so_far = 0;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // update the maximum sum of subarray "ending" at index `i` (by adding the
        // current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + arr[i];
 
        // if the maximum sum is negative, set it to 0 (which represents
        // an empty subarray)
        max_ending_here = max(max_ending_here, 0);
 
        // update result if the current subarray sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here);
    }
 
    return max_so_far;
}
 
// Function to find the maximum sum circular subarray in a given array
int runCircularKadane(int arr[], int n)
{
    // empty array has sum of 0
    if (n == 0) {
        return 0;
    }
 
    // find the maximum element present in a given array
    int max_num = *max_element(arr, arr + n);
 
    // if the array contains all negative values, return the maximum element
    if (max_num < 0) {
        return max_num;
    }
 
    // negate all the array elements
    for (int i = 0; i < n; i++) {
        arr[i] = -arr[i];
    }
 
    // run Kadane’s algorithm on the modified array
    int neg_max_sum = kadane(arr, n);
 
    // restore the array
    for (int i = 0; i < n; i++) {
        arr[i] = -arr[i];
    }
 
    /* Return the maximum of the following:
        1. Sum returned by Kadane’s algorithm on the original array.
        2. Sum returned by Kadane’s algorithm on the modified array +
           the sum of all the array elements.
    */
 
    return max(kadane(arr, n), accumulate(arr, arr + n, 0) + neg_max_sum);
}
 
int main()
{
    int arr[] = { 2, 1, -5, 4, -3, 1, -3, 4, -1 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "The sum of the subarray with the largest sum is " <<
            runCircularKadane(arr, n);
 
    return 0;
}
