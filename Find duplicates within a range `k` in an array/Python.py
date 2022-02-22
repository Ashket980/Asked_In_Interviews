def hasDuplicate(nums, k):
 
    # stores (element, index) pairs as (key, value) pairs
    d = {}
 
    # traverse the list
    for i, e in enumerate(nums):
 
        # if the current element already exists in the dictionary
        if e in d:
 
            # return true if the current element repeats within range of `k`
            if i - d.get(e) <= k:
                return True
 
        # store elements along with their indices
        d[e] = i
 
    # we reach here when no element repeats within range `k`
    return False
 
 
if __name__ == '__main__':
 
    nums = [5, 6, 8, 2, 4, 6, 9]
    k = 4
 
    if hasDuplicate(nums, k):
        print('Duplicates found')
    else:
        print('No duplicates were found')
