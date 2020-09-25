import DoublyLinkedLists

unitTests = True

class Deque:
    def __init__(self):
        self.items = DoublyLinkedLists.DoublyLinkedList()
        self.head = self.items.head
        self.tail = self.items.tail
        self.empty = True

    def enqueueLeft(self, item):
        self.items.insert(item)
        self.tail = self.items.tail
        self.head = self.items.head
        self.empty = False

    def enqueueRight(self, item):
        self.items.insertRight(item)
        self.head = self.items.head
        self.tail = self.items.tail
        self.empty = False

    def dequeueLeft(self):
        if not self.empty:
            temp = self.head
            self.head = temp.nextNode
            self.items.delete(temp)

            if self.head == None:
                self.empty = True

            return temp
        else:
            print("Error: tried to dequeueLeft from an empty Deque.")
            return None

    def dequeueRight(self):
        if not self.empty:
            temp = self.tail
            self.tail = temp.prevNode
            self.items.delete(temp)

            if self.items.head == None:
                self.head = None
                self.tail = None
                self.empty = True

            return temp
        else:
            print("Error: tried to dequeueRight from an empty Deque.")
            return None


if unitTests:
    testDeque = Deque()
    testDeque.enqueueLeft(DoublyLinkedLists.Node(1))
    testDeque.enqueueLeft(DoublyLinkedLists.Node(2))
    testDeque.enqueueLeft(DoublyLinkedLists.Node(3))

    print("Deque tests. Expected no errors above.")
    print("Expected 1, 2, 3. Got: " + str(testDeque.dequeueRight().value)
          + ", " + str(testDeque.dequeueRight().value)
          + ", " + str(testDeque.dequeueRight().value))

    print("Now we try to dequeue from an empty queue."
          + " We should get two printed errors below. ")
    testDeque.dequeueRight()
    testDeque.dequeueLeft()

    print("Finally, try things the other direction.")
    print("(Right to left this time)")
    testDeque.enqueueRight(DoublyLinkedLists.Node(1))
    testDeque.enqueueRight(DoublyLinkedLists.Node(2))
    testDeque.enqueueRight(DoublyLinkedLists.Node(3))

    print("Expected 1, 2, 3. Got: " + str(testDeque.dequeueLeft().value)
          + ", " + str(testDeque.dequeueLeft().value)
          + ", " + str(testDeque.dequeueLeft().value))
