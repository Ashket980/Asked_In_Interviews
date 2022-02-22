#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
vector<int> findNextGreaterElements(vector<int> const &input)
{
    int n = input.size();
    vector<int> result(n, -1);
 
    // create an empty stack
    stack<int> s;
 
    // process each element from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // loop till we have a greater element on top or stack becomes empty.
        while (!s.empty())
        {
            // pop elements that aren't greater than the current element
            if (s.top() <= input[i]) {
                s.pop();
            }
            // the next greater element is now on the top of the stack
            else {
                result[i] = s.top();
                break;
            }
        }
 
        // push current element into the stack
        s.push(input[i]);
    }
 
    return result;
}
 
int main()
{
    vector<int> input = { 2, 7, 3, 5, 4, 6, 8 };
 
    vector<int> result = findNextGreaterElements(input);
    for (int i: result) {
        cout << i << ' ';
    }
 
    return 0;
}
