# Returns the total number of distinct absolute values in a given input
def findDistinctCount(A):
 
    # initialize the distinct count as input size
    distinct_count = len(A)
 
    # points to the left and right boundary of the current window,
    # i.e., the current window is formed by `A[left, right]`
    left = 0
    right = len(A) - 1
 
    # loop until the left index of the current window is less than the right index
    while left < right:
 
        # remove any duplicate elements from the left and right of the current
        # window and decrease the distinct count for each duplicate found
        while left < right and A[left] == A[left + 1]:
            distinct_count = distinct_count - 1
            left = left + 1
 
        while right > left and A[right] == A[right - 1]:
            distinct_count = distinct_count - 1
            right = right - 1
 
        # if only one element is left, break the loop
        if left == right:
            break
 
        total = A[left] + A[right]
 
        # decrease the distinct count if the zero-sum pair is encountered
        if total == 0:
            distinct_count = distinct_count - 1
            left = left + 1
            right = right - 1
 
        # if the sum is negative, incrementing the left index might still lead
        # to a zero-sum pair
        elif total < 0:
            left = left + 1
        # if the sum is positive, decrementing the right index might still lead
        # to a zero-sum pair
        else:
            right = right - 1
 
    return distinct_count
 
 
if __name__ == '__main__':
 
    input = [-1, -1, 0, 1, 1, 1]
    print('The total number of distinct absolute values is', findDistinctCount(input))
