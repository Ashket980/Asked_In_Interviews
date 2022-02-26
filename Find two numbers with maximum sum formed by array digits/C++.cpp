#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// Find two numbers with a maximum sum formed by digits of an array
pair<int, int> findMaximum(vector<int> input)        // no-ref, no-const
{
    // base case: invalid input
    if (input.size() <= 1) {
        return make_pair(-1, -1);
    }
 
    // sort the array in descending order
    sort(input.rbegin(), input.rend());
 
    // fill `x` with digits at the odd indices of the sorted array
    int x = 0;
    for (int i = 0; i < input.size(); i = i + 2) {
        x = x * 10 + input[i];
    }
 
    // fill `y` with digits at the even indices of the sorted array
    int y = 0;
    for (int i = 1; i < input.size(); i = i + 2) {
        y = y * 10 + input[i];
    }
 
    // return `x` and `y`
    return make_pair(x, y);
}
 
int main()
{
    vector<int> input = { 4, 6, 2, 7, 9, 8 };
 
    pair<int, int> p = findMaximum(input);
    cout << "The two numbers with maximum sum are "
         << p.first << " and " << p.second;
 
    return 0;
}
