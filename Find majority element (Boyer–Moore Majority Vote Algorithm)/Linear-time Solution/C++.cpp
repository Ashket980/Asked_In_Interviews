#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Function to find the majority element present in a given array
int findMajorityElement(vector<int> const &nums)
{
    // create an empty map
    unordered_map<int, int> map;
 
    // get input size
    int n = nums.size();
 
    // 1. Store each element's frequency in a map
    for (int i = 0; i < n; i++) {
        map[nums[i]]++;
    }
 
    // 2. Return the element if its count is more than `n/2`
    for (auto pair: map)
    {
        if (pair.second > n/2) {
            return pair.first;
        }
    }
 
    // Note that we can merge steps 2 and 3 into one
    /* for (int i = 0; i < n; i++)
    {
        if (++map[nums[i]] > n/2) {
            return nums[i];
        }
    } */
 
    // return -1 if no majority element is present
    return -1;
}
 
int main()
{
    vector<int> input = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
 
    int result = findMajorityElement(input);
    if (result != -1) {
        cout << "The majority element is " << result;
    }
    else {
        cout << "The majority element doesn't exist";
    }
 
    return 0;
}
