# Python3 program for Left
# Rotation and Right
# Rotation of a String
 
# In-place rotates s towards left by d
def leftrotate(s, d):
    tmp = s[d : ] + s[0 : d]
    return tmp
   
# In-place rotates s
# towards right by d
def rightrotate(s, d):
   
   return leftrotate(s, len(s) - d)
 
# Driver code
if __name__=="__main__":
     
    str1 = "GeeksforGeeks"
    print(leftrotate(str1, 2))
  
    str2 = "GeeksforGeeks"
    print(rightrotate(str2, 2))
