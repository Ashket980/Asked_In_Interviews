
# A class to store a Job
class Job:
    def __init__(self, start, finish, profit):
        self.start = start
        self.finish = finish
        self.profit = profit
 
 
# Function to find the maximum profit of non-overlapping jobs using LIS
def findMaxProfit(jobs):
 
    # base case
    if not jobs:
        return 0
 
    # sort the jobs according to increasing order of their start time
    jobs.sort(key=lambda x: x.start)
 
    # `maxProfit[i]` stores the maximum profit of non-conflicting jobs
    # ending at the i'th job
    maxProfit = [None] * len(jobs)
 
    # consider every job
    for i in range(len(jobs)):
        # initialize current profit to 0
        maxProfit[i] = 0
 
        # consider each `j` less than `i`
        for j in range(i):
            # if the j'th job is not conflicting with the i'th job and
            # is leading to the maximum profit
            if jobs[j].finish <= jobs[i].start and maxProfit[i] < maxProfit[j]:
                maxProfit[i] = maxProfit[j]
 
        # end the current task with i'th job
        maxProfit[i] += jobs[i].profit
 
    # return the maximum profit
    return max(maxProfit)
 
 
if __name__ == '__main__':
 
    jobs = [
        Job(0, 6, 60), Job(5, 9, 50), Job(1, 4, 30),
        Job(5, 7, 30), Job(3, 5, 10), Job(7, 8, 10)
    ]
 
    print('The maximum profit is', findMaxProfit(jobs))
