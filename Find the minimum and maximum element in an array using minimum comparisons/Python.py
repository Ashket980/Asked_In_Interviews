import sys
 
 
# Optimized solution to find the minimum and maximum number in a list
def findMinAndMax(nums):
 
    n = len(nums)
 
    # initialize minimum element by INFINITY and the maximum element by -INFINITY
    max = -sys.maxsize
    min = sys.maxsize
 
    # if the list has an odd number of elements, ignore the last
    # element and consider it later
    if n & 1:
        n = n - 1
 
    # compare elements in pairs, i.e., nums[i] and nums[i+1]
    for i in range(0, n, 2):
 
        # find maximum and minimum among nums[i] and nums[i+1]
 
        if nums[i] > nums[i + 1]:     # 1st comparison
            minimum = nums[i + 1]
            maximum = nums[i]
        else:
            minimum = nums[i]
            maximum = nums[i + 1]
 
        # update max
        if maximum > max:       # 2nd comparison
            max = maximum
 
        # update min
        if minimum < min:       # 3rd comparison
            min = minimum
 
    # handle the last element if the list has an odd number of elements
    if len(nums) & 1:
        if nums[n] > max: max = nums[n]
        if nums[n] < min: min = nums[n]
 
    print('The minimum element in the list is', min)
    print('The maximum element in the list is', max)
 
 
if __name__ == '__main__':
 
    nums = [4, 7, 5, 1, 3]
    findMinAndMax(nums)
