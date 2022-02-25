#include <stdio.h>
#include <limits.h>
#include <math.h>
 
// Utility function to find a minimum of two integers
int min (int x, int y) {
    return (x < y) ? x : y;
}
 
// Function to find the minimum difference between the index of two
// elements `x` and `y` present in an array
int findMinDifference(int arr[], int n, int x, int y)
{
    // base case
    if (n <= 1) {
        return 0;
    }
 
    int x_index = n, y_index = n;
    int min_diff = INT_MAX;
 
    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // if the current element is `x`
        if (arr[i] == x)
        {
            // set `x_index` to the current index
            x_index = i;
 
            // if `y` is seen before, update the result if required
            if (y_index != n) {
                min_diff = min(min_diff, abs(x_index - y_index));
            }
        }
 
        // if the current element is `y`
        if (arr[i] == y)
        {
            // set `y_index` to the current index
            y_index = i;
 
            // if `x` is seen before, update the result if required
            if (x_index != n) {
                min_diff = min(min_diff, abs(x_index - y_index));
            }
        }
    }
 
    return min_diff;
}
 
int main(void)
{
    int arr[] = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 };
    int x = 2, y = 5;
 
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff = findMinDifference(arr, n, x, y);
 
    if (diff != INT_MAX) {
        printf("The minimum difference is %d", diff);
    }
    else {
        printf("Invalid input");
    }
 
    return 0;
}
