# Function to find the maximum profit earned by buying and
# selling shares any number of times
def findMaxProfit(price):
 
    # keep track of the maximum profit gained
    profit = 0
 
    # initialize the local minimum to the first element's index
    j = 0
 
    # start from the second element
    for i in range(1, len(price)):
 
        # update the local minimum if a decreasing sequence is found
        if price[i - 1] > price[i]:
            j = i
 
        # sell shares if the current element is the peak, i.e.,
        # (`previous <= current > next`)
        if price[i - 1] <= price[i] and \
                (i + 1 == len(price) or price[i] > price[i + 1]):
            profit += (price[i] - price[j])
            print(f"Buy on day {j + 1} and sell on day {i + 1}")
 
    return profit
 
 
if __name__ == '__main__':
 
    price = [1, 5, 2, 3, 7, 6, 4, 5]
    print("\nTotal profit earned is", findMaxProfit(price))
