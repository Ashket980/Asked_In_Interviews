import sys
 
 
# Function to find a pair in a list with an absolute minimum sum
def findPair(A):
 
    if len(A) < 2:
        return
 
    # sort the list if it is unsorted
 
    # maintain two indexes pointing to endpoints of the list
    (low, high) = (0, len(A) - 1)
 
    # `min` stores the minimum absolute difference
    min = sys.maxsize
    i = j = 0
 
    # reduce the search space `A[low…high]` at each iteration of the loop
 
    # loop if `low` is less than `high`
    while low < high:
        # update the minimum if the current absolute sum is less
        if abs(A[high] + A[low]) < min:
            min = abs(A[high] + A[low])
            (i, j) = (low, high)
 
        # optimization: pair with zero-sum is found
        if min == 0:
            break
 
        # increment `low` index if the total is less than 0;
        # decrement `high` index if the total is more than 0
        if A[high] + A[low] < 0:
            low = low + 1
        else:
            high = high - 1
 
    # print the pair
    print("Pair found", (A[i], A[j]))
 
 
if __name__ == '__main__':
 
    A = [-6, -5, -3, 0, 2, 4, 9]
 
    findPair(A)
