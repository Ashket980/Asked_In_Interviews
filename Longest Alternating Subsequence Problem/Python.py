# Function to find the length of the longest subsequence with alternate
# low and high elements.
def findLongestSequence(A):
 
    # base case
    if not A or len(A) <= 1:
        return len(A)
 
    # lookup table to store solutions to subproblems
    T = [[0] * 2 for r in range(len(A) + 1)]
 
    '''
        `T[i][0]` stores the longest alternating subsequence till `A[0…i]`
        where `A[i]` is greater than `A[i-1]`
 
        `T[i][1]` stores the longest alternating subsequence till `A[0…i]`
        where `A[i]` is smaller than `A[i-1]`
    '''
 
    # stores result
    result = 1
 
    # base case: the first element will always be part of LAS
    T[0][0] = T[0][1] = 1
 
    # fill the lookup table in a bottom-up manner
    for i in range(1, len(A)):
 
        # do for each element `A[j]` before `A[i]`
        for j in range(i):
 
            # If `A[i]` is greater than `A[j]`, update `T[i][0]`
            if A[i] > A[j]:
                T[i][0] = max(T[i][0], T[j][1] + 1)
 
            # If `A[i]` is smaller than `A[j]`, update `T[i][1]`
            if A[i] < A[j]:
                T[i][1] = max(T[i][1], T[j][0] + 1)
 
        # update result by taking a maximum of both values
        if result < max(T[i][0], T[i][1]):
            result = max(T[i][0], T[i][1])
 
    # return result
    return result
 
 
if __name__ == '__main__':
 
    A = [8, 9, 6, 4, 5, 7, 3, 2, 4]
 
    print('The length of the longest alternating subsequence is',
        findLongestSequence(A))
