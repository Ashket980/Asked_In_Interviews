# Find all combinations that satisfy the given constraints
def findAllCombinations(A, x, n):
 
    # if all elements are filled, print the solution
    if x > n:
        print(A)
        return
 
    # try all possible combinations for element `x`
    for i in range(2*n):
 
        # if position `i` and `i+x+1` are not occupied in the input
        if A[i] == -1 and (i + x + 1) < 2*n and A[i + x + 1] == -1:
 
            # place `x` at position `i` and `i+x+1`
            A[i] = x
            A[i + x + 1] = x
 
            # recur for the next element
            findAllCombinations(A, x + 1, n)
 
            # backtrack (remove `x` from position `i` and `i+x+1`)
            A[i] = -1
            A[i + x + 1] = -1
 
 
if __name__ == '__main__':
 
    # given number
    n = 7
 
    # create an input list of the size of a given number with
    # all its elements initialized by -1
    A = [-1] * (2*n)
 
    # start from element 1
    x = 1
    findAllCombinations(A, x, n)
