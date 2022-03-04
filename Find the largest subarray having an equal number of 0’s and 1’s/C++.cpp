#include <iostream>
#include <unordered_map>
using namespace std;
 
// Function to find the largest subarray having an equal number
// of 0's and 1's
void findLargestSubarray(int nums[], int n)
{
    // create an empty map to store the ending index of the first subarray
    // having some sum
    unordered_map<int, int> map;
 
    // insert (0, -1) pair into the set to handle the case when a
    // subarray with zero-sum starts from index 0
    map[0] = -1;
 
    // `len` stores the maximum length of subarray with zero-sum
    int len = 0;
 
    // stores ending index of the largest subarray having zero-sum
    int ending_index = -1;
 
    int sum = 0;
 
    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far (replace 0 with -1)
        sum += (nums[i] == 0)? -1 : 1;
 
        // if the sum is seen before
        if (map.find(sum) != map.end())
        {
            // update length and ending index of largest subarray having zero-sum
            if (len < i - map[sum])
            {
                len = i - map[sum];
                ending_index = i;
            }
        }
        // if the sum is seen for the first time, insert the sum with its
        // index into the map
        else {
            map[sum] = i;
        }
    }
 
    // print the subarray if present
    if (ending_index != -1) {
        cout << "[" << ending_index - len + 1 << ", " << ending_index << "]";
    }
    else {
        cout << "No subarray exists";
    }
}
 
int main()
{
    int nums[] = { 0, 0, 1, 0, 1, 0, 0 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    findLargestSubarray(nums, n);
 
    return 0;
}
