# Returns the maximum count of non-conflicting jobs that can be performed
# by a single person
def findNonConflictingJobsLength(jobs):
 
    # Sort the jobs according to increasing order of their start time
    jobs.sort(key=lambda x: x[0])
 
    # L[i] stores the maximum count of non-conflicting jobs ending at i'th job
    L = [0] * len(jobs)
 
    for i in range(len(jobs)):
        # consider each `j` less than `i`
        for j in range(i):
            # L[i] = max(L[j]), where `jobs[j].finish` is less than `jobs[i].start`
            if jobs[j][1] < jobs[i][0] and L[i] < L[j]:
                L[i] = L[j]
 
        # increment L[i] since it ends at the i'th job
        L[i] = L[i] + 1
 
    # return the maximum job length in the list
    return max(L)
 
 
if __name__ == '__main__':
 
    # Each pair stores the start and the finish time of a job
    jobs = [
        (1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9),
        (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)
    ]
 
    print('The maximum number of non-conflicting jobs is',
        findNonConflictingJobsLength(jobs))
