#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a Job
struct Job {
    int start, finish, profit;
};
 
// Function to find the maximum profit of non-overlapping jobs using LIS
int findMaxProfit(vector<Job> jobs)        // no-ref, no-const
{
    // sort the jobs according to increasing order of their start time
    sort(jobs.begin(), jobs.end(),
        [](Job &x, Job &y) {
            return x.start < y.start;
        });
 
    // get the number of jobs
    int n = jobs.size();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // `maxProfit[i]` stores the maximum profit of non-conflicting jobs
    // ending at the i'th job
    int maxProfit[n];
 
    // consider every job
    for (int i = 0; i < n; i++)
    {
        // initialize current profit to 0
        maxProfit[i] = 0;
 
        // consider each `j` less than `i`
        for (int j = 0; j < i; j++)
        {
            // if the j'th job is not conflicting with the i'th job and
            // is leading to the maximum profit
            if (jobs[j].finish <= jobs[i].start && maxProfit[i] < maxProfit[j]) {
                maxProfit[i] = maxProfit[j];
            }
        }
 
        // end the current task with i'th job
        maxProfit[i] += jobs[i].profit;
    }
 
    // return the maximum profit
    return *max_element(maxProfit, maxProfit + n);
}
 
int main()
{
    vector<Job> jobs {
        { 0, 6, 60 },
        { 5, 9, 50 },
        { 1, 4, 30 },
        { 5, 7, 30 },
        { 3, 5, 10 },
        { 7, 8, 10 }
    };
 
    cout << "The maximum profit is " << findMaxProfit(jobs);
 
    return 0;
}
