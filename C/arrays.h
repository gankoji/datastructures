/* Obviously, C has arrays built in, so there's not much to do here. */
#ifndef ARRAYS
#define ARRAYS

#include <stdlib.h>

int * insert(int * inArray, int element, int size) {
  /*  Create a new array that's one cell bigger, copy over the content of the
      old one. */

  int * newArray = (int *)malloc((size+1)*sizeof(int));
  if (newArray) {
    for (int i=0; i<size; i++) {
      newArray[i] = inArray[i];
    }
    newArray[size] = element;
    return newArray;
  } else {
    /* Allocation failed */
    return NULL;
  }
}

/*  Deletion is straightforward. We could work with resizing, but that seems a
    pain. For now, just remove the element and leave a space. We do have to
    figure out how to keep track of the empty slots, so we can use them rather
    than insert by growing above. */

/*  Searching for a value is O(n). We simply iterate over the array and see if
    the key matches any of the currently stored values. */
int search(int* inArray, int element, int size) {
  for (int i=0; i<size; i++){
    if (inArray[i] == element) return i;
  }
  return -1;
}

#endif
