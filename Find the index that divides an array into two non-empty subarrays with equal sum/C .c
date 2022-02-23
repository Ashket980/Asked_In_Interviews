#include <stdio.h>
 
// Function to find index `i` in an array such that the sum of the left
// subarray of `A[i]` is equal to the sum of its right subarray
void findBreakPoint(int A[], int n)
{
    // base case
    if (n == 0) {
        return;
    }
 
    int total = 0;
 
    // calculate the sum of all array elements
    for (int i = 0; i < n; i++) {
        total += A[i];
    }
 
    // stores sum of the left subarray
    int left_sum = A[0];
 
    // start from index 1 to find non-empty subarrays
    for (int i = 1; i < n - 1; i++)
    {
        // if the sum of `A[0…i-1]` is equal to `A[i+1, n-1]`
        if (left_sum == total - (A[i] + left_sum)) {
            printf("The index is %d\n", i);
        }
 
        // update the left subarray sum
        left_sum += A[i];
    }
}
 
int main(void)
{
    int A[] = { -1, 6, 3, 1, -2, 3, 3 };
    int n = sizeof(A)/sizeof(A[0]);
 
    // divide the array into two non-empty subarrays with equal sum
    findBreakPoint(A, n);
 
    return 0;
}
