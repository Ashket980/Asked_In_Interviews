#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
void countSort(vector<int> &input)
{
    // create an empty map to store the frequency of array elements
    map<int, int> freq;
 
    // store distinct values in the input array as key and
    // their respective counts as values
    for (int x: input) {
        freq[x]++;
    }
 
    // traverse the map and overwrite the input array with sorted elements
    // (the map will iterate based on the sorted order of keys)
    int i = 0;
    for (auto p: freq)
    {
        while (p.second--) {
            input[i++] = p.first;
        }
    }
}
 
int main()
{
    vector<int> input = { 4, 2, 1, 4, 1, 4, 2, 1, 10 };
 
    countSort(input);
 
    for (int i: input) {
        cout << i << " ";
    }
 
    return 0;
}
