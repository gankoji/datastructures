#include "arrays.h"
#include <stdio.h>

int testArray[10];

int main() {
  for (int i=0; i<10; i++){
    testArray[i] = i;
  }
  int * newArray;
  newArray = insert(testArray, 11, 10);

  if (newArray && (newArray[10] == 11)) {
    printf("Insert successful.\n");
    int ind = search(newArray, 4, 11);
    if (newArray[ind] == 4) {
      printf("Search successful.\n Tests passed.");
    } else {
      printf("Search unsuccessful.\n");
    }
  } else {
    printf("Insert unsuccessful, OOM.\n");
  }
}
