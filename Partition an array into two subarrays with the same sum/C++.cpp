#include <iostream>
#include <numeric>
#include <iterator>
using namespace std;
 
// Partition the array into two subarrays with the same sum
int partition(int arr[], int n)
{
    // calculate the sum of all array elements
    int total_sum = accumulate(arr, arr + n, 0);
 
    // variable to maintain the sum of processed elements
    int sum_so_far = 0;
 
    // do for each array element
    for (int i = 0; i < n; i++)
    {
        // if the sum of `A[0…i-1]` is equal to `A[i, n-1]`
        if (sum_so_far == total_sum - sum_so_far) {
            return i;
        }
 
        // update `sum_so_far` by including the value of the current element
        sum_so_far += arr[i];
    }
 
    return -1;
}
 
int main()
{
    int arr[] = { 6, -4, -3, 2, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // get index `i` that points to the starting of the second subarray
    int i = partition(arr, n);
 
    if (i != -1)
    {
        // print the first subarray, `arr[0, i-1]`
        copy(arr, arr + i, ostream_iterator<int>(cout, " "));
 
        cout << endl;
 
        // print the second subarray, `arr[i, n-1]`
        copy(arr + i, arr + n, ostream_iterator<int>(cout, " "));
    }
    else {
        cout << "The array can't be partitioned";
    }
 
    return 0;
}
