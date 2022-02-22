#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Merge two subarrays, `arr[low… mid]` and `arr[mid+1… high]`,
// such that all positive numbers follow negative numbers
void merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low;
 
    // copy negative elements from the left subarray
    for (int i = low; i <= mid; i++)
    {
        if (arr[i] < 0) {
            aux[k++] = arr[i];
        }
    }
 
    // copy negative elements from the right subarray
    for (int j = mid + 1; j <= high; j++)
    {
        if (arr[j] < 0) {
            aux[k++] = arr[j];
        }
    }
 
    // copy positive elements from the left subarray
    for (int i = low; i <= mid; i++)
    {
        if (arr[i] >= 0) {
            aux[k++] = arr[i];
        }
    }
 
    // copy positive elements from the right subarray
    for (int j = mid + 1; j <= high; j++)
    {
        if (arr[j] >= 0) {
            aux[k++] = arr[j];
        }
    }
 
    // copy back to the original array to reflect the relative order
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}
 
// Segregate positive and negative integers using a mergesort-like routine
void partition(int arr[], int aux[], int low, int high)
{
    // base case
    if (high <= low) {
        return;
    }
 
    // find midpoint
    int mid = (low + ((high - low) >> 1));
 
    partition(arr, aux, low, mid);          // split/merge left half
    partition(arr, aux, mid + 1, high);     // split/merge right half
 
    merge(arr, aux, low, mid, high);        // join the two half runs
}
 
int main()
{
    int arr[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    int aux[n];
    for (int i = 0; i < n; i++) {
        aux[i] = arr[i];
    }
 
    partition(arr, aux, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}
