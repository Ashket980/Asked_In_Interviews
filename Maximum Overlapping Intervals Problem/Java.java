import java.util.Arrays;
 
class Main
{
    // Function to find the point when the maximum number of guests are
    // present in an event
    public static void findMaxGuests(int[] arrival, int[] departure)
    {
        // Find the time when the last guest leaves the event
        int t = Arrays.stream(departure).max().getAsInt();
 
        // create a count array initialized by 0
        int[] count = new int[t + 2];
 
        for (int i = 0; i < arrival.length; i++)
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
 
        System.out.println("Event Time: " + max_event_tm);
        System.out.println("The maximum number of guests is " + count[max_event_tm]);
    }
 
    public static void main(String[] args)
    {
        int[] arrival = { 1, 2, 4, 7, 8, 12 };
        int[] departure = { 2, 7, 8, 12, 10, 15 };
 
        findMaxGuests(arrival, departure);
    }
}
