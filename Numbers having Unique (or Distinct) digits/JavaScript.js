<script>
 
// Javascript implementation to find unique digit
// numbers in a range
 
// Function to print unique digit numbers
// in range from l to r.
function printUnique(l, r)
{
    // Start traversing the numbers
    for (let i=l ; i<=r ; i++)
    {
        let num = i;
        let visited = new Array(10);
 
        // Find digits and maintain its hash
        while (num)
        {
            // if a digit occurs more than 1 time
            // then break
            if (visited[num % 10])
                break;
 
            visited[num%10] = true;
 
            num = Math.floor(num/10);
        }
 
        // num will be 0 only when above loop
        // doesn't get break that means the
        // number is unique so print it.
        if (num == 0)
            document.write(i + " ");
    }
}
 
// Driver code
 
    let l = 1, r = 20;
    printUnique(l, r);
     
 
</script>
