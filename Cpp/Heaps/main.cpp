#include <iostream>
#include "heap.h"

int main(int argc, char ** argv) {
    int arr[5] = { 1, 2, 3, 5, 4};

    heap testHeap = heap(arr, 5);
    //testHeap.heapify(0);
    testHeap.printHeap();

    return 0;
}