#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
// Optimized solution to find the minimum and maximum number in an array
void findMinAndMax(vector<int> const &nums, int &min, int &max)
{
    // initialize minimum element by INFINITY and the maximum element by -INFINITY
    max = INT_MIN, min = INT_MAX;
    
    int n = nums.size();
 
    // if the array has an odd number of elements, ignore the last
    // element and consider it later
    bool odd = n & 1;
    if (odd) {
        n--;    // comparison
    }
 
    // compare elements in pairs, i.e., nums[i] and nums[i+1]
    for (int i = 0; i < n; i = i + 2)
    {
        int maximum, minimum;
 
        // find the maximum and minimum among nums[i] and nums[i+1]
 
        if (nums[i] > nums[i + 1]) {  // 1st comparison
            minimum = nums[i + 1],
            maximum = nums[i];
        }
        else {
            minimum = nums[i],
            maximum = nums[i + 1];
        }
 
        // update max
        if (maximum > max) {        // 2nd comparison
            max = maximum;
        }
 
        // update min
        if (minimum < min) {        // 3rd comparison
            min = minimum;
        }
    }
 
    // handle the last element if the array has an odd number of elements
 
    if (odd)                        // comparison
    {
        if (nums[n] > max) {         // extra comparison for an odd element
            max = nums[n];
        }
 
        if (nums[n] < min) {         // extra comparison for an odd element
            min = nums[n];
        }
    }
}
 
int main()
{
    vector<int> nums = { 4, 7, 5, 1, 3 };
 
    // to store minimum and maximum element, respectively
    int min, max;
 
    findMinAndMax(nums, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
 
    return 0;
}
