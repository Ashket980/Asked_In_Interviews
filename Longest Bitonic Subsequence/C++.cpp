#include <iostream>
#include <vector>
#include <list>
using namespace std;
 
// Function to find the longest bitonic subsequence in an array
void LBS(vector<int> const &nums)
{
    int n = nums.size();
 
    // base case
    if (n == 0) {
        return;
    }
 
    // `I[i]` store the longest increasing subsequence, ending at `nums[i]`
    list<int> I[n];
    I[0].push_back(nums[0]);
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (I[i].size() < I[j].size() && nums[i] > nums[j]) {
                I[i] = I[j];
            }
        }
        I[i].push_back(nums[i]);
    }
 
    // `D[i]` stores the longest decreasing subsequence, starting from `nums[i]`
    list<int> D[n];
    D[n - 1].push_front(nums[n - 1]);
 
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (D[i].size() < D[j].size() && nums[i] > nums[j]) {
                D[i] = D[j];
            }
        }
        D[i].push_front(nums[i]);
    }
 
    // uncomment the following code to print contents of vector LIS and LDS
    /* for (int i = 0; i < n; i++)
    {
        cout << "LIS[" << i << "] — ";
        for (int j: I[i]) {
            cout << j << " ";
        }
 
        cout << "\t\tLDS[" << i << "] — ";
        for (int j: D[i]) {
            cout << j << " ";
        }
        cout << endl;
    } */
 
    // find the peak element index
    int peak = 0;
    for (int i = 1; i < n; i++)
    {
        if ((I[i].size() + D[i].size()) > (I[peak].size() + D[peak].size())) {
            peak = i;
        }
    }
 
    cout << "The longest bitonic subsequence is ";
 
    // print longest increasing subsequence ending at peak element
    for (int i: I[peak]) {
        cout << i << " ";
    }
 
    // pop the front element of LDS as it points to the same element as the rear of LIS
    D[peak].pop_front();
 
    // print longest decreasing subsequence starting from the peak element
    for (int i: D[peak]) {
        cout << i << " ";
    }
}
 
int main()
{
    vector<int> nums = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
 
    LBS(nums);
 
    return 0;
}
