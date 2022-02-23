#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// Data structure to store the start and finish time of the jobs.
struct Job
{
    int start;
    int finish;
};
 
// Find the maximum number of non-conflicting jobs that can be performed
// by a single person
void findNonConflictingJobs(vector<Job> jobs)        // no-ref, no-const
{
    // sort the jobs according to increasing order of their start time
    sort(jobs.begin(), jobs.end(),
        [](Job &x, Job &y) {
            return x.start < y.start;
        });
 
    // `L[i]` stores the maximum non-conflicting jobs that end at i'th job
    vector<vector<Job>> L(jobs.size());
 
    for (int i = 0; i < jobs.size(); i++)
    {
        // consider each `j` less than `i`
        for (int j = 0; j < i; j++)
        {
            // L[i] = max(L[j]), where `jobs[j].finish` is less than `jobs[i].start`
            if (jobs[j].finish < jobs[i].start &&
                L[i].size() < L[j].size()) {
                L[i] = L[j];
            }
        }
 
        // `L[i]` ends at i'th job
        L[i].push_back(jobs[i]);
    }
 
    // find the vector having the maximum size
    vector<Job> max;
    for (auto &pair: L)
    {
        if (max.size() < pair.size()) {
            max = pair;
        }
    }
 
    // print maximum non-conflicting jobs
    for (Job &pair: max) {
        cout << "{" << pair.start << ", " << pair.finish << "} ";
    }
}
 
int main()
{
    // Each pair stores the start and the finish time of a job
    vector<Job> jobs =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    findNonConflictingJobs(jobs);
 
    return 0;
}
