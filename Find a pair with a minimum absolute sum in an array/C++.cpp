#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
 
// Function to find a pair in an array with an absolute minimum sum
void findPair(int arr[], int n)
{
    if (n < 2) {
        return;
    }
 
    // sort the array if it is unsorted
    // sort(arr, arr + n);
 
    // maintain two indexes pointing to endpoints of the array
    int low = 0;
    int high = n - 1;
 
    // `min` stores the minimum absolute difference
    int min = INT_MAX;
    int i, j;
 
    // reduce the search space `arr[low…high]` at each iteration of the loop
 
    // loop if `low` is less than `high`
    while (low < high)
    {
        // update the minimum if the current absolute sum is less
        if (abs(arr[high] + arr[low]) < min)
        {
            min = abs(arr[high] + arr[low]);
            i = low;
            j = high;
        }
 
        // optimization: pair with zero-sum is found
        if (min == 0) {
            break;
        }
 
        // increment `low` index if the total is less than 0;
        // decrement `high` index if the total is more than 0
        (arr[high] + arr[low] < 0)? low++: high--;
    }
 
    // print the pair
    cout << "Pair found (" << arr[i] << ", " << arr[j] << ")";
}
 
int main()
{
    int arr[] = { -6, -5, -3, 0, 2, 4, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findPair(arr, n);
 
    return 0;
}
