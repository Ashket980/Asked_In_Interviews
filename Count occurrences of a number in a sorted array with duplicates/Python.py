# Function to find the first or last occurrence of a given number in
# a sorted list of integers. If `searchFirst` is true, return the
# first occurrence of the number; otherwise, return its last occurrence.
def binarySearch(nums, target, searchFirst):
 
    # search space is nums[left…right]
    (left, right) = (0, len(nums) - 1)
 
    # initialize the result by -1
    result = -1
 
    # loop till the search space is exhausted
    while left <= right:
 
        # find the mid-value in the search space and compares it with the target
        mid = (left + right) // 2
 
        # if the target is found, update the result
        if target == nums[mid]:
            result = mid
 
            # go on searching towards the left (lower indices)
            if searchFirst:
                right = mid - 1
            # go on searching towards the right (higher indices)
            else:
                left = mid + 1
 
        # if the target is less than the middle element, discard the right half
        elif target < nums[mid]:
            right = mid - 1
        # if the target is more than the middle element, discard the left half
        else:
            left = mid + 1
 
    # return the found index or -1 if the element is not found
    return result
 
 
if __name__ == '__main__':
 
    nums = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9]
    target = 5
 
    first = binarySearch(nums, target, True)        # pass true for the first occurrence
    last = binarySearch(nums, target, False)        # pass false for the last occurrence
 
    count = last - first + 1
 
    if first != -1:
        print(f'Element {target} occurs {count} times')
    else:
        print('Element found not in the list')
