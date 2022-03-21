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

// Basic mergesort
int * mergeSort(int * arr, int len) {
    // Check the base case, a 1 element array is vacuously sorted 
    if (len <= 1) {
        return arr;
    }

    // Split the array in two
    int halflen = len/2;
    int *a, *b;
    a = (int *)malloc(sizeof(int)*halflen);
    b = (int *)malloc(sizeof(int)*(len-halflen));
    if ((a == NULL) || (b == NULL)) {
        printf("ERROR: couldn't malloc.\n");
        return NULL;
    }

    for (int i=0; i<halflen; i++) {
        a[i] = arr[i];
    }

    for (int i=halflen; i<len; i++) {
        b[i-halflen] = arr[i];
    }


    // Recurse on halves
    int * asorted = mergeSort(a, halflen);
    int * bsorted = mergeSort(b, (len-halflen));

    // Merge sorted halves
    int * output = (int *)malloc(sizeof(int)*len);
    if (output == NULL) {
        printf("ERROR: couldn't malloc output.\n");
        return NULL;
    }
    int i=0, j=0, k=0;
    while (k < len) {
        if ((i < (halflen)) && (j < (len - halflen))) {
            if (asorted[i] <= bsorted[j]) {
                output[k] = asorted[i];
                i++; k++;
            } else {
                output[k] = bsorted[j];
                j++; k++;
            }
        } else if (i < (halflen)) {
            output[k] = asorted[i];
            i++; k++;
        } else {
            output[k] = bsorted[j];
            j++; k++;
        }
    }

    free(asorted);
    free(bsorted);
    return output;
}
int main(int argc, char ** argv) {

    // First, build some test data
    int arrSize = (int)1e8;
    int * a = (int *)malloc(sizeof(int)*arrSize);

    for (int i=0; i<arrSize; i++) {
        a[i] = rand()%20000;
    }

    // Call sorting function
    int * asorted;
    asorted = mergeSort(a,arrSize);

    // Check that our sorting routine has correctly sorted 
    printf("Testing MergeSort on an array with %d elements.\n", arrSize);
    printf("isSorted: %s\n", isSorted(asorted,arrSize)? "True":"False");
    return 1;
}