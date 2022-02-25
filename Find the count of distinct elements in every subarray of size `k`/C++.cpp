#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
// Function to find the count of distinct elements in every subarray
// of size `k` in an array
void findDistinctCount(vector<int> const &input, int k)
{
    // map to store the frequency of elements in the current window of size `k`
    unordered_map<int, int> freq;
 
    // maintains the count of distinct elements in every subarray of size `k`
    int distinct = 0;
 
    // loop through the array
    for (int i = 0; i < input.size(); i++)
    {
        // ignore the first `k` elements
        if (i >= k)
        {
            // remove the first element from the subarray by reducing its
            // frequency in the map
            freq[input[i - k]]--;
 
            // reduce the distinct count if we are left with 0
            if (freq[input[i - k]] == 0) {
                distinct--;
            }
        }
 
        // add the current element to the subarray by incrementing its
        // count in the map
        freq[input[i]]++;
 
        // increment distinct count by 1 if element occurs for the first
        // time in the current window
        if (freq[input[i]] == 1) {
            distinct++;
        }
 
        // print count of distinct elements in the current subarray
        if (i >= k - 1)
        {
            cout << "The count of distinct elements in subarray [" <<
                (i - k + 1) << ", " << i << "]" << " is " << distinct << endl;
        }
    }
}
 
int main()
{
    vector<int> input = { 1, 1, 2, 1, 3 };
    int k = 3;
 
    findDistinctCount(input, k);
 
    return 0;
}
