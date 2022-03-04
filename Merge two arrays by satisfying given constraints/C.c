#include <stdio.h>
 
// Function to merge `X[0… m]` and `Y[0… n]` into `X[0… m+n+1]`
void merge(int X[], int Y[], int m, int n)
{
    // size of `X[]` is `k+1`
    int k = m + n + 1;
 
    // run if X[] or Y[] has elements left
    while (m >= 0 && n >= 0)
    {
        // put the next greater element in the next free position in `X[]` from the end
        if (X[m] > Y[n]) {
            X[k--] = X[m--];
        }
        else {
            X[k--] = Y[n--];
        }
    }
 
    // copy the remaining elements of `Y[]` (if any) to `X[]`
    while (n >= 0) {
        X[k--] = Y[n--];
    }
 
    // fill `Y[]` with all zeroes
    for (int i = 0; i < n; i++) {
        Y[i] = 0;
    }
}
 
// The function moves non-empty elements in `X[]` in the
// beginning and then merge them with `Y[]`
void rearrange(int X[], int Y[], int m, int n)
{
    // return if `X` is empty
    if (m == 0) {
        return;
    }
 
    // moves non-empty elements of `X[]` at the beginning
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        if (X[i] != 0) {
            X[k++] = X[i];
        }
    }
 
    // merge `X[0 … k-1]` and `Y[0 … n-1]` into `X[0 … m-1]`
    merge(X, Y, k - 1, n - 1);
}
 
int main()
{
    // vacant cells in `X[]` is represented by 0
    int X[] = { 0, 2, 0, 3, 0, 5, 6, 0, 0 };
    int Y[] = { 1, 8, 9, 10, 15 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
 
    /* Validate input before calling `rearrange()`
        1. Both arrays `X[]` and `Y[]` should be sorted (ignore 0's in `X[]`)
        2. Size of array `X[]` >= size of array `Y[]` (i.e., `m >= n`)
        3. Total number of vacant cells in array `X[]` = size of array `Y[]` */
 
    // merge `Y[]` into `X[]`
    rearrange(X, Y, m, n);
 
    // print merged array
    for (int i = 0; i < m; i++) {
        printf("%d ", X[i]);
    }
 
    return 0;
}
