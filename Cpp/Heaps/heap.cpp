#include "heap.h"

heap::heap(int * arr, int n) {
    _arr = new int[2*n];
    capacity = 2*n;
    std::copy(arr, arr + n, _arr);
    this->n = n;

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(i);
}

void heap::swap(int a, int b) {
    int temp = _arr[a];
    _arr[a] = _arr[b];
    _arr[b] = temp;
}

void heap::heapify(int rootIdx) {
    int largest = rootIdx; // Initialize largest as root
    int l = 2 * rootIdx + 1;
    int r = 2 * rootIdx + 2;

    // If left child is larger than root
    if (l < n && _arr[l] > _arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && _arr[r] > _arr[largest])
        largest = r;

    // If largest is not root
    if (largest != rootIdx) {
        swap(rootIdx, largest);

        // Recursively heapify the affected sub-tree
        heapify(largest);
    }
}

void heap::printHeap() {
    std::cout << "Internal array: [";
    //printf("Here in printheap\n");
    for (int i=0; i<n-1; i++) {
        std::cout << _arr[i] << ", ";
    }
    std::cout << _arr[n-1] << "];\n";
}

void heap::ensureCapacity() {
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

void heap::push(int el) {
    ensureCapacity();
    _arr[n] = el;
    n++;
    heapifyUp();
}

void heap::heapifyUp() {
    int index = n-1;
    while (hasParent(index) && parent(index) < _arr[index]) {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void heap::heapifyDown() {
    int index = 0;
    while (hasLeftChild(index)) {
        int largerChildIndex = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) > leftChild(index)) {
            largerChildIndex = getRightChildIndex(index);
        }

        if (_arr[index] > _arr[largerChildIndex]) {
            break;
        } else {
            swap(index, largerChildIndex);
        }

        index = largerChildIndex;
    }
}

int heap::peek() {
    if (n == 0) {
        return -1;
    }

    return _arr[0];
}

int heap::pop() {
    if (n==0) {
        return -1;
    }

    int item = _arr[0];
    _arr[0] = _arr[n-1];
    n--;
    heapifyDown();
    return item;
}