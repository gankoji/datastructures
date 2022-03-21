#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>
#include <vector>
#include <iostream>
using namespace std;

// Sorting - main.cpp
// Here we'll implement a few different sorting algorithms
// Mostly to show that I can still do it in C++. This file 
// simply runs the tests to show that they work!

bool isSorted(vector<int> arr) {
    int len = arr.size();
    for (int i=1; i<len; i++) {
        if (arr[i-1] > arr[i]) return false;
    }
    return true;
}

void printVector(vector<int> v) {
    cout << "v = { ";
    for (int n : v) {
        cout << n << ", ";
    }
    cout << "}; \n";
}

// Basic mergesort
vector<int> mergeSort(vector<int> arr) {
    // Check the base case, a 1 element array is vacuously sorted 
    int len = arr.size();
    if (len <= 1) {
        return arr;
    }

    // Split the array in two
    int halflen = len/2;
    vector<int> a, b;

    for (int i=0; i<halflen; i++) {
        a.push_back(arr.at(i));
    }

    for (int i=halflen; i<len; i++) {
        b.push_back(arr.at(i));
    }

    // Recurse on halves
    vector<int> asorted = mergeSort(a);
    vector<int> bsorted = mergeSort(b);

    // Merge sorted halves
    vector<int> output;
    int i=0, j=0, k=0;
    while (k < len) {
        if ((i < (halflen)) && (j < (len - halflen))) {
            if (asorted[i] <= bsorted[j]) {
                output.push_back(asorted[i]);
                i++; k++;
            } else {
                output.push_back(bsorted[j]);
                j++; k++;
            }
        } else if (i < (halflen)) {
            output.push_back(asorted[i]);
            i++; k++;
        } else {
            output.push_back(bsorted[j]);
            j++; k++;
        }
    }

    return output;
}

void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

int main(int argc, char ** argv) {

    signal(SIGSEGV, handler);
    // First, build some test data
    int arrSize = (int)1e8;
    vector<int> a;

    for (int i=0; i<arrSize; i++) {
        a.push_back(rand()%20000);
    }

    // Call sorting function
    vector<int> asorted;
    asorted = mergeSort(a);

    // Check that our sorting routine has correctly sorted 
    printf("Testing MergeSort on an array with %d elements.\n", arrSize);
    printf("isSorted: %s\n", isSorted(asorted)? "True":"False");
    return 1;
}