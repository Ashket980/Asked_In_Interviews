#include <iostream>
#include <vector>
using namespace std;
 
// Utility function to print contents of a vector
void printArray(vector<int> &arr)
{
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}
 
// Function to merge two sorted vectors X[] and Y[] from their end
vector<int> merge(vector<int> const &X, vector<int> const &Y)
{
    int i = X.size() - 1, j = Y.size() - 1;
 
    vector<int> aux(X.size() + Y.size());
    int k = 0;
 
    // while there are elements in the first and second arrays
    while (i >= 0 && j >= 0)
    {
        if (X[i] >= Y[j]) {
            aux[k++] = X[i--];
        }
        else {
            aux[k++] = Y[j--];
        }
    }
 
    // copy remaining elements
    while (i >= 0) {
        aux[k++] = X[i--];
    }
 
    while (j >= 0) {
        aux[k++] = Y[j--];
    }
 
    return aux;
}
 
int main()
{
    vector<int> X = { 1, 4, 7, 8 };
    vector<int> Y = { 2, 3, 9 };
 
    vector<int> aux = merge(X, Y);
 
    cout << "First Array : "; printArray(X);
    cout << "Second Array: "; printArray(Y);
    cout << "After Merge : "; printArray(aux);
 
    return 0;
}
