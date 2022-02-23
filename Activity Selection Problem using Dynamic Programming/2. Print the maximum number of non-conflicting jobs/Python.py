# Find the maximum number of non-conflicting jobs that can be performed
# by a single person
def findNonConflictingJobs(jobs):
 
    # sort the jobs according to increasing order of their start time
    jobs.sort(key=lambda x: x[0])
 
    # `L[i]` stores the maximum non-conflicting jobs that end at i'th job
    L = [[] for _ in range(len(jobs))]
 
    for i in range(len(jobs)):
        # consider each `j` less than `i`
        for j in range(i):
            # L[i] = max(L[j]), where `jobs[j].finish` is less than `jobs[i].start`
            start, finish = (jobs[i][0], jobs[j][1])
            if finish < start and len(L[i]) < len(L[j]):
                L[i] = L[j].copy()
 
        # `L[i]` ends at i'th job
        L[i].append(jobs[i])
 
    # find the list having a maximum size
    max = []
    for pair in L:
        if len(max) < len(pair):
            max = pair
 
    # print maximum non-conflicting jobs
    print(max)
 
 
if __name__ == '__main__':
 
    # Each pair stores the start and the finish time of a job
    jobs = [(1, 4), (3, 5), (0, 6), (5, 7),
            (3, 8), (5, 9), (6, 10), (8, 11),
            (8, 12), (2, 13), (12, 14)]
 
    findNonConflictingJobs(jobs)
