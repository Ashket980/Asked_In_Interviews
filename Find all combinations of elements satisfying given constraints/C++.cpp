#include <iostream>
#include <vector>
using namespace std;
 
// Find all combinations that satisfy the given constraints
void findAllCombinations(vector<int> &arr, int x, int n)
{
    // if all elements are filled, print the solution
    if (x > n)
    {
        for (int i: arr) {
            cout << i << " ";
        }
        cout << endl;
 
        return;
    }
 
    // try all possible combinations for element `x`
    for (int i = 0; i < 2*n; i++)
    {
        // if position `i` and `i+x+1` are not occupied in the vector
        if (arr[i] == -1 && (i + x + 1) < 2*n &&
            arr[i + x + 1] == -1)
        {
            // place `x` at position `i` and `i+x+1`
            arr[i] = x;
            arr[i + x + 1] = x;
 
            // recur for the next element
            findAllCombinations(arr, x + 1, n);
 
            // backtrack (remove `x` from position `i` and `i+x+1`)
            arr[i] = -1;
            arr[i + x + 1] = -1;
        }
    }
}
 
int main()
{
    // given number
    int n = 7;
 
    // create a vector of double the size of a given number with
    // all its elements initialized by -1
    vector<int> arr(2*n, -1);
 
    // start from element 1
    int x = 1;
    findAllCombinations(arr, x, n);
 
    return 0;
}
