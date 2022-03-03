#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to print the contents of the vector
void printVector(vector<int> const &out)
{
    for (auto it = out.begin(); it != out.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
 
// Function to print all distinct combinations of length `k`, where the
// repetition of elements is allowed
void findCombinations(int arr[], vector<int> &out, int k, int i, int n)
{
    // base case: if the combination size is `k`, print it
    if (out.size() == k)
    {
        printVector(out);
        return;
    }
 
    // start from the previous element in the current combination
    // till the last element
    for (int j = i; j < n; j++)
    {
        // add current element `arr[j]` to the solution and recur with the
        // same index `j` (as repeated elements are allowed in combinations)
        out.push_back(arr[j]);
        findCombinations(arr, out, k, j, n);
 
        // backtrack: remove the current element from the solution
        out.pop_back();
 
        // code to handle duplicates – skip adjacent duplicates
        while (j < n - 1 && arr[j] == arr[j + 1]) {
            j++;
        }
    }
}
 
int main()
{
    int arr[] = { 1, 2, 1 };
    int k = 2;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // if the array contains repeated elements, sort the array to
    // handle duplicates combinations
    sort (arr, arr + n);
 
    vector<int> out;
    findCombinations(arr, out, k, 0, n);
 
    return 0;
}
