#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
 
// Data structure to store an element and its index in an array
struct Node
{
    int elem;
    int index;
};
 
// Overload compare operator for inserting into a set
inline bool operator<(const Node &lhs, const Node &rhs) {
    return lhs.elem < rhs.elem;
}
 
// Function to print LIS using parent array
void print(vector<int> const &input, auto parent, set<Node> s)
{
    // container to store LIS in reverse order
    stack<int> lis;
 
    // start from the last element of `s`
    int index = s.rbegin()->index;
 
    // get length of LIS
    int n = s.size();
 
    // retrieve LIS from parent array
    while (n--)
    {
        lis.push(input[index]);
        index = parent[index];
    }
 
    // print LIS
    cout << "LIS is ";
    while (!lis.empty())
    {
        cout << lis.top() << " ";
        lis.pop();
    }
}
 
// Function to find the longest increasing subsequence in a given array
void printLIS(vector<int> const &input)
{
    // base case
    if (input.size() == 0) {
        return;
    }
 
    // create an empty ordered set `s` (i'th element in `s` is defined as the
    // smallest integer that ends an increasing sequence of length `i`)
    set<Node> s;
 
    // `parent[i]` will store the predecessor of an element with index `i` in the LIS,
    // ending at the element with index `i`.
    map<int, int> parent;
 
    // process every element one by one
    for (int i = 0; i < input.size(); i++)
    {
        // construct node from the current element and its index
        Node curr = {input[i], i};
 
        // ignore the current element if it is already present in the set
        if (s.find(curr) != s.end()) {
            continue;
        }
 
        // insert the current node into the set and get an iterator to the
        // inserted node
        auto it = s.insert(curr).first;
 
        // if the node is not inserted at the end, then delete the next node
        if (++it != s.end()) {
            s.erase(it);
        }
 
        // get an iterator to the current node and update the parent
        it = s.find(curr);
        parent[i] = (--it)->index;
    }
 
    // print LIS using parent map
    print(input, parent, s);
}
 
int main()
{
    vector<int> input = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    printLIS(input);
 
    return 0;
}
