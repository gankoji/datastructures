#include <iostream>
#include <numeric>
#include "heap.h"

#define NUM_TESTS 3
int main(int argc, char ** argv) {
    int arr[6] = { 1, 2, 3, 5, 4, 6};
    bool tests[NUM_TESTS];

    // Testing our max heap
    // Test creation: heap invariant should hold
    heap testHeap = heap(arr, 6);
    tests[0] = (testHeap.peek() == 6);

    // Test insertion
    testHeap.push(7);
    tests[1] = (testHeap.peek() == 7);

    // Finally, test removal
    int out = testHeap.pop();
    tests[2] = ((testHeap.peek() == 6) && out == 7);

    int sum = std::accumulate(tests, tests+3, 0);
    if (sum == NUM_TESTS) {
        std::cout << "All tests passed.\n";
    } else {
        for (int i=0; i<NUM_TESTS; i++) {
            std::cout << "Test " << i << ": " << (tests[i]? "Passed.\n":"Failed.\n");
        }
    }
    return 0;
}