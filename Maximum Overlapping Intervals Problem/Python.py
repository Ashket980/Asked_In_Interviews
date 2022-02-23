# Function to find the point when the maximum number of guests are present in an event
def findMaxGuests(arrival, departure):
 
    # Find the time when the last guest leaves the event
    t = max(departure)
 
    # create a count array initialized by 0
    count = [0] * (t + 2)
 
    for i in range(len(arrival)):
        count[arrival[i]] += 1
        count[departure[i] + 1] -= 1
 
    # keep track of the time when there are maximum guests
    max_event_tm = count[0]
 
    # perform a prefix sum computation to determine the guest count at each point
    for i in range(1, t + 1):
        count[i] += count[i - 1]
        if count[max_event_tm] < count[i]:
            max_event_tm = i
 
    print("Event Time:", max_event_tm)
    print("The maximum number of guests is", count[max_event_tm])
 
 
if __name__ == '__main__':
 
    arrival = [1, 2, 4, 7, 8, 12]
    departure = [2, 7, 8, 12, 10, 15]
 
    findMaxGuests(arrival, departure)
