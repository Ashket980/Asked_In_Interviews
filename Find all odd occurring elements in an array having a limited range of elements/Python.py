# Find odd occurring elements in a given list
def findRepeating(nums):
 
    xor = 0
    for i in nums:
        xor ^= (1 << i)
 
    print('The odd occurring elements are ', end='')
    for i in nums:
        if xor & (1 << i):
            print(i, end=' ')
            xor ^= (1 << i)        # to avoid printing duplicates
 
 
if __name__ == '__main__':
 
    nums = [5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2]
    findRepeating(nums)
