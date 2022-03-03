# Function to find a duplicate element in a limited range list
def findDuplicate(nums):
 
    xor = 0
 
    # take xor of all list elements
    for i in range(len(nums)):
        xor ^= nums[i]
 
    # take xor of numbers from 1 to `n-1`
    for i in range(1, len(nums)):
        xor ^= i
 
    # same elements will cancel each other as a ^ a = 0,
    # 0 ^ 0 = 0 and a ^ 0 = a
 
    # `xor` will contain the missing number
    return xor
 
 
if __name__ == '__main__':
 
    # input list contains `n` numbers between 1 and `n-1`
    # with one duplicate, where `n = len(nums)`
    nums = [1, 2, 3, 4, 4]
 
    print('The duplicate element is', findDuplicate(nums))
