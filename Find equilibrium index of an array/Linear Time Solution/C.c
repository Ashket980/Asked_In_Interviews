#include <stdio.h>
 
// Function to find the equilibrium index of an array
void findEquilibriumIndex(int A[], int n)
{
    // `left[i]` stores the sum of elements of subarray `A[0…i-1]`
    int left[n];
 
    left[0] = 0;
 
    // traverse the array from left to right
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] + A[i - 1];
    }
 
    // `right` stores the sum of elements of subarray `A[i+1…n)`
    int right = 0;
 
    // traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        /* If the sum of elements of subarray `A[0…i-1]` is equal to
           the sum of elements of the subarray `A[i+1…n)` i.e.
           `(A[0] + A[1] + … + A[i-1])` = `(A[i+1] + A[i+2] + … + A[n-1])`
        */
 
        if (left[i] == right) {
            printf("Equilibrium Index found at %d\n", i);
        }
 
        // new right is `A[i] + (A[i+1] + A[i+2] + … + A[n-1])`
        right += A[i];
    }
}
 
int main(void)
{
    int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findEquilibriumIndex(A, n);
 
    return 0;
}
