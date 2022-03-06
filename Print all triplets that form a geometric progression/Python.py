# Function to print all triplets that forms geometric progression
# in a given sorted list
def findAllTriplets(A):
 
    if len(A) < 3:
        return
 
    # One by one, fix every element as a middle element
    for j in range(1, len(A) - 1):
 
        # Initialize `i` and `k` for current `j`
        i = j - 1
        k = j + 1
 
        # Find all `i` and `k` such that `(i, j, k)` form a GP triplet
        while True:
 
            # If `A[j]/A[i] = r`, and `A[k]/A[j] = r`, and `r` is an integer,
            # `(i, j, k)` forms a GP
            while (i >= 0 and k <= len(A) - 1 and
                (A[j] % A[i] == 0) and (A[k] % A[j] == 0) and
                (A[j] / A[i] == A[k] / A[j])):
 
                # print the triplet
                print((A[i], A[j], A[k]))
 
                # since the list is sorted and elements are distinct
                k = k + 1
                i = i - 1
 
            if i < 0 or k >= len(A):
                break
 
            # If `A[j]` is multiple of `A[i]` and `A[k]` is multiple of `A[j]`,
            # then `A[j] / A[i] != A[k] / A[j]`; compare their values
            # to move to the next `k` or previous `i`
            if A[j] % A[i] == 0 and A[k] % A[j] == 0:
                if A[j] / A[i] < A[k] / A[j]:
                    i = i - 1
                else:
                    k = k + 1
 
            # Otherwise, if `A[j]` is a multiple of `A[i]`, try next `k`.
            # Else, try the previous `i`.
            elif A[j] % A[i] == 0:
                k = k + 1
            else:
                i = i - 1
 
 
if __name__ == '__main__':
 
    A = [1, 2, 6, 10, 18, 54]
    findAllTriplets(A)
