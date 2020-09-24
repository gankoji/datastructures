# Stacks are again absent from Python's native datatypes.
unitTests = True

class Stack:
    def __init__(self):
        self.data = []

    def push(self, el):
        self.data.append(el)

    def pop(self):
        return self.data.pop()


if unitTests:
    testStack = Stack()

    testStack.push(1)
    testStack.push(2)
    print("Stack test. Expected 2, got: " + str(testStack.pop()))
    print("Second stack test. Expected 1, got: " + str(testStack.pop()))
