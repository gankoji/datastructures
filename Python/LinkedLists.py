# Linked lists are *not* native to Python, so we'll have a slight bit more work
# here

unitTests = False
# First, define a single element of the list

class Node:
    def __init__(self, val):
        self.value = val
        self.nextNode = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, node):
        if not (self.head == None):
            node.nextNode = self.head

        self.head = node

    def search(self, value):
        current = self.head
        prev = None

        while not (current == None):
            if current.value == value:
                # We've found the node
                return current
            else:
                prev = current
                current = current.nextNode

        # If we reach this, we've traversed the list and not found the element.
        print("Error, value not found in list")
        return None

    def delete(self, node):
        current = self.head
        prev = None

        while not (current == None):
            if current.value == node.value:
                # We've found the node
                if prev == None:
                    self.head = self.head.nextNode
                else:
                    prev.nextNode = current.nextNode
                return
            else:
                prev = current
                current = current.nextNode


        # If we reach this, we've traversed the list and not found the element.
        print("Error, node not found in list, can't delete it.")
        return


if unitTests:
    testList = LinkedList()

    testList.insert(Node(1))
    testList.insert(Node(2))
    testList.search(2)
    testList.delete(Node(1))

    print("Linked List. Expected no printed errors, got above.")
