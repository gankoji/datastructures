# The venerable B-Tree is a marvel of datastructure ingenuity. Often found as
# the "index" structure underlying databases, they're most useful for their
# guaranteed worst case performance, which is O(log n) for insert, search, and
# deletion. This is particularly important in large external datastores (e.g.
# databases) where the majority of data lies on disks, as reducing the
# operation cost in terms of disk seeks has significant repercussions on
# overall operation time. However, it is important to note that the performance
# quoted above is a bound only in the asymptotic sense, meaning that for
# less-than-astonomically sized datasets, the performance of a B-tree could be
# (and often is) many times worse than simpler structures, such as a BST.

# The key challenge with B-trees is the splitting of nodes and rearranging of
# keys that can occur during inserts and deletions. Searching a B-tree is
# trivial, as that is the exact operation it was designed/optimized for.

# The rules of m-ary B-Trees, according to Knuth:
# Every node has at most m children
# Every node, except for the root and leaves, has at least m/2 children
# The root has at least 2 children, unless it is itself a leaf (the tree is
# empty)
# All leaves appear on the same level, and carry no information
# A nonleaf node with k children contains k-1 keys. 

unitTests = True

class BNode:
    def __init__(self):
        self.children = []
        self.keys = []

    def lowerBound(self, key):
        # Use binary search to find the place in children where this key should
        # go.
        l = 0
        u = len(self.children) - 1
        while l < u:
            #print(l)
            #print(u)
            mid = (l + u + 1)//2
            if self.keys[mid-1] <= key:
                l = mid
            else:
                u = mid - 1
        return l

if unitTests:
    testNode = BNode()
    testNode.keys = [1, 2, 3, 4, 5, 6]
    testNode.children = (len(testNode.keys)+1)*[BNode()]

    if testNode.lowerBound(4) == 4:
        print("Success")
    else:
        print("You donkey.")
