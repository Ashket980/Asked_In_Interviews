#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
 
// Function to find the point when the maximum number of guests are present in an event
void findMaxGuests(vector<int> const &arrival, vector<int> const &departure)
{
    // Find the time when the last guest leaves the event
    int t = *max_element(departure.begin(), departure.end());
 
    // create a count array initialized by 0
    vector<int> count(t + 2);
 
    for (int i = 0; i < arrival.size(); i++)
    {
        count[arrival[i]]++;
        count[departure[i] + 1]--;
    }
 
    // keep track of the time when there are maximum guests
    int max_event_tm = count[0];
 
    // perform a prefix sum computation to determine the guest count at each point
    for (int i = 1; i <= t; i++)
    {
        count[i] += count[i-1];
        if (count[max_event_tm] < count[i]) {
            max_event_tm = i;
        }
    }
 
    cout << "Event Time: " << max_event_tm << endl;
    cout << "The Maximum number of guests is " << count[max_event_tm] << endl;
}
 
int main()
{
    vector<int> arrival = { 1, 2, 4, 7, 8, 12 };
    vector<int> departure = { 2, 7, 8, 12, 10, 15 };
 
    findMaxGuests(arrival, departure);
 
    return 0;
}
