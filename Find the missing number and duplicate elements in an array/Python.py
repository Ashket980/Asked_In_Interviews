from math import log
 
 
def log2(x, base):
    return int(log(x) // log(base))
 
 
# Function to find the missing number and duplicate element
# using XOR operator in a list of size `n` and range of
# elements from 1 to `n`
def findMissingAndDuplicate(arr):
    n = len(arr)
 
    # take XOR of all list elements from index 0 to `n-1`
    # all numbers in range 1 to `n`
    result = n
    for i in range(n):
        result = result ^ arr[i] ^ i
 
    # `x` and `y` stores the duplicate element and missing number
    x = y = 0
 
    # `result` stores `x ^ y`
 
    # find the position of the rightmost set bit in result
    k = log2(result & -result, 2)
 
    # split the list into two sublists
    for val in arr:
        # list elements that have k'th bit 1
        if (val & (1 << k)) != 0:
            x = x ^ val
        # list elements that have k'th bit 0
        else:
            y = y ^ val
 
    # split range [1, n] into two subranges
    for i in range(1, n + 1):
        # number `i` has k'th bit 1
        if (i & (1 << k)) != 0:
            x = x ^ i
        # number `i` has k'th bit 0
        else:
            y = y ^ i
 
    # linear search for the missing element
    if x in arr:
        return x, y
    else:
        return y, x
 
 
if __name__ == '__main__':
    arr = [4, 3, 6, 5, 2, 4]
    print('The duplicate and missing elements are', findMissingAndDuplicate(arr))
