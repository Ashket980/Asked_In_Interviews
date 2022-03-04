# Function to find the largest sublist having an equal number of 0's and 1's
def findLargestSublist(nums):
 
    # create an empty dictionary to store the ending index of the first
    # sublist having some sum
    d = {}
 
    # insert (0, -1) pair into the set to handle the case when a
    # sublist with zero-sum starts from index 0
    d[0] = -1
 
    # `length` stores the maximum length of sublist with zero-sum
    length = 0
 
    # stores ending index of the largest sublist having zero-sum
    ending_index = -1
 
    total = 0
 
    # Traverse through the given list
    for i in range(len(nums)):
 
        # sum of elements so far (replace 0 with -1)
        total += -1 if (nums[i] == 0) else 1
 
        # if the sum is seen before
        if total in d:
 
            # update length and ending index of largest sublist having zero-sum
            if length < i - d.get(total):
                length = i - d.get(total)
                ending_index = i
 
        # if the sum is seen for the first time, insert the sum with its
        # index into the dictionary
        else:
            d[total] = i
 
    # print the sublist if present
    if ending_index != -1:
        print((ending_index - length + 1, ending_index))
    else:
        print('No sublist exists')
 
 
if __name__ == '__main__':
 
    nums = [0, 0, 1, 0, 1, 0, 0]
    findLargestSublist(nums)
