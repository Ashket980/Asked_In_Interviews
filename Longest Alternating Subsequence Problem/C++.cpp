#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Utility function to find the length of the longest alternating subsequence.
// If the `flag` is true, the next element should be greater.
// If the `flag` is false, the next element should be smaller.
int findLongestSequence(vector<int> const &A, int start, int end, bool flag,
                        auto &lookup)
{
    // if the subproblem is seen for the first time, solve it and
    // store its result in the lookup table
    if (lookup[start][flag] == 0)
    {
        int result = 0;
        for (int i = start; i <= end; i++)
        {
            // include `A[i]` as next high in subsequence and flip `flag`
            // for next subsequence
            if (flag && A[i - 1] < A[i]) {
                result = max(result, 1 + findLongestSequence(A, i + 1, end,
                                            !flag, lookup));
            }
 
            // include `A[i]` as next low in subsequence and flip `flag`
            // for next subsequence
            else if (!flag && A[i - 1] > A[i]) {
                result = max(result, 1 + findLongestSequence(A, i + 1, end,
                                            !flag, lookup));
            }
 
            // don't include `A[i]` in subsequence
            else {
                result = max(result, findLongestSequence(A, i + 1, end, flag, lookup));
            }
        }
 
        lookup[start][flag] = result;
    }
 
    // return solution to the current subproblem
    return lookup[start][flag];
}
 
// Function to find the length of the longest subsequence with alternate
// low and high elements. It calls the `findLongestSequence()` method.
int longestSequence(vector<int> const &A)
{
    int n = A.size();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // Fix the first element and recur for the remaining elements.
    // There are two possibilities:
 
    // lookup table to store solutions to a subproblem
    // `max(lookup[i][0], lookup[i][1])` stores the longest sequence till `A[0…i]`
    vector<vector<int>> lookup(n + 1, vector<int>(2));
 
    // 1. The next element is greater (pass true)
    // 2. The next element is smaller (pass false)
    return 1 + max(findLongestSequence(A, 1, n - 1, true, lookup),
            findLongestSequence(A, 1, n - 1, false, lookup));
}
 
int main()
{
    vector<int> A = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
 
    // Find the longest alternating subsequence
    cout << "The length of the longest alternating subsequence is "
         << longestSequence(A);
 
    return 0;
}
