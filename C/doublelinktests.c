#include <stdio.h>
#include "doublylinkedlists.h"

int main() {
  struct dlnode * list;
  struct dlnode * element;

  element = (struct dlnode *)malloc(sizeof(struct dlnode));

  element->key = 5;
  element->value = 10;
  insert(list, element);
  struct dlnode * found;
  found = search(list, 5);

  if (found) {
    printf("Search successful.\n");
  } else {
    printf("Search failed.\n");
  }
  delete(list, element);

}
