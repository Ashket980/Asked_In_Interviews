#include <bits/stdc++.h>
using namespace std;
int main()
{
  
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;i++)
  {
      cin>>arr[i];
  }
  int a,b,c;
  for(int i = 0; i < N-2; i++)//select an element
  {
    for(int j=i+1;j <N-1; j++)//select an element in front of the considered element
      {
        for(int k =i+2; k<N;k++)// this element will be one ahead of the previously selected element in the jus touter loop
        {
          a = arr[i];
          b = arr[j];
          c = arr[k];
          if(a*a + b*b == c*c) // if the chosen elements satisfy the pythagoras theorem then simply print the three values.
            cout << a <<"  "<<b<<"  "<<c<<endl;
            
        }
      }
  }  
  return 0;
}
