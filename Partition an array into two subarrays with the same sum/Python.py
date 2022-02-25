# Partition the list into two sublists with the same sum
def partition(A):
 
    # calculate the sum of all list elements
    total_sum = sum(A)
 
    # variable to maintain the sum of processed elements
    sum_so_far = 0
 
    # do for each element in the list
    for i in range(len(A)):
 
        # if the sum of `A[0…i-1]` is equal to `A[i, n-1]`
        if sum_so_far == total_sum - sum_so_far:
            return i
 
        # update `sum_so_far` by including the value of the current element
        sum_so_far += A[i]
 
    return -1
 
 
if __name__ == '__main__':
 
    A = [6, -4, -3, 2, 3]
 
    # get index `i` that points to the starting of the second sublist
    i = partition(A)
 
    if i != -1:
        print(A[:i])        # print the first sublist, `A[0, i-1]`
        print(A[i:])        # print the second sublist, `A[i, len(A))`
    else:
        print("The list can't be partitioned")
