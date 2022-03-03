#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
 
int find_duplicate(vector<int> const &nums)
{
    int size = nums.size();
 
    int actual_sum = accumulate(nums.begin(), nums.end(), 0);
    int expected_sum = size * (size - 1) / 2;
 
    return actual_sum - expected_sum;
}
 
int main()
{
    vector<int> nums = { 1, 2, 3, 4, 4 };
 
    cout << "The duplicate element is " << find_duplicate(nums);
 
    return 0;
}
