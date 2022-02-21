<script>
// Program to find minimum number of platforms
// required on a railway station
 
function max(a,b)
{
    if(a==b)
         return a;
    else{
        if(a>b)
            return a;
        else
            return b;
       }
}
 
// Returns minimum number of platforms required
function findPlatform( arr, dep, n)
{
 
    // plat_needed indicates number of platforms
    // needed at a time
    var plat_needed = 1, result = 1;
    var i = 1, j = 0;
 
    // run a nested loop to find overlap
    for (var i = 0; i < n; i++) {
        // minimum platform
        plat_needed = 1;
 
        for (var j = i + 1; j < n; j++) {
            // check for overlap
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
        (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }
 
        // update result
        result = max(result, plat_needed);
    }
 
    return result;
}
 
var arr = [ 900, 940, 950, 1100, 1500, 1800 ];
    var dep = [ 910, 1200, 1120, 1130, 1900, 2000 ];
    var n =6;
    document.write("Minimum Number of Platforms Required = "
        +findPlatform(arr, dep, n));
 
 
</script>
