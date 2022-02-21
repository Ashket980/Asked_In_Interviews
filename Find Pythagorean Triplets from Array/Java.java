import static java.lang.Integer.max;
import java.util.Scanner;
class sum
{
    public static void main(String[] args)  
    { 
        Scanner sr = new Scanner(System.in);
        int n = sr.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = sr.nextInt();
        }
        int a,b,c;
        for(int i=0;i<n-2;i++)//select an element
        {
            for(int j=i+1;j<n-1;j++)//select an element in front of the considered element
            {
                for(int k=i+2;k<n;k++)// this element will be one ahead of the previously selected element in the jus touter loop
                {
                  a = arr[i];
                  b = arr[j];
                  c = arr[k];
                  if(a*a + b*b == c*c) // if the chosen elements satisfy the pythagoras theorem then simply print the three values.
                    System.out.println(a +"  "+b+"  "+c);
                }
              }
          }
    }
}
