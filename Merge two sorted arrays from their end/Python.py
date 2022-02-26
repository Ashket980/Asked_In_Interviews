# Function to merge two sorted lists `X` and `Y` from their end
def merge(X, Y):
 
    i = len(X) - 1
    j = len(Y) - 1
 
    aux = [0] * (len(X) + len(Y))
    k = 0
 
    # while there are elements in the first and second arrays
    while i >= 0 and j >= 0:
        if X[i] >= Y[j]:
            aux[k] = X[i]
            i = i - 1
        else:
            aux[k] = Y[j]
            j = j - 1
        k = k + 1
 
    # copy remaining elements
    while i >= 0:
        aux[k] = X[i]
        k = k + 1
        i = i - 1
 
    while j >= 0:
        aux[k] = Y[j]
        k = k + 1
        j = j - 1
 
    return aux
 
 
if __name__ == '__main__':
 
    X = [1, 4, 7, 8]
    Y = [2, 3, 9]
 
    aux = merge(X, Y)
 
    print('First Array :', X)
    print('Second Array:', Y)
    print('After Merge :', aux)
