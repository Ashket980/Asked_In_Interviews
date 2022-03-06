import sys
 
 
# Function to find the minimum number of coins required
# to get a total of `target` from set `S`
def findMinCoins(S, target):
 
    # `T[i]` stores the minimum number of coins needed to get a total of i
    T = [0] * (target + 1)
 
    for i in range(1, target + 1):
 
        # initialize the minimum number of coins needed to infinity
        T[i] = sys.maxsize
 
        # do for each coin
        for c in range(len(S)):
            # check if the index doesn't become negative by including
            # current coin `c`
            if i - S[c] >= 0:
                result = T[i - S[c]]
 
                # if total can be reached by including current coin `c`,
                # update the minimum number of coins needed `T[i]`
                if result != sys.maxsize:
                    T[i] = min(T[i], result + 1)
 
    # `T[target]` stores the minimum number of coins needed to get a total of `target`
    return T[target]
 
 
if __name__ == '__main__':
 
    # coins of given denominations
    S = [1, 2, 3, 4]
 
    # total change required
    target = 15
 
    coins = findMinCoins(S, target)
    if coins != sys.maxsize:
        print('The minimum number of coins required to get the desired change is', coins)
