#include "minheap.h"

minheap::minheap(int * arr, int n) {
    _arr = new int[2*n];
    capacity = 2*n;
    std::copy(arr, arr + n, _arr);
    this->n = n;

    // Build minheap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(i);
}

void minheap::swap(int a, int b) {
    int temp = _arr[a];
    _arr[a] = _arr[b];
    _arr[b] = temp;
}

void minheap::minheapify(int rootIdx) {
    int smallest = rootIdx; // Initialize smallest as root
    int l = 2 * rootIdx + 1;
    int r = 2 * rootIdx + 2;

    // If left child is smaller than root
    if (l < n && _arr[l] < _arr[smallest])
        smallest = l;

    // If right child is larger than smallest so far
    if (r < n && _arr[r] < _arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != rootIdx) {
        swap(rootIdx, smallest);

        // Recursively minheapify the affected sub-tree
        minheapify(smallest);
    }
}

void minheap::printminheap() {
    std::cout << "Internal array: [";
    for (int i=0; i<n-1; i++) {
        std::cout << _arr[i] << ", ";
    }
    std::cout << _arr[n-1] << "];\n";
}

void minheap::ensureCapacity() {
    if (n == capacity) {
        // We've run out of room, make more
        int * temp = new int[2*capacity];
        for (int i=0; i<n; i++) {
            temp[i] = _arr[i];
        }
        _arr = temp;
        capacity *= 2;
    }
}

void minheap::push(int el) {
    ensureCapacity();
    _arr[n] = el;
    n++;
    minheapifyUp();
}

void minheap::minheapifyUp() {
    int index = n-1;
    while (hasParent(index) && parent(index) > _arr[index]) {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void minheap::minheapifyDown() {
    int index = 0;
    while (hasLeftChild(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }

        if (_arr[index] < _arr[smallerChildIndex]) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }

        index = smallerChildIndex;
    }
}

int minheap::peek() {
    if (n == 0) {
        return -1;
    }

    return _arr[0];
}

int minheap::pop() {
    if (n==0) {
        return -1;
    }

    int item = _arr[0];
    _arr[0] = _arr[n-1];
    n--;
    minheapifyDown();
    return item;
}