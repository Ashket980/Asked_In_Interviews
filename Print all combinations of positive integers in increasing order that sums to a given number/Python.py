# Recursive function to print all combinations of positive integers
# in increasing order that sum to a given number
def printCombinations(nums, i, total, sum_left):
 
    # to maintain the increasing order, start the loop from the
    # previous number stored in `nums`
    prev_num = nums[i - 1] if (i > 0) else 1
    for k in range(prev_num, total + 1):
 
        # set the next element in the list to `k`
        nums[i] = k
 
        # recur with the sum left and the next location in the list
        if sum_left > k:
            printCombinations(nums, i + 1, total, sum_left - k)
 
        # if the sum is found
        if sum_left == k:
            print(nums[:i+1])
 
 
# Wrapper over `printCombinations()` function
def findCombinations(total):
 
    # create a temporary list for storing the combinations
    nums = [0] * total
 
    # recur for all combinations
    starting_index = 0
    printCombinations(nums, starting_index, total, total)
 
 
if __name__ == '__main__':
 
    total = 5
    findCombinations(total)
