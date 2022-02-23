#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
 
// Find a sorted triplet in a given array
bool findTriplet(vector<int> const &arr, auto &tuple)
{
    // size of the input array
    int n = arr.size();
 
    // a sorted triplet is not possible on input having less than 3 elements
    if (n < 3) {
        return false;
    }
 
    // `min[i] = j`, when `0 <= j < i` and `arr[j] < arr[i]`
    // `min[i] = -1` when `arr[j] > arr[i]` for every index `j < i`
    vector<int> min(n, -1);
 
    // keep an index to the minimum element found so far
    // while traversing the array from left to right
    int min_index_so_far = 0;
 
    // start from the 1st index as `min[0]` would be -1
    for (int i = 1; i < n; i++)
    {
        // update `min_index_so_far` if the current index has less value;
        // otherwise, update `min[i]` with the smallest index to its left
        if (arr[i] < arr[min_index_so_far]) {
            min_index_so_far = i;
        }
        else if (arr[i] > arr[min_index_so_far]) {
            min[i] = min_index_so_far;
        }
    }
 
    // `max[i] = j`, when `i < j < n` and `arr[i] < arr[j]`
    // `max[i] = -1` when `arr[j] < arr[i]` for every index `j > i`
    vector<int> max(n, -1);
 
    // keep an index to the maximum element found so far
    // while traversing the array from right to left
    int max_index_so_far = n - 1;
 
    // start from the second last index as `max[n-1]` would be `-1`
    for (int i = n - 2; i >= 0; i--)
    {
        // update `max_index_so_far` if the current index has more value;
        // otherwise, update `max[i]` with the greatest index to its right
        if (arr[i] > arr[max_index_so_far]) {
            max_index_so_far = i;
        }
        else if (arr[i] < arr[max_index_so_far]) {
            max[i] = max_index_so_far;
        }
    }
 
    // traverse the array again and find an index with both a min
    // element on its left and a max element on its right
    for (int i = 0; i < n; i++)
    {
        if (min[i] != -1 && max[i] != -1)
        {
            // create a tuple of the found triplet and returns true
            tuple = make_tuple(min[i], i, max[i]);
            return true;
        }
    }
 
    // no triplet found
    return false;
}
 
int main()
{
    // input array
    vector<int> input = { 5, 4, 3, 7, 6, 1, 9 };
 
    // create a tuple to store the triplet
    tuple<int, int, int> triplet;
 
    // find triplet
    if (findTriplet(input, triplet))
    {
        cout << "Triplet found: ("
             << input[get<0>(triplet)] << ", "
             << input[get<1>(triplet)] << ", "
             << input[get<2>(triplet)] << ")";
    }
    else {
        cout << "Triplet not found";
    }
 
    return 0;
}
