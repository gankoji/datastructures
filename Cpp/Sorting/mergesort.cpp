#include "mergesort.h"

// Basic mergesort
std::vector<int> mergeSort(std::vector<int> arr) {
    // Check the base case, a 1 element array is vacuously sorted 
    int len = arr.size();
    if (len <= 1) {
        return arr;
    }

    // Split the array in two
    int halflen = len/2;
    std::vector<int> a, b;

    for (int i=0; i<halflen; i++) {
        a.push_back(arr.at(i));
    }

    for (int i=halflen; i<len; i++) {
        b.push_back(arr.at(i));
    }

    // Recurse on halves
    std::vector<int> asorted = mergeSort(a);
    std::vector<int> bsorted = mergeSort(b);

    // Merge sorted halves
    std::vector<int> output;
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