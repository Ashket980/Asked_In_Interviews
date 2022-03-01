#include <stdio.h>
#include <limits.h>
 
// Utility function to find a maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Function to calculate the maximum difference between two elements in an
// array such that the smaller element appears before the larger element
int getMaxDiff(int arr[], int n)
{
    int diff = INT_MIN;
    if (n == 0) {
        return diff;
    }
 
    int max_so_far = arr[n-1];
 
    // traverse the array from the right and keep track of the maximum element
    for (int i = n - 2; i >= 0; i--)
    {
        // update `max_so_far` if the current element is greater than the
        // maximum element
        if (arr[i] >= max_so_far) {
            max_so_far = arr[i];
        }
        // if the current element is less than the maximum element,
        // then update the difference if required
        else {
            diff = max (diff, max_so_far - arr[i]);
        }
    }
 
    // return difference
    return diff;
}
 
int main()
{
    int arr[] = { 2, 7, 9, 5, 1, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int result = getMaxDiff(arr, n);
    if (result != INT_MIN) {
        printf("The maximum difference is %d", result);
    }
 
    return 0;
}
