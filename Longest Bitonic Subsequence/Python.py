# Function to find the longest bitonic subsequence in a list
def LBS(nums):
 
    n = len(nums)
 
    # base case
    if n == 0:
        return
 
    # `I[i]` store the longest increasing subsequence, ending at `nums[i]`
    I = [[] for _ in range(n)]
    I[0].append(nums[0])
 
    for i in range(1, n):
        for j in range(i):
            if len(I[i]) < len(I[j]) and nums[i] > nums[j]:
                I[i] = I[j].copy()
        I[i].append(nums[i])
 
    # `D[i]` stores the longest decreasing subsequence, starting from `nums[i]`
    D = [[] for _ in range(n)]
    D[n - 1].insert(0, nums[n - 1])
 
    for i in reversed(range(n - 1)):
        for j in reversed(range(i + 1, n)):
            if len(D[i]) < len(D[j]) and nums[i] > nums[j]:
                D[i] = D[j].copy()
        D[i].insert(0, nums[i])
 
    # find the peak element index
    peak = 0
    for i in range(1, n):
        if len(I[i]) + len(D[i]) > len(I[peak]) + len(D[peak]):
            peak = i
 
    print('The longest bitonic subsequence is ', end='')
 
    # print longest increasing subsequence ending at peak element
    print(I[peak], end='')
 
    # pop the front element of LDS as it points to the same element as the rear of LIS
    D[peak].pop(0)
 
    # print longest decreasing subsequence starting from the peak element
    print(D[peak])
 
 
if __name__ == '__main__':
 
    nums = [4, 2, 5, 9, 7, 6, 10, 3, 1]
    LBS(nums)
