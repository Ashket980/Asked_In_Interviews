def countSort(nums):
 
    # create a dictionary to store the frequency of list elements
    freq = {}
 
    # store distinct values in the input list as keys and
    # their respective counts as values in the dictionary
    for i in nums:
        freq[i] = freq.setdefault(i, 0) + 1
 
    # traverse the dictionary (based on the sorted order of keys) and
    # overwrite the input list with sorted elements
    i = 0
    for key, value in sorted(freq.items()):
        while value > 0:
            nums[i] = key
            value = value - 1
            i = i + 1
 
 
if __name__ == '__main__':
 
    nums = [4, 2, 1, 4, 1, 4, 2, 1, 10]
 
    countSort(nums)
    print(nums)
