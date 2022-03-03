#include <stdio.h>
#include <stdlib.h>
 
// Function to find the length of the longest bitonic subarray in an array
void findBitonicSubarray(int A[], int n)
{
    int end_index = 0, max_len = 1, i = 0;
 
    while (i + 1 < n)
    {
        // check for the longest bitonic subarray starting at `A[i]`
 
        // reset length to 1
        int len = 1;
 
        // run till sequence is increasing
        while (i + 1 < n && A[i] < A[i + 1]) {
            i++, len++;
        }
 
        // run till sequence is decreasing
        while (i + 1 < n && A[i] > A[i + 1]) {
            i++, len++;
        }
 
        // run till sequence is equal
        while (i + 1 < n && A[i] == A[i + 1]) {
            i++;
        }
 
        // update the longest bitonic subarray if required
        if (len > max_len)
        {
            max_len = len;
            end_index = i;
        }
    }
 
    // print the longest bitonic subarray
    printf("The length of the longest bitonic subarray is %d\n", max_len);
    printf("The longest bitonic subarray indices is [%d, %d]",
            end_index - max_len + 1, end_index);
}
 
int main(void)
{
    int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findBitonicSubarray(A, n);
 
    return 0;
}
