# Queues are the second of the 'second order data structures' that we build
# here. I call them second order because they depend on a 'first order'
# structure underneath, and simply add functionality thereupon. In this case,
# we'll use a Doubly Linked list, because it simplifies the 'pointer'
# management slightly. We could also use any of the other choices, i.e. arrays
# or singly linked lists.
import DoublyLinkedLists

unitTests = False

class Queue:
    def __init__(self):
        self.items = DoublyLinkedLists.DoublyLinkedList()
        self.tail = self.items.head
        self.empty = True

    def enqueue(self, item):
        if self.empty:
            self.tail = item

        self.items.insert(item)
        self.empty = False

    def dequeue(self):
        if not self.empty:
            temp = self.tail
            self.tail = temp.prevNode
            self.items.delete(temp)

            if self.items.head == None:
                self.empty = True

            return temp
        else:
            print("Error: queue is empty.")
            return None


if unitTests:
    testQueue = Queue()
    testQueue.enqueue(DoublyLinkedLists.Node(1))
    testQueue.enqueue(DoublyLinkedLists.Node(2))
    testQueue.enqueue(DoublyLinkedLists.Node(3))

    print("Queue tests. Expected no errors above.")
    print("Expected 1, 2, 3. Got: " + str(testQueue.dequeue().value)
          + ", " + str(testQueue.dequeue().value)
          + ", " + str(testQueue.dequeue().value))

    print("Now we try to dequeue from an empty queue."
          + " We should get a printed error below. ")
    testQueue.dequeue()

