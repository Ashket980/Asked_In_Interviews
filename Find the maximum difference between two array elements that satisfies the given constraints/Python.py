import sys
 
 
# Function to calculate the maximum difference between two elements in a
# list such that a smaller element appears before a larger element
def getMaxDiff(A):
 
    diff = -sys.maxsize
    n = len(A)
    if n == 0:
        return diff
 
    max_so_far = A[n - 1]
 
    # traverse the list from the right and keep track of the maximum element
    for i in reversed(range(n - 1)):
 
        # update `max_so_far` if the current element is greater than the
        # maximum element
        if A[i] >= max_so_far:
            max_so_far = A[i]
 
        # if the current element is less than the maximum element,
        # then update the difference if required
        else:
            diff = max(diff, max_so_far - A[i])
 
    # return difference
    return diff
 
 
if __name__ == '__main__':
 
    A = [2, 7, 9, 5, 1, 3, 5]
    diff = getMaxDiff(A)
    if diff != -sys.maxsize:
        print("The maximum difference is", diff)
