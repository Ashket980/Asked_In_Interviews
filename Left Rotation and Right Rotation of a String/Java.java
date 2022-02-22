// Java program for Left Rotation and Right
// Rotation of a String
import java.util.*;
import java.io.*;
 
class GFG
{
         
    // function that rotates s towards left by d
    static String leftrotate(String str, int d)
    {
            String ans = str.substring(d) + str.substring(0, d);
            return ans;
    }
 
    // function that rotates s towards right by d
    static String rightrotate(String str, int d)
    {
            return leftrotate(str, str.length() - d);
    }
 
    // Driver code
    public static void main(String args[])
    {
            String str1 = "GeeksforGeeks";
            System.out.println(leftrotate(str1, 2));
 
            String str2 = "GeeksforGeeks";
            System.out.println(rightrotate(str2, 2));
    }
