#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Utility function to print subarray `nums[i…j]`
void printSubarray(vector<int> const &nums, int i, int j)
{
    cout << "[";
    for (int k = i; k < j; k++) {
        cout << nums[k] << ", ";
    }
    cout << nums[j] << "]";
}
 
// Function to find the length of the longest subarray with alternating
// positive and negative elements
void findLongestSubarray(vector<int> const &nums)
{
    // base case
    if (nums.size() == 0) {
        return;
    }
 
    // stores length of longest alternating subarray found so far
    int max_len = 1;
 
    // stores ending index of longest alternating subarray found so far
    int ending_index = 0;
 
    // stores length of alternating subarray ending at the current position
    int curr_len = 1;
 
    // traverse the given array starting from the second index
    for (int i = 1; i < nums.size(); i++)
    {
        // if the current element has an opposite sign than the previous element
        if (nums[i] * nums[i - 1] < 0)
        {
            // include the current element in the longest alternating subarray ending
            // at the previous index
            curr_len++;
 
            // update result if the current subarray length is found to be greater
            if (curr_len > max_len)
            {
                max_len = curr_len;
                ending_index = i;
            }
        }
        // reset length if the current element has the same sign as the previous
        // element
        else {
            curr_len = 1;
        }
    }
 
    cout << "The longest alternating subarray is ";
    printSubarray(nums, (ending_index - max_len + 1), ending_index);
}
 
int main()
{
    vector<int> nums = { 1, -2, 6, 4, -3, 2, -4, -3 };
 
    findLongestSubarray(nums);
 
    return 0;
}
