#include <algorithm>
#include <iostream>

class minheap {
    public:
        minheap(int* arr, int size);
        void minheapify(int rootIdx);
        int pop();
        int peek();
        void push(int el);
        void minheapsort();
        void printminheap();

    private:
        int n;
        int capacity;
        int * _arr;

        void swap(int a, int b);
        void ensureCapacity();
        void minheapifyDown();
        void minheapifyUp();

        int getLeftChildIndex(int parentIndex) { return 2*parentIndex + 1; };
        int getRightChildIndex(int parentIndex) { return 2*parentIndex + 2; };
        int getParentIndex(int childIndex) { return (childIndex - 1)/2; };

        bool hasLeftChild(int index) { return getLeftChildIndex(index) < n;};
        bool hasRightChild(int index) { return getRightChildIndex(index) < n;};
        bool hasParent(int index) { return getParentIndex(index) >= 0;};

        int leftChild(int index) { return _arr[getLeftChildIndex(index)]; };
        int rightChild(int index) { return _arr[getRightChildIndex(index)]; };
        int parent(int index) { return _arr[getParentIndex(index)]; };
};