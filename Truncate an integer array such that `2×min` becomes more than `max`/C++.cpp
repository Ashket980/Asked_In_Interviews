#include <iostream>
#include <algorithm>
using namespace std;
 
int findMin(int arr[], int low, int high)
{
    // base case
    if (low > high) {
        return 0;
    }
 
    // find the minimum and the maximum elements in array `arr[low…high]`
    int min = *min_element(arr + low, arr + high + 1);
    int max = *max_element(arr + low, arr + high + 1);
 
    // if the array is not balanced
    if (2 * min <= max)
    {
        // remove the leftmost element from the array, and recur with the
        // remaining elements
        int L = 1 + findMin(arr, low + 1, high);
 
        // remove the rightmost element from the array, and recur with the
        // remaining elements
        int R = 1 + findMin(arr, low, high - 1);
 
        // return the minimum of two
        return std::min(L, R);
    }
 
    // we reach here if the array is already balanced
    return 0;
}
 
int main()
{
    int arr[] = { 4, 2, 6, 4, 9 };
    int n = end(arr) - begin(arr);
 
    cout << "The minimum number of removals is " << findMin(arr, 0, n - 1) << endl;
 
    return 0;
}
