#include <stdio.h>
 
// Function to print all triplets that forms geometric progression
// in a given sorted array
void findAllTriplets(int A[], int n)
{
    if (n < 3) {
        return;
    }
 
    // One by one, fix every element as a middle element
    for (int j = 1; j < n - 1; j++)
    {
        // Initialize `i` and `k` for current `j`
        int i = j - 1, k = j + 1;
 
        // Find all `i` and `k` such that `(i, j, k)` form a GP triplet
        while (1)
        {
            // If `A[j]/A[i] = r`, and `A[k]/A[j] = r`, and `r` is an integer,
            // `(i, j, k)` forms a GP
            while (i >= 0 && k < n && (A[j] % A[i] == 0) &&
                    (A[k] % A[j] == 0) && (A[j] / A[i] == A[k] / A[j]))
            {
                // print the triplet
                printf("%d %d %d\n", A[i], A[j], A[k]);
 
                // since the array is sorted and elements are distinct
                k++ , i--;
            }
 
            if (i < 0 || k >= n) {
                break;
            }
 
            // If `A[j]` is multiple of `A[i]` and `A[k]` is multiple of `A[j]`,
            // then `A[j] / A[i] != A[k] / A[j]`; compare their values to
            // move to the next `k` or previous `i`
            if (A[j] % A[i] == 0 && A[k] % A[j] == 0)
            {
                if (A[j] / A[i] < A[k] / A[j]) {
                    i--;
                }
                else {
                    k++;
                }
            }
 
            // Otherwise, if `A[j]` is a multiple of `A[i]`, try next `k`.
            // Else, try the previous `i`.
            else if (A[j] % A[i] == 0) {
                k++;
            }
            else {
                i--;
            }
        }
    }
}
 
int main()
{
    int A[] = { 1, 2, 6, 10, 18, 54 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findAllTriplets(A, n);
 
    return 0;
}
