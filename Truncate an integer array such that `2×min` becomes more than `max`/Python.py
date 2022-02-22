def findMin(arr, low, high):
 
    # base case
    if low > high:
        return 0
 
    # find the minimum and the maximum elements in array `arr[low…high]`
    # and check if the array is not balanced
    subarr = arr[low:high+1]
    if 2 * min(subarr) <= max(subarr):
        # remove the leftmost element from the array, and recur with the
        # remaining elements
        L = 1 + findMin(arr, low + 1, high)
 
        # remove the rightmost element from the array, and recur with the
        # remaining elements
        R = 1 + findMin(arr, low, high - 1)
 
        # return the minimum of two
        return min(L, R)
 
    # we reach here if the array is already balanced
    return 0
 
 
if __name__ == '__main__':
 
    arr = [4, 2, 6, 4, 9]
    print('The minimum number of removals is', findMin(arr, 0, len(arr) - 1))
