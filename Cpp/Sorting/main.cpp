#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Sorting - main.cpp
// Here we'll implement a few different sorting algorithms
// Mostly to show that I can still do it in C++. This file 
// simply runs the tests to show that they work!

// This is the C way to do it. Refactor later for std::vector, and 
// use iterators to avoid this messiness with having to know the length
bool isSorted(int * arr, int len) {
    for (int i=1; i<len; i++) {
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

// A pretty print for our arrays
void printArray(int * arr, int len) {
    printf("[");
    for (int i=0; i<len; i++) {
        printf("%d,", arr[i]);
    }
    printf("]\n");
}

int main(int argc, char ** argv) {

    // First, build some test data
    int a[5];

    for (int i=0; i<5; i++) {
        a[i] = 5-i;
    }

    // Print starting array
    printArray(a,5);

    // Call sorting function

    // Print ending array
    printArray(a,5);

    // Check that our sorting routine has correctly sorted 
    printf("isSorted: %s\n", isSorted(a,5)? "True":"False");
    return 1;
}