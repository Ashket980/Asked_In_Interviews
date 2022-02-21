# Python3 program to demonstrate insert operation in binary
# search tree.
# class for creating node
class Node():
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.count = 1  # count of number of times data is inserted in tree
 
# class for binary search tree
# it initialises tree with None root
# insert function inserts node as per BST rule
# and also checks for majority element
# if no majority element is found yet, it returns None
 
 
class BST():
    def __init__(self):
        self.root = None
 
    def insert(self, data, n):
        out = None
        if (self.root == None):
            self.root = Node(data)
        else:
            out = self.insertNode(self.root, data, n)
        return out
 
    def insertNode(self, currentNode, data, n):
        if (currentNode.data == data):
            currentNode.count += 1
            if (currentNode.count > n//2):
                return currentNode.data
            else:
                return None
        elif (currentNode.data < data):
            if (currentNode.right):
                self.insertNode(currentNode.right, data, n)
            else:
                currentNode.right = Node(data)
        elif (currentNode.data > data):
            if (currentNode.left):
                self.insertNode(currentNode.left, data, n)
            else:
                currentNode.left = Node(data)
 
 
# Driver code
# declaring an array
arr = [3, 2, 3]
n = len(arr)
 
# declaring None tree
tree = BST()
flag = 0
for i in range(n):
    out = tree.insert(arr[i], n)
    if (out != None):
        print(arr[i])
        flag = 1
        break
if (flag == 0):
    print("No Majority Element")
