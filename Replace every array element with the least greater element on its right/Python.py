import sys
 
 
# Replace each element of the specified list with the
# least greater element on its right
def replace(nums):
 
    # traverse the list from the beginning
    for i in range(len(nums)):
 
        successor = -1
        diff = sys.maxsize
 
        # check every element on the right for a successor
        for j in range(i + 1, len(nums)):
            if nums[j] > nums[i] and (nums[j] - nums[i] < diff):
                successor = nums[j]
                diff = nums[j] - nums[i]
 
        nums[i] = successor
 
    # print the resultant list
    print(nums)
 
 
if __name__ == '__main__':
 
    nums = [10, 100, 93, 32, 35, 65, 80, 90, 94, 6]
    replace(nums)
