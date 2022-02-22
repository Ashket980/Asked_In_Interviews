import sys
 
 
# Find minimum jumps required to reach the destination
def findMinJumps(nums, i, n, lookup):
 
    # base case: destination is reached
    if i == n - 1:
        return 0
 
    # base case: list index out of bound or destination is
    # unreachable from the source
    if i >= n or nums[i] == 0:
        return sys.maxsize
 
    # if the subproblem is seen before
    if lookup[i]:
        return lookup[i]
 
    # find the minimum jumps required to reach the destination by considering
    # the minimum of all elements reachable from `nums[i]`
    min_jumps = sys.maxsize
    for j in range(i + 1, i + nums[i] + 1):
        cost = findMinJumps(nums, j, n, lookup)
        if cost != sys.maxsize:
            min_jumps = min(min_jumps, cost + 1)
 
    # if the subproblem is seen for the first time
    lookup[i] = min_jumps
    return lookup[i]
 
 
def findMinimumJumps(nums):
 
    # base case
    if not nums:
        return 0
 
    # create an auxiliary list to store solutions to the subproblems and
    # initialize it with 0
    lookup = [0] * len(nums)
 
    return findMinJumps(nums, 0, len(nums), lookup)
 
 
if __name__ == '__main__':
 
    nums = [1, 3, 6, 1, 0, 9]
 
    print('The minimum jumps required to reach the destination are',
        findMinimumJumps(nums))
