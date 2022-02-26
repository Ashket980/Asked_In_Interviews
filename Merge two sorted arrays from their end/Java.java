import java.util.Arrays;
 
class Main
{
    // Function to merge two sorted arrays X[] and Y[] from their end
    public static int[] merge(int[] X, int[] Y)
    {
        int i = X.length - 1, j = Y.length - 1;
 
        int[] aux = new int[X.length + Y.length];
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
 
    public static void main (String[] args)
    {
        int[] X = { 1, 4, 7, 8 };
        int[] Y = { 2, 3, 9 };
 
        int[] aux = merge(X, Y);
 
        System.out.println("First Array : " + Arrays.toString(X));
        System.out.println("Second Array: " + Arrays.toString(Y));
        System.out.println("After Merge : " + Arrays.toString(aux));
    }
}
