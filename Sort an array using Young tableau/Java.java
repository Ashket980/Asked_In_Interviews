import java.util.Arrays;
 
class YoungTableau
{
    // Function construct an `N × N` Young tableau from the given keys
    public static int[][] construct(int[] keys)
    {
        // calculate N
        int N = (int) Math.ceil(Math.sqrt(keys.length));
 
        int[][] tableau = new int[N][N];
 
        // initialize the Young tableau by infinity
        for (int i = 0; i < N; i++) {
            Arrays.fill(tableau[i], Integer.MAX_VALUE);
        }
 
        // do for each key
        for (int key : keys) {
            // check for overflow
            if (tableau[N - 1][N - 1] != Integer.MAX_VALUE) {
                break;
            }
 
            // place the key at the bottom-right corner of the tableau
            tableau[N - 1][N - 1] = key;
 
            // move the key to its correct position in the tableau
            insert(tableau, N - 1, N - 1);
        }
 
        return tableau;
    }
 
    // Recursive function to fix the tableau property in an `N × N` Young tableau.
    // An infinite value is initially placed at the first cell `(0, 0)` of the tableau.
    // The function works by swapping the smallest of `[i+i, j]` and `[i, j+1]` with
    // `[i, j]` and recur for the smaller value.
 
    private static void fixTableau(int[][] tableau, int i, int j) {
 
        int N = tableau.length;
 
        // get the values present at the bottom and right cell of the current cell
        int bottom = (i + 1 < N) ? tableau[i + 1][j] : Integer.MAX_VALUE;
        int right = (j + 1 < N) ? tableau[i][j + 1] : Integer.MAX_VALUE;
 
        if (bottom == Integer.MAX_VALUE && right == Integer.MAX_VALUE) {
            return;
        }
 
        if (bottom < right)        // go down
        {
            // swap `tableau[i][j]` and `tableau[i+1][j]`
 
            int temp = tableau[i][j];
            tableau[i][j] = tableau[i + 1][j];
            tableau[i + 1][j] = temp;
 
            fixTableau(tableau, i + 1, j);
        }
        else        // go right
        {
            // swap `tableau[i][j]` and `tableau[i][j+1]`
 
            int temp = tableau[i][j];
            tableau[i][j] = tableau[i][j + 1];
            tableau[i][j + 1] = temp;
 
            fixTableau(tableau, i, j + 1);
        }
    }
 
    // Function to extract the next minimum element from the Young tableau
    public static int extractMin(int[][] tableau) {
        // the first cell of the tableau stores the minimum element
        int min = tableau[0][0];
 
        // make the first element as infinity
        tableau[0][0] = Integer.MAX_VALUE;
 
        // fix the Young tableau property
        fixTableau(tableau, 0, 0);
 
        return min;
    }
 
    // Recursive function to insert a new element into a non-full `N × N` Young tableau
    // The new element is initially placed at the bottom-right corner of the tableau.
    // The function works by swapping the smallest of `[i-i, j]` and `[i, j-1]` with
    // `[i, j]` and recur for the smaller value.
 
    private static void insert(int[][] tableau, int i, int j) {
        // base case
        if (i == 0 && j == 0) {
            return;
        }
 
        // handle separately for the first row
        if (i == 0) {
            if (tableau[i][j] < tableau[i][j - 1]) {
                // swap `tableau[i][j]` and `tableau[i][j-1]`
                int temp = tableau[i][j];
                tableau[i][j] = tableau[i][j - 1];
                tableau[i][j - 1] = temp;
 
                insert(tableau, i, j - 1);
            }
            return;
        }
 
        // handle separately for the first column
        if (j == 0) {
            if (tableau[i][j] < tableau[i - 1][j]) {
                // swap `tableau[i][j]` and `tableau[i-1][j]`
 
                int temp = tableau[i][j];
                tableau[i][j] = tableau[i - 1][j];
                tableau[i - 1][j] = temp;
 
                insert(tableau, i - 1, j);
            }
            return;
        }
 
        if (tableau[i][j] < tableau[i - 1][j])        // go up
        {
            // swap `tableau[i][j]` and `tableau[i-1][j]`
 
            int temp = tableau[i][j];
            tableau[i][j] = tableau[i - 1][j];
            tableau[i - 1][j] = temp;
 
            insert(tableau, i - 1, j);
        }
 
        if (tableau[i][j] < tableau[i][j - 1])        // go left
        {
            // swap `tableau[i][j]` and `tableau[i][j-1]`
 
            int temp = tableau[i][j];
            tableau[i][j] = tableau[i][j - 1];
            tableau[i][j - 1] = temp;
 
            insert(tableau, i, j - 1);
        }
    }
}
 
public class Main
{
    public static void sort(int[] keys)
    {
        if (keys == null || keys.length == 0) {
            return;
        }
 
        // construct a Young tableau from the above keys
        int[][] tableau = YoungTableau.construct(keys);
 
        // repeatedly call `extractMin()` and fill `keys[]` with the returned values
        for (int i = 0; i < keys.length; i++) {
            keys[i] = YoungTableau.extractMin(tableau);
        }
    }
 
    public static void main(String[] args)
    {
        // unsorted input
        int[] keys = {6, 4, 8, 7, 2, 3, 1, 5};
 
        // sort the input keys
        sort(keys);
 
        // print the sorted input
        System.out.println(Arrays.toString(keys));
    }
}
