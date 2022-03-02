#include <iostream>
#include <set>
#include <vector>
#include <experimental/iterator>
using namespace std;
 
// Function to print all distinct combinations of length `k`
void findCombinations(vector<int> const &arr, int i, int k,
                set<vector<int>> &subarrays, vector<int> &out)
{
    // invalid input
    if (arr.size() == 0 || k > arr.size()) {
        return;
    }
 
    // base case: combination size is `k`
    if (k == 0) {
        subarrays.insert(out);
        return;
    }
 
    // start from the next index till the last index
    for (int j = i; j < arr.size(); j++)
    {
        // add current element `arr[j]` to the solution and recur for next index
        // `j+1` with one less element `k-1`
        out.push_back(arr[j]);
        findCombinations(arr, j + 1, k - 1, subarrays, out);
        out.pop_back();        // backtrack
    }
}
 
template <typename T>
void printVector(vector<T> const &input)
{
    cout << "[";
    copy(begin(input),
            end(input),
            experimental::make_ostream_joiner(cout, ", "));
    cout << "]\n";
}
 
int main()
{
    vector<int> arr = { 1, 2, 3 };
    int k = 2;
 
    // set to store all combinations
    set<vector<int>> subarrays;
 
    // vector to store a combination
    vector<int> out;
 
    // process elements from left to right
    findCombinations(arr, 0, k, subarrays, out);
 
    // print subarrays
    for (auto const &vec: subarrays) {
        printVector(vec);
    }
 
    return 0;
}
