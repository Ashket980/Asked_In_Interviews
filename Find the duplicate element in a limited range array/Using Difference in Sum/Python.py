def findDuplicate(nums):
 
    actual_sum = sum(nums)
    expected_sum = len(nums) * (len(nums) - 1) // 2
 
    return actual_sum - expected_sum
 
 
if __name__ == '__main__':
 
    nums = [1, 2, 3, 4, 4]
    print('The duplicate element is', findDuplicate(nums))
