#include <iostream>
#include <numeric>
#include "maxheap.h"
#include "minheap.h"

#define NUM_TESTS 6
int main(int argc, char ** argv) {
    int arr[6] = { 1, 2, 3, 5, 4, 6};
    bool tests[NUM_TESTS];

    // Testing our max maxheap
    // Test creation: maxheap invariant should hold
    maxheap testmaxheap = maxheap(arr, 6);
    minheap testminheap = minheap(arr, 6);
    
    tests[0] = (testmaxheap.peek() == 6);
    tests[3] = (testminheap.peek() == 1);

    // Test insertion
    testmaxheap.push(7);
    testminheap.push(0);

    tests[1] = (testmaxheap.peek() == 7);
    tests[4] = (testminheap.peek() == 0);

    // Finally, test removal
    int out = testmaxheap.pop();
    tests[2] = ((testmaxheap.peek() == 6) && out == 7);

    int out2 = testminheap.pop();
    tests[5] = ((testminheap.peek() == 1) && out2 == 0);

    int sum = std::accumulate(tests, tests+NUM_TESTS, 0);
    if (sum == NUM_TESTS) {
        std::cout << "All tests passed.\n";
    } else {
        for (int i=0; i<NUM_TESTS; i++) {
            std::cout << "Test " << i << ": " << (tests[i]? "Passed.\n":"Failed.\n");
        }
    }
    return 0;
}