# Function to merge `X[0… m]` and `Y[0… n]` into `X[0… m+n+1]`
def merge(X, Y, m, n):
 
    # size of `X` is `k+1`
    k = m + n + 1
 
    # run if `X` or `Y` has elements left
    while m >= 0 and n >= 0:
        # put the next greater element in the next free position in `X[]` from the end
        if X[m] > Y[n]:
            X[k] = X[m]
            m = m - 1
            k = k - 1
        else:
            X[k] = Y[n]
            n = n - 1
            k = k - 1
 
    # copy the remaining elements of `Y[]` (if any) to `X[]`
    while n >= 0:
        X[k] = Y[n]
        k = k - 1
        n = n - 1
 
    # fill `Y` with all zeroes
    for i in range(len(Y)):
        Y[i] = 0
 
 
# The function moves non-empty elements in `X` in the
# beginning and then merge them with `Y`
def rearrange(X, Y):
 
    # return if `X` is empty
    if not len(X):
        return;
 
    # moves non-empty elements of `X` at the beginning
    k = 0
    for i in range(len(X)):
        if X[i]:
            X[k] = X[i]
            k = k + 1
 
    # merge `X[0… k-1]` and `Y[0… n-1]` into `X[0… m-1]`
    merge(X, Y, k - 1, len(Y) - 1)
 
 
if __name__ == '__main__':
 
    # vacant cells in `X[]` is represented by 0
    X = [0, 2, 0, 3, 0, 5, 6, 0, 0]
    Y = [1, 8, 9, 10, 15]
 
    ''' Validate input before calling `rearrange()`
        1. Both lists `X[]` and `Y[]` should be sorted (ignore 0's in `X[]`)
        2. Size of list `X[]` >= size of list `Y[]` (i.e., `m >= n`)
        3. Total number of vacant cells in list `X[]` = size of list `Y[]` '''
 
    # merge `Y` into `X`
    rearrange(X, Y)
 
    # print merged list
    print(X)
