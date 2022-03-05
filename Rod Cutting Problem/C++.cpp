#include <iostream>
#include <string>
using namespace std;
 
// Function to find the best way to cut a rod of length `n`
// where the rod of length `i` has a cost `price[i-1]`
int rodCut(int price[], int n)
{
    // `T[i]` stores the maximum profit achieved from a rod of length `i`
    int T[n + 1];
 
    // initialize maximum profit to 0
    for (int i = 0; i <= n; i++) {
        T[i] = 0;
    }
 
    // consider a rod of length `i`
    for (int i = 1; i <= n; i++)
    {
        // divide the rod of length `i` into two rods of length `j`
        // and `i-j` each and take maximum
        for (int j = 1; j <= i; j++) {
            T[i] = max(T[i], price[j - 1] + T[i - j]);
        }
    }
 
    // `T[n]` stores the maximum profit achieved from a rod of length `n`
    return T[n];
}
 
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
 
    // rod length
    int n = 4;
 
    cout << "Profit is " << rodCut(price, n);
 
    return 0;
}
