#include <algorithm>
#include <iostream>

class heap {
    public:
        heap(int* arr, int size);
        void heapify(int rootIdx);
        int pop();
        void push(int el);
        void heapsort();
        void printHeap();

        int * _arr;
    private:
        int n;
        void swap(int a, int b);
};