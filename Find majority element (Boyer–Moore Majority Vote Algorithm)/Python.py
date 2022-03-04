# Function to find the majority element present in a given list
def findMajorityElement(nums):
 
    # `m` stores the majority element (if present)
    m = -1
 
    # initialize counter `i` with 0
    i = 0
 
    # do for each element `nums[j]` in the list
    for j in range(len(nums)):
 
        # if counter `i` becomes 0
        if i == 0:
 
            # set the current candidate to `nums[j]`
            m = nums[j]
 
            # reset the counter to 1
            i = 1
 
        # otherwise, increment the counter if `nums[j]` is a current candidate
        elif m == nums[j]:
            i = i + 1
 
        # otherwise, decrement the counter if `nums[j]` is a current candidate
        else:
            i = i - 1
 
    return m
 
 
if __name__ == '__main__':
 
    # assumption: valid input (majority element is present)
    nums = [1, 8, 7, 4, 1, 2, 2, 2, 2, 2, 2]
 
    print('The majority element is', findMajorityElement(nums))
