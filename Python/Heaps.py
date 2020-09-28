# The classic heap. A heap is a general term for any tree or tree-like
# structure (even arrays where an assumed relation is present between the
# 'nodes') which satisfies the heap property. The heap property is such: "In a
# max(min)-heap, every node's key is greater (less) than the key of all its
# children."

# Heaps are useful for a great many applications, but the most commonly cited
# is a priority queue. Any instance where we need a datastructure which can
# quickly and repeatedly retrieve the max(min) key item from its store is
# appropriate for a heap.

# The heap implemented here is a binary max heap. Making it a min heap requires
# only that we change the comparison operator used in the appropriate few
# places. We use an array for node storage, since that is maximally efficient
# (spacewise) for simple nodes.

from math import floor
unitTests = True
class binaryMaxHeap():
    def __init__(self):
        self.array = []
        self.lastopen = 0

    def build(self, newArray):
        n = len(newArray)
        self.array = newArray
        start = int(floor(n/2))

        for i in range(start, -1, -1):
            self.maxHeapify(i)

    def insert(self, item):
        self.array.append(item)
        self.bubbleup(self.lastopen)
        self.lastopen += 1

    def extract(self):
        temp = self.array[0]
        last = self.array.pop(-1)
        if len(self.array) != 0:
            self.array[0] = last
            self.maxHeapify(0)

        self.lastopen -= 1
        return temp

    def bubbleup(self, start):
        parent = int(floor(start/2))
        if self.array[parent] < self.array[start]:
            temp = self.array[parent]
            self.array[parent] = self.array[start]
            self.array[start] = temp
            self.bubbleup(parent)

    def maxHeapify(self, start):
        left = 2*(start+1) - 1
        right = 2*(start+1)
        largest = start

        if left <= (len(self.array) - 1) and self.array[left] > self.array[largest]:
            largest = left

        if right <= (len(self.array) - 1) and self.array[right] > self.array[largest]:
            largest = right

        if largest != start:
            temp = self.array[start]
            self.array[start] = self.array[largest]
            self.array[largest] = temp
            self.maxHeapify(largest)

if unitTests:
    numEls = 64
    print("Testing Heaps.")
    print(f"Expected behavior: full heap printed ({numEls} els)")
    print(f"Then a descending list from {numEls}-0")
    print("Finally, an empy heap printed")

    testHeap = binaryMaxHeap()
    for i in range(0,numEls):
        testHeap.insert(i)

    print(testHeap.array)
    newArray = [i for i in range(numEls)]
    testHeap.build(newArray)
    print(testHeap.array)
    for i in range(0,numEls):
        print(testHeap.extract())

    print(testHeap.array)
