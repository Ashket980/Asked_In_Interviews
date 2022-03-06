#include <stdio.h>
 
int max(int x, int y) {
    return (x > y) ? x : y;
}
 
// Function to find the length of the longest subsequence with alternate
// low and high elements.
int findLongestSequence(int A[], int n)
{
    // base case
    if (n <= 1) {
        return n;
    }
 
    // lookup table to store solutions to subproblems
    int T[n][2];
 
    /*
        `T[i][0]` stores the longest alternating subsequence till `A[0…i]`
        where `A[i]` is greater than `A[i-1]`
 
        `T[i][1]` stores the longest alternating subsequence till `A[0…i]`
        where `A[i]` is smaller than `A[i-1]`
    */
 
    // initialize matrix
    for (int i = 1; i < n; i++) {
        T[i][0] = T[i][1] = 0;
    }
 
    // base case: the first element will always be part of LAS
    T[0][0] = T[0][1] = 1;
 
    // stores result
    int result = 1;
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i < n; i++)
    {
        // do for each element `A[j]` before `A[i]`
        for (int j = 0; j < i; j++)
        {
            // If `A[i]` is greater than `A[j]`, update `T[i][0]`
            if (A[i] > A[j]) {
                T[i][0] = max(T[i][0], T[j][1] + 1);
            }
 
            // If `A[i]` is smaller than `A[j]`, update `T[i][1]`
            if (A[i] < A[j]) {
                T[i][1] = max(T[i][1], T[j][0] + 1);
            }
        }
 
        // update result by taking a maximum of both values
        if (result < max(T[i][0], T[i][1])) {
            result = max(T[i][0], T[i][1]);
        }
    }
 
    // return result
    return result;
}
 
int main(void)
{
    int A[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
    int n = sizeof(A) / sizeof(A[0]);
 
    printf("The length of the longest alternating subsequence is %d",
            findLongestSequence(A, n));
 
    return 0;
}
