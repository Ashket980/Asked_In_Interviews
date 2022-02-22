#include <iostream>
#include <vector>
using namespace std;
 
// Function to print the contents of a given array
void printCombination(vector<int> const &out)
{
    for (int i: out) {
        cout << i << " ";
    }
    cout << endl;
}
 
// Recursive function to print all combinations of numbers
// from `i` to `n` having sum `n`
void printCombinations(int i, int n, vector<int> &out)
{
    // if the sum becomes `n`, print the combination
    if (n == 0) {
        printCombination(out);
    }
 
    // start from the previous element in the combination till `n`
    for (int j = i; j <= n; j++)
    {
        // include current element from the combination
        out.push_back(j);
 
        // recur with a reduced sum
        printCombinations(j, n - j, out);
 
        // backtrack: remove the current element from the combination
        out.pop_back();
    }
}
 
int main()
{
    int n = 5;
 
    vector<int> out;
 
    // recur all combinations of numbers from 1 to `n` having sum `n`
    printCombinations(1, n, out);
 
    return 0;
}
