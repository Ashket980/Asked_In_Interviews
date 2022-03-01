from math import log
 
 
def log2(x, base):
    return int(log(x) // log(base))
 
 
# Function to find two repeating elements in a list of size `n+2`
# having a range of elements from 1 to `n` using XOR operator
def findDuplicates(arr, n):
 
    # take XOR of all list elements index 0 to `n-1` and
    # elements from 1 to `n`
    result = arr[0] ^ arr[n + 1]
    for i in range(1, n + 1):
        result = result ^ arr[i] ^ i
 
    # `x` and `y` are two odd appearing elements
    x = y = 0
 
    # `result` stores `x ^ y`
 
    # find the position of the rightmost set bit in `result`
    k = log2(result & -result, 2)
 
    # split the list into two sublists
    for i in range(n + 2):
 
        # list elements that have k'th bit 1
        if arr[i] & (1 << k):
            x = x ^ arr[i]
 
        # list elements that have k'th bit 0
        else:
            y = y ^ arr[i]
 
    # split range [1, n] into two subranges
    for i in range(1, n + 1):
 
        # number `i` has k'th bit 1
        if i & (1 << k):
            x = x ^ i
 
        # number `i` has k'th bit 0
        else:
            y = y ^ i
 
    print(f'The duplicate elements are {x} and {y}')
 
 
if __name__ == '__main__':
 
    arr = [4, 3, 6, 5, 2, 4, 1, 1]
    n = 6        # list size is `n+2`
 
    findDuplicates(arr, n)
 
