# A class to store a Doubly Linked List / BST node
class Node:
    # The `prev` and `next` pointer of the doubly linked list can act as
    # left and right child for the BST, respectively
    def __init__(self, data, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next
 
 
# Function to insert a new node at the beginning of the doubly linked list
def push(head, data):
 
    # allocate a new node and link it at the beginning
    node = Node(data)
    node.next = head
 
    # change `prev` of the existing head node to point to the new node
    if head:
        head.prev = node
 
    # update head pointer
    head = node
    return head
 
 
# Function to print nodes of a doubly linked list
def printListNodes(node):
 
    while node:
        print(node.data, end=' ')
        node = node.next
    print()
 
 
# Function to print preorder traversal of the BST
def preorder(root):
 
    if root is None:
        return
 
    print(root.data, end=' ')
    preorder(root.prev)
    preorder(root.next)
 
 
# Function to push nodes of a given BST in a list
def pushDDLNodes(node, nodes):
 
    while node:
        nodes.append(node)
        node = node.next
 
 
# Recursive function to construct a height-balanced BST from
# given nodes in sorted order
def buildBalancedBST(nodes, start, end):
 
    # base case
    if start > end:
        return None
 
    # find the middle index
    mid = (start + end) // 2
 
    # The root node will be a node present at the mid-index
    root = nodes[mid]
 
    # recursively construct left and right subtree
    root.prev = buildBalancedBST(nodes, start, mid - 1)
    root.next = buildBalancedBST(nodes, mid + 1, end)
 
    # return root node
    return root
 
 
# Function to construct a height-balanced BST from a sorted doubly linked list.
def convertSortedDLLToBalancedBST(head):
 
    # Push nodes of a given BST into a list in the original order
    nodes = []
    pushDDLNodes(head, nodes)
 
    # Construct a height-balanced BST from sorted BST nodes
    return buildBalancedBST(nodes, 0, len(nodes) - 1)
 
 
if __name__ == '__main__':
 
    # points to the head of a doubly linked list
    head = None
 
    # construct a doubly linked list from sorted keys
    keys = [25, 20, 18, 15, 12, 10, 8]
    for key in keys:
        head = push(head, key)
 
    print('Doubly Linked List: ', end='')
    printListNodes(head)
 
    # construct a height-balanced BST from a sorted doubly linked list
    root = convertSortedDLLToBalancedBST(head)
 
    print('Preorder traversal of the constructed BST: ', end='')
    preorder(root)
