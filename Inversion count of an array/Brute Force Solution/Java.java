class Main
{
    // Function to find inversion count of a given array
    public static int findInversionCount(int[] arr)
    {
        int inversionCount = 0;
 
        for (int i = 0; i < arr.length - 1; i++)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr[i] > arr[j]) {
                    inversionCount++;
                }
            }
        }
 
        return inversionCount;
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 1, 9, 6, 4, 5 };
 
        System.out.println("The inversion count is " + findInversionCount(arr));
    }
}
