#include <iostream>
#include <cmath>
using namespace std;
 
// Function to find two repeating elements in an array of size `n+2`
// having a range of elements from 1 to `n` using XOR operator
pair<int, int> findDuplicates(int arr[], int n)
{
    // take XOR of all array elements from index 0 to `n-1` and
    // all numbers in range 1 to `n`
    int result = arr[0] ^ arr[n+1];
    for (int i = 1; i <= n; i++) {
        result = result ^ arr[i] ^ i;
    }
 
    // `x` and `y` are two duplicate elements
    int x = 0, y = 0;
 
    // `result` stores `x ^ y`
 
    // find the position of the rightmost set bit in `result`
    int k = log2(result & -result);
 
    // split the array into two subarrays
    for (int i = 0; i < n + 2; i++)
    {
        // array elements that have k'th bit 1
        if (arr[i] & (1 << k)) {
            x = x ^ arr[i];
        }
 
        // array elements that have k'th bit 0
        else {
            y = y ^ arr[i];
        }
    }
 
    // split range [1, n] into two subranges
    for (int i = 1; i <= n; i++)
    {
        // number `i` has k'th bit 1
        if (i & (1 << k)) {
            x = x ^ i;
        }
 
        // number `i` has k'th bit 0
        else {
            y = y ^ i;
        }
    }
 
    return make_pair(x, y);
}
 
int main()
{
    int arr[] = { 4, 3, 6, 5, 2, 4, 1, 1 };
    int n = 6;        // array size is `n+2`
 
    pair<int, int> p = findDuplicates(arr, n);
    cout << "The duplicate elements are " << p.first << " and " << p.second;
 
    return 0;
}
