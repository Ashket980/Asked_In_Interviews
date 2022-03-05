# Function to find the best way to cut a rod of length `n`
# where the rod of length `i` has a cost `price[i-1]`
def rodCut(price, n):
 
    # `T[i]` stores the maximum profit achieved from a rod of length `i`
    T = [0] * (n + 1)
 
    # consider a rod of length `i`
    for i in range(1, n + 1):
        # divide the rod of length `i` into two rods of length `j`
        # and `i-j` each and take maximum
        for j in range(1, i + 1):
            T[i] = max(T[i], price[j - 1] + T[i - j])
 
    # `T[n]` stores the maximum profit achieved from a rod of length `n`
    return T[n]
 
 
if __name__ == '__main__':
 
    price = [1, 5, 8, 9, 10, 17, 17, 20]
    n = 4        # rod length
 
    print('Profit is', rodCut(price, n))
