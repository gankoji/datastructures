unitTests = False
# First, define a single element of the list

class Node:
    def __init__(self, val):
        self.value = val
        self.nextNode = None
        self.prevNode = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, node):
        if (self.head == None):
            self.head = node
            self.tail = node
        else:
            node.nextNode = self.head
            self.head.prevNode = node
            self.head = node

    def insertRight(self, node):
        if (self.tail == None):
            self.head = node
            self.tail = node
        else:
            node.prevNode = self.tail
            self.tail.nextNode = node
            self.tail = node

    def search(self, value):
        current = self.head

        while not (current == None):
            if current.value == value:
                # We've found the node
                return current
            else:
                current = current.nextNode

        # If we reach this, we've traversed the list and not found the element.
        print("Error, value not found in list")
        return None

    def delete(self, node):
        current = self.head
        success = False

        while not (current == None):
            if current.value == node.value:
                # We've found the node
                success = True
                if  current.prevNode == None:
                    # We've found the head
                    self.head = current.nextNode
                    if not (self.head == None):
                        self.head.prevNode = None
                    else:
                        self.tail = None
                elif current.nextNode == None:
                    # We've found the tail
                    self.tail = current.prevNode
                    if not (self.tail == None):
                        self.tail.nextNode = None
                    else:
                        self.head = None
                else:
                    # We're somewhere else in the list
                    current.nextNode.prevNode = current.prevNode
                    current.prevNode.nextNode = current.nextNode

                break
            else:
                current = current.nextNode


        if not success:
            # If we reach this, we've traversed the list and not found the element.
            print("Error, node not found in list, can't delete it.")


if unitTests:
    testList = DoublyLinkedList()

    testList.insert(Node(1))
    testList.search(1)
    print(testList.head.value)
    testList.delete(Node(1))
    if (not (testList.head == None)) or (not (testList.head == None)):
        print("Error: list doesn't think it's empty")
    testList.insert(Node(1))
    testList.insert(Node(2))
    testList.search(2)
    testList.delete(Node(1))


    testList.insertRight(Node(3))
    testList.insertRight(Node(4))

    # Print the contents of the list at this point, for good measure
    current = testList.head
    while not (current == None):
        print(current.value)
        current = current.nextNode

    testList.search(3)
    testList.delete(Node(3))
    print("Doubly Linked List. Expected no printed errors, got above.")

