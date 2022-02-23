# Function to find index `i` in the list such that the sum of the left
# sublist of `A[i]` is equal to the sum of its right sublist
def findBreakPoint(A):
 
    # base case
    if not len(A):
        return -1
 
    # calculate the sum of all list elements
    total = sum(A)
 
    # stores sum of the left sublist
    left_sum = A[0]
 
    # start from index 1 to find non-empty sublists
    for i in range(1, len(A) - 1):
 
        # if the sum of `A[0…i-1]` is equal to `A[i+1, n-1]`
        if left_sum == total - (A[i] + left_sum):
            print("Index is", i)
 
        # update the left sublist sum
        left_sum += A[i]
 
 
if __name__ == '__main__':
 
    A = [-1, 6, 3, 1, -2, 3, 3]
 
    # divide the list into two non-empty sublists with equal sum
    findBreakPoint(A)
