#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "quicksort.h"
#include "mergesort.h"
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

int main(int argc, char ** argv) {

    // First, build some test data
    int arrSize = (int)1e5;
    vector<int> a;

    for (int i=0; i<arrSize; i++) {
        a.push_back(rand()%20000);
    }

    // Call sorting function
    vector<int> asorted;
    bool doQuickSort = false;

    if (doQuickSort) {
        int * aq;
        aq = a.data();
        quicksort(aq, 0, a.size()-1);
        asorted = a;
    } else {
        asorted = mergeSort(a);
    }

    // Check that our sorting routine has correctly sorted 
    printf("Testing MergeSort on an array with %d elements via %s.\n", arrSize, doQuickSort?"Quicksort":"Mergesort");
    printf("isSorted: %s\n", isSorted(asorted)? "True":"False");
    return 1;
}