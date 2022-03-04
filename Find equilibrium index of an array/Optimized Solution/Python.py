# Optimized method to find the equilibrium index of a list
def findEquilibriumIndex(A):
 
    # `total` stores the sum of all elements in the list
    total = sum(A)
 
    # `right` stores the sum of elements of sublist `A[i+1…n)`
    right = 0
 
    # maintain a list of indices
    indices = []
 
    # traverse the list from right to left
    for i in reversed(range(len(A))):
 
        ''' `i` is an equilibrium index if the sum of elements of sublist
            `A[0…i-1]` is equal to the sum of elements of the sublist
            A[i+1…n), i.e., (A[0] + A[1] + … + A[i-1]) =
            (A[i+1] + A[i+2] + … + A[n-1]) '''
 
        # sum of elements of the left sublist `A[0…i-1]` is
        # (total - (A[i] + right))
        if right == total - (A[i] + right):
            indices.append(i)
 
        # new right is `A[i] + (A[i+1] + A[i+2] + … + A[n-1])`
        right += A[i]
 
    print("Equilibrium Index found at", indices)
 
 
if __name__ == '__main__':
 
    A = [0, -3, 5, -4, -2, 3, 1, 0]
 
    findEquilibriumIndex(A)
