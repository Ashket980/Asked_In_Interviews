# Function to move all zeros present in the list to the end
def reorder(A):
 
    # `k` stores the index of the next available position
    k = 0
 
    # do for each element
    for i in A:
        # if the current element is non-zero, put the element at the
        # next free position in the list
        if i:
            A[k] = i
            k = k + 1
 
    # move all 0's to the end of the list (remaining indices)
    for i in range(k, len(A)):
        A[i] = 0
 
 
if __name__ == '__main__':
 
    A = [6, 0, 8, 2, 3, 0, 4, 0, 1]
 
    reorder(A)
    print(A)
