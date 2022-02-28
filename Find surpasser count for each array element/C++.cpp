#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
 
// Function to merge two sorted subarrays `arr[low … mid]` and
// `arr[mid+1 … high]`
void merge(int arr[], int aux[], int low, int mid, int high,
            auto &surpasser_count)
{
    int k = low, i = low, j = mid + 1;
    int count = 0;
 
    // run if there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            // update surpasser count of `arr[i]`
            surpasser_count[arr[i]] += count;
 
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            count++;
        }
    }
 
    // copy remaining elements
    while (i <= mid)
    {
        surpasser_count[arr[i]] += count;
        aux[k++] = arr[i++];
    }
 
    /* no need to copy the second half (since the remaining items
       are already in their correct position in the temporary array) */
 
    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}
 
// Function to sort array `arr[low…high]` in descending order
void merge_sort(int arr[], int aux[], int low, int high,
                auto &surpasser_count)
{
    // base case: run size is less than or equal to 1
    if (high <= low) {
        return;
    }
 
    // find midpoint
    int mid = (low + ((high - low) >> 1));
 
    // recursively split runs into two halves until run size == 1,
    // merge them, and return up the call chain
 
    merge_sort(arr, aux, low, mid, surpasser_count);
    merge_sort(arr, aux, mid + 1, high, surpasser_count);
 
    merge(arr, aux, low, mid, high, surpasser_count);
}
 
// Function to find the surpasser count for each array element
auto surpasserCount(int const A[], int n)
{
    unordered_map<int, int> surpasser_count;
 
    // create two copies of the original array
    int aux[n], arr[n];
    memcpy(aux, A, n * sizeof(A[0]));
    memcpy(arr, A, n * sizeof(A[0]));
 
    // sort array `arr[]` in descending order using auxiliary array aux[]
    merge_sort(arr, aux, 0, n - 1, surpasser_count);
 
    return surpasser_count;
}
 
int main()
{
    int arr[] = { 4, 6, 3, 9, 7, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // find the surpasser count for array elements
    unordered_map<int, int> surpasser_count = surpasserCount(arr, n);
    for (int i = 0; i < n; i++) {
        cout << surpasser_count[arr[i]] << " ";
    }
 
    return 0;
}
