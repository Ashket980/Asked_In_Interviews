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
 
// Returns the maximum count of non-conflicting jobs that can be performed
// by a single person
int findNonConflictingJobsLength(vector<Job> jobs)        // no-ref, no-const
{
    // sort the jobs according to increasing order of their start time
    sort(jobs.begin(), jobs.end(),
        [](Job &x, Job &y) {
            return x.start < y.start;
        });
 
    // L[i] stores the maximum count of non-conflicting jobs ending at i'th job
    vector<int> L(jobs.size());
 
    for (int i = 0; i < jobs.size(); i++)
    {
        // consider each `j` less than `i`
        for (int j = 0; j < i; j++)
        {
            // L[i] = max(L[j]), where `jobs[j].finish` is less than `jobs[i].start`
            if (jobs[j].finish < jobs[i].start && L[i] < L[j]) {
                L[i] = L[j];
            }
        }
 
        // increment L[i] since it ends at the i'th job
        L[i]++;
    }
 
    // return the maximum job length in the vector
    return *max_element(L.begin(), L.end());
}
 
int main()
{
    // Each pair stores the start and the finish time of a job
    vector<Job> jobs =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
 
    cout << "The maximum number of non-conflicting jobs is "
         << findNonConflictingJobsLength(jobs);
 
    return 0;
}
