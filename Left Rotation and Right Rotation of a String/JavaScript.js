<script>
 
// JavaScript program for Left Rotation and Right
// Rotation of a String
 
// Function that rotates s towards left by d
function leftrotate(str, d)
{
    var ans = str.substring(d, str.length) +
              str.substring(0, d);
    return ans;
}
 
// Function that rotates s towards right by d
function rightrotate(str, d)
{
    return leftrotate(str, str.length - d);
}
 
// Driver code
var str1 = "GeeksforGeeks";
document.write(leftrotate(str1, 2) + "<br>");
 
var str2 = "GeeksforGeeks";
document.write(rightrotate(str2, 2) + "<br>");
 
// This code is contributed by rdtank
 
</script>
