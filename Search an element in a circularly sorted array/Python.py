# Function to find an element in a circularly sorted list
def searchCircularList(nums, target):
 
    # search space is nums[left…right]
    (left, right) = (0, len(nums) - 1)
 
    # loop till the search space is exhausted
    while left <= right:
 
        # find the mid-value in the search space and
        # compares it with the target
        mid = (left + right) // 2
 
        # if the key is found, return its index
        if target == nums[mid]:
            return mid
 
        # if right half nums[mid…right] is sorted and `mid` is not
        # the key element
        if nums[mid] <= nums[right]:
            # compare key with nums[mid] and nums[right] to know
            # if it lies in nums[mid…right] or not
            if nums[mid] < target <= nums[right]:
                left = mid + 1      # go searching in the right sorted half
            else:
                right = mid - 1     # go searching left
 
        # if left half nums[left…mid] is sorted, and `mid` is not
        # the key element
        else:
            # compare key with nums[left] and nums[mid] to know
            # if it lies in nums[left…mid] or not
            if nums[left] <= target < nums[mid]:
                right = mid - 1     # go searching in the left sorted half
            else:
                left = mid + 1      # go searching right
 
    # key not found or invalid input
    return -1
 
 
if __name__ == '__main__':
 
    nums = [9, 10, 2, 5, 6, 8]
    key = 5
 
    index = searchCircularList(nums, key)
 
    if index != -1:
        print('Element found at index', index)
    else:
        print('Element found not in the list')
