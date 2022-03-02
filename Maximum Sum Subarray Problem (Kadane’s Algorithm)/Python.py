import sys
 
 
# Function to find the maximum sum of a contiguous subarray
# in a given integer array (handles negative numbers as well)
def kadaneNeg(A):
    # stores the maximum sum sublist found so far
    max_so_far = -sys.maxsize
 
    # stores the maximum sum of sublist ending at the current position
    max_ending_here = 0
 
    # traverse the given list
    for i in range(len(A)):
        # update the maximum sum of sublist "ending" at index `i` (by adding the
        # current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + A[i]
 
        # maximum sum should be more than the current element
        max_ending_here = max(max_ending_here, A[i])
 
        # update the result if the current sublist sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here)
 
    return max_so_far
 
 
if __name__ == '__main__':
    A = [-8, -3, -6, -2, -5, -4]
    print("The sum of contiguous sublist with the largest sum is", kadaneNeg(A))
