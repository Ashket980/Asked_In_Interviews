#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;
 
// Function to generate random nums from a vector according to the given probabilities
int random(vector<int> const &nums, vector<int> const &probability)
{
    int n = nums.size();
    if (n != probability.size()) {
        return -1;        // error
    }
 
    // construct a sum vector from the given probabilities
    vector<int> prob_sum(n, 0);
 
    // `prob_sum[i]` holds sum of all `probability[j]` for `0 <= j <=i`
    prob_sum[0] = probability[0];
    for (int i = 1; i < n; i++) {
        prob_sum[i] = prob_sum.at(i-1) + probability[i];
    }
 
    // generate a random integer from 1 to 100 and check where it lies in `prob_sum[]`
    int r = (rand() % 100) + 1;
 
    // based on the comparison result, return the corresponding
    // element from the nums vector
 
    if (r <= prob_sum[0]) {      // handle 0th index separately
        return nums[0];
    }
 
    for (int i = 1; i < n; i++)
    {
        if (r > prob_sum.at(i-1) && r <= prob_sum[i]) {
            return nums[i];
        }
    }
}
 
int main()
{
    // Input: vector of integers and their probabilities
    // Goal: generate `nums[i]` with probability equal to `probability[i]`
 
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> probability = {30, 10, 20, 15, 25};
 
    // initialize srand with a distinctive value
    srand(time(NULL));
 
    // maintain a frequency map to validate the results
    unordered_map<int, int> freq;
 
    // make 1000000 calls to the `random()` function and
    // store results in a map
    for (int i = 0; i < 1000000; i++)
    {
        int val = random(nums, probability);
        freq[val]++;
    }
 
    // print the results
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ~ " << freq[nums[i]]/10000.0 << "%" << endl;
    }
 
    return 0;
}
