import sys
 
 
# Function to find the minimum difference between the index of two
# elements `x` and `y` present in a list
def findMinDifference(A, x, y):
 
    # base case
    if len(A) <= 1:
        return 0
 
    x_index = y_index = len(A)
    min_diff = sys.maxsize
 
    # traverse the given list
    for i in range(len(A)):
 
        # if the current element is `x`
        if A[i] == x:
            # set `x_index` to the current index
            x_index = i
 
            # if `y` is seen before, update the result if required
            if y_index != len(A):
                min_diff = min(min_diff, abs(x_index - y_index))
 
        # if the current element is `y`
        if A[i] == y:
            # set `y_index` to the current index
            y_index = i
 
            # if `x` is seen before, update the result if required
            if x_index != len(A):
                min_diff = min(min_diff, abs(x_index - y_index))
 
    return min_diff
 
 
if __name__ == '__main__':
 
    A = [1, 3, 5, 4, 8, 2, 4, 3, 6, 5]
    x = 2
    y = 5
 
    diff = findMinDifference(A, x, y)
 
    if diff != sys.maxsize:
        print("The minimum difference is", diff)
    else:
        print("Invalid input")
