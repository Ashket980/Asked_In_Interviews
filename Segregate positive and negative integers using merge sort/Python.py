# Merge two sublists, `A[low… mid]` and `A[mid+1… high]`,
# such that all positive numbers follow negative numbers
def merge(A, aux, low, mid, high):
 
    k = low
 
    # copy negative elements from the left sublist
    for i in range(low, mid + 1):
        if A[i] < 0:
            aux[k] = A[i]
            k = k + 1
 
    # copy negative elements from the right sublist
    for j in range(mid + 1, high + 1):
        if A[j] < 0:
            aux[k] = A[j]
            k = k + 1
 
    # copy positive elements from the left sublist
    for i in range(low, mid + 1):
        if A[i] >= 0:
            aux[k] = A[i]
            k = k + 1
 
    # copy positive elements from the right sublist
    for j in range(mid + 1, high + 1):
        if A[j] >= 0:
            aux[k] = A[j]
            k = k + 1
 
    # copy back to the original list to reflect sorted order
    for i in range(low, high + 1):
        A[i] = aux[i]
 
 
# Segregate positive and negative integers using a mergesort-like routine
def partition(A, aux, low, high):
 
    # Base case
    if high <= low:
        return
 
    # find midpoint
    mid = low + ((high - low) >> 1)
 
    partition(A, aux, low, mid)         # split/merge left half
    partition(A, aux, mid + 1, high)    # split/merge right half
 
    merge(A, aux, low, mid, high)       # join the two half runs
 
 
if __name__ == '__main__':
 
    A = [9, -3, 5, -2, -8, -6, 1, 3]
    aux = A.copy()
 
    partition(A, aux, 0, len(A) - 1)
    print(A)
