#include <stdio.h>
 
// Determine if an array can be divided into pairs such that the sum of elements
// in each pair is divisible by the given integer `k`
int findPairs(int arr[], int n, int k)
{
    // base case: input contains an odd number of elements
    // (an odd number of elements cannot be paired)
    if (n & 1) {
        return 0;
    }
 
    // create a boolean array to mark elements that formed a pair
    int visited[n];
 
    // initialize visited array by value 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
 
    // consider each element as the first element of a pair
    for (int i = 0; i < n - 1; i++)
    {
        // ignore the current element if it is already part of another pair
        if (visited[i]) {
            continue;
        }
 
        // find the first non-visited element `arr[j]` that forms a pair with `arr[i]`
        int j = i + 1;
        while (j < n)
        {
            if (!visited[j] && (arr[j] + arr[i]) % k == 0)
            {
                // pair found `(arr[i], arr[j])`
                visited[j] = 1;
                break;
            }
            j++;
        }
 
        // return 0 if pair not found for the current element
        if (j == n) {
            return 0;
        }
    }
 
    // we reach here only when each element forms a pair
    return 1;
}
 
int main(void)
{
    int arr[] = { 2, 9, 4, 1, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
 
    if (findPairs(arr, n, k)) {
        printf("Pairs can be formed");
    }
    else {
        printf("Pairs cannot be formed");
    }
 
    return 0;
}
