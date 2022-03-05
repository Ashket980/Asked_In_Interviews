#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
 
// Partition set `S` into two subsets, `S1` and `S2`, such that the
// difference between the sum of elements in `S1` and the sum
// of elements in `S2` is minimized
int findMinAbsDiff(vector<int> const &S, int n, int S1, int S2, auto &lookup)
{
    // Base case: if the list becomes empty, return the absolute
    // difference between both sets
    if (n < 0) {
        return abs(S1 - S2);
    }
 
    // Construct a unique map key from dynamic elements of the input.
    // Note that we can uniquely identify the subproblem with `n` and `S1` only,
    // as `S2` is nothing but `S-S1`, where `S` is the sum of all elements
    string key = to_string(n) + "|" + to_string(S1);
 
    // If the subproblem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // Case 1. Include the current item in subset `S1` and recur
        // for the remaining items `n-1`
        int inc = findMinAbsDiff(S, n - 1, S1 + S[n], S2, lookup);
 
        // Case 2. Exclude the current item from subset `S1` and recur for
        // the remaining items `n-1`
        int exc = findMinAbsDiff(S, n - 1, S1, S2 + S[n], lookup);
 
        lookup[key] = min(inc, exc);
    }
 
    return lookup[key];
}
 
int main()
{
    // Input: a set of items
    vector<int> S = { 10, 20, 15, 5, 25 };
 
    // total number of items
    int n = S.size();
 
    // create a map to store solutions to subproblems
    unordered_map<string, int> lookup;
 
    cout << "The minimum difference is " << findMinAbsDiff(S, n - 1, 0, 0, lookup);
 
    return 0;
}
