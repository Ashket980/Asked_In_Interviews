# Utility function to swap elements `A[i]` and `A[j]` in the list
def swap(A, i, j):
 
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
 
 
# Function to rearrange the list such that every second element
# of the list is greater than its left and right elements
def rearrangeArray(A):
 
    # start from the second element and increment index
    # by 2 for each iteration of the loop
    for i in range(1, len(A), 2):
 
        # if the previous element is greater than the current element,
        # swap the elements
        if A[i - 1] > A[i]:
            swap(A, i - 1, i)
 
        # if the next element is greater than the current element,
        # swap the elements
        if i + 1 < len(A) and A[i + 1] > A[i]:
            swap(A, i + 1, i)
 
 
if __name__ == '__main__':
 
    A = [9, 6, 8, 3, 7]
 
    rearrangeArray(A)
 
    # print output list
    print(A)
