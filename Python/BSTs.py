# Another classic data structure, the Binary Search Tree. BSTs share much with
# binary heaps, in terms of structure and maintenance operations. However,
# their intended use is slightly different, in that we're often using BSTs when
# we want to be able to find a node with a given key quickly, but don't want to
# pay the worst-case penalty of a hashmap/dictionary, or the
# complexity penalty of a B-tree. The 'penalty' associated with BSTs with
# respect to the other two options mentioned is in time complexity. From
# Wikipedia, here is the table of complexities associated with the BST:

# Operation   Average    Worst Case
# (Space)     O(n)       O(n)
# Insert      O(log n)   O(n)
# Search      O(log n)   O(n)
# Delete      O(log n)   O(n)
unitTests = True

class bstNode():
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key

class binarySearchTree():
    def __init__(self):
        self.root = None

    def search(self, key):
        return self.searchRecursively(self.root, key)

    def searchRecursively(self, node, key):
        if node == None or node.key == key:
            return node
        if key < node.key:
            return self.searchRecursively(node.left, key)
        if key > node.key:
            return self.searchRecursively(node.right, key)

    def findParent(self, key):
        # We are effectively repeating the search algorithm here
        # but this time we want to return the parent of the node found
        if self.root.key == key:
            return None
        else:
            return self.findParentRecursively(None, self.root, key)

    def findParentRecursively(self, parent, node, key):
        if node == None:
            return None
        else:
            if node.key == key:
                return parent
            if key < node.key:
                return self.findParentRecursively(node, node.left, key)
            else:
                return self.findParentRecursively(node, node.right, key)

    def insert(self, node):
        if self.root == None:
            self.root = node
        else:
            self.insertRecursively(self.root, node)

    def insertRecursively(self, root, node):
        if node.key == root.key:
            # nothing to do, since we're disallowing dupes
            return
        elif node.key < root.key:
            if root.left == None:
                root.left = node
                return
            else:
                self.insertRecursively(root.left, node)
        else:
            if root.right == None:
                root.right = node
                return
            else:
                self.insertRecursively(root.right, node)

    def delete(self, key):
        node = self.search(key)
        self.deleteNode(node)

    def deleteNode(self, node, parent=None):
        # Delete is the most complicated of the three operations
        # It's the trickiest because a) we have three cases to consider, and b)
        # we also need to maintain information on the parent of the node to be
        # deleted.
        # We have three cases, dependent on the node's children
        if parent == None:
            parent = self.findParent(node.key)

        if node.left == None and node.right == None:
            # No children, simply remove from the tree
            if parent == None:
                self.root = None
                return

            if (parent.left != None) and parent.left.key == node.key:
                parent.left = None
            else:
                parent.right = None

            return
        elif (node.left != None) and (node.right != None):
            # Case 3: Two children
            minNode = self.findMin(node)
            parent = self.findParent(minNode.key)
            node.key = minNode.key
            self.deleteNode(minNode, parent)

        else:
            #We have only one child, make it the child of parent
            if node.left == None:
                if parent == None:
                    self.root = node.right
                    return

                if parent.left == None:
                    parent.right = node.right
                else:
                    parent.left = node.right
            else:
                if parent == None:
                    self.root = node.left
                    return

                if parent.left == None:
                    parent.right = node.left
                else:
                    parent.left = node.left

    def findMin(self, node):
        while node.left:
            node = node.left

        return node

if unitTests:
    testTree = binarySearchTree()
    testTree.insert(bstNode(2))
    testTree.insert(bstNode(5))
    testTree.insert(bstNode(1))

    searched = testTree.search(2)
    if searched == None:
        print("Error: couldn't find an element we just inserted.")

    if testTree.findParent(2) != None:
        print("Error finding 2's parent.")

    if testTree.findParent(5).key != 2:
        print("Error finding 5's parent.")

    testTree.delete(2)
    if testTree.search(5).key != 5:
        print("Error finding 5 after root deletion.")
    if testTree.search(1).key != 1:
        print("Error finding 1 after root deletion.")

    print("Testing Binary Search Trees.")
    print(f"Tree root should now be 1. Got: {testTree.root.key}")
