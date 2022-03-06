# Merge two sorted sublists `A[low … mid]` and `A[mid+1 … high]`
def merge(A, aux, low, mid, high):
 
    k = i = low
    j = mid + 1
    inversionCount = 0
 
    # while there are elements in the left and right runs
    while i <= mid and j <= high:
        if A[i] <= A[j]:
            aux[k] = A[i]
            i = i + 1
        else:
            aux[k] = A[j]
            j = j + 1
            inversionCount += (mid - i + 1)        # NOTE
 
        k = k + 1
 
    # copy remaining elements
    while i <= mid:
        aux[k] = A[i]
        k = k + 1
        i = i + 1
 
    ''' no need to copy the second half (since the remaining items
        are already in their correct position in the temporary array) '''
 
    # copy back to the original list to reflect sorted order
    for i in range(low, high + 1):
        A[i] = aux[i]
 
    return inversionCount
 
 
# Sort list `A[low…high]` using auxiliary list `aux`
def mergesort(A, aux, low, high):
 
    # base case
    if high <= low:        # if run size <= 1
        return 0
 
    # find midpoint
    mid = low + ((high - low) >> 1)
    inversionCount = 0
 
    # recursively split runs into two halves until run size <= 1,
    # then merges them and return up the call chain
 
    inversionCount += mergesort(A, aux, low, mid)       # split/merge left half
    inversionCount += mergesort(A, aux, mid + 1, high)  # split/merge right half
    inversionCount += merge(A, aux, low, mid, high)     # merge the two half runs
 
    return inversionCount
 
 
if __name__ == '__main__':
 
    A = [1, 9, 6, 4, 5]
    aux = A.copy()
 
    # get the inversion count by performing merge sort on a list
    print("Inversion count is", mergesort(A, aux, 0, len(A) - 1))
