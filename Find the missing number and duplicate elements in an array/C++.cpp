#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
// Function to find the missing number and duplicate element using XOR operator
// in an array of size `n` and range of elements from 1 to `n`
pair<int, int> findMissingAndDuplicate(vector<int> const &arr)
{
    int n = arr.size();
 
    // take XOR of all array elements from index 0 to `n-1`
    // all numbers in range 1 to `n`
    int result = n;
    for (int i = 0; i < n; i++) {
        result = result ^ arr[i] ^ i;
    }
 
    // `x` and `y` stores the duplicate element and missing number
    int x = 0, y = 0;
 
    // `result` stores `x ^ y`
 
    // find the position of the rightmost set bit in result
    int k = log2(result & -result);
 
    // split the array into two subarrays
    for (int val: arr)
    {
        // array elements that have k'th bit 1
        if (val & (1 << k)) {
            x = x ^ val;
        }
        // array elements that have k'th bit 0
        else {
            y = y ^ val;
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
 
    // linear search for the missing element
    if (find(arr.begin(), arr.end(), x) == arr.end()) {
        return make_pair(y, x);
    }
 
    return make_pair(x, y);
}
 
int main()
{
    vector<int> arr = { 4, 3, 6, 5, 2, 4 };
 
    pair<int, int> p = findMissingAndDuplicate(arr);
 
    cout << "The duplicate and missing elements are "
         << p.first << " and " << p.second;
 
    return 0;
}
