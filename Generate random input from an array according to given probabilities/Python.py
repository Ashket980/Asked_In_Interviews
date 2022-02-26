from random import randrange
 
 
# Function to generate random nums from a list according to the
# given probabilities
def random(nums, probability):
 
    n = len(nums)
    if n != len(probability):
        return -1               # error
 
    # construct a sum list from the given probabilities
    prob_sum = [None] * n
 
    # `prob_sum[i]` holds sum of all `probability[j]` for `0 <= j <=i`
    prob_sum[0] = probability[0]
    for i in range(1, n):
        prob_sum[i] = prob_sum[i - 1] + probability[i]
 
    # generate a random integer from 1 to 100
    # and check where it lies in `prob_sum`
    r = randrange(1, 100)
 
    # based on the comparison result, return the corresponding
    # element from the input list
 
    if r <= prob_sum[0]:        # handle 0th index separately
        return nums[0]
 
    for i in range(1, n):
        if prob_sum[i - 1] < r <= prob_sum[i]:
            return nums[i]
 
    return -1
 
 
if __name__ == '__main__':
 
    # Input: list of integers and their probabilities
    # Goal: generate `nums[i]` with probability equal to `probability[i]`
 
    nums = [1, 2, 3, 4, 5]
    probability = [30, 10, 20, 15, 25]
 
    # maintain a frequency map to validate the results
    freq = {}
 
    # make 1000000 calls to the `random()` function and store results in a dictionary
    for i in range(1000000):
        val = random(nums, probability)
        freq[val] = freq.get(val, 0) + 1
 
    # print the results
    for i in range(len(nums)):
        print(f'{nums[i]} ~ {freq.get(nums[i]) / 10000.0}%')
