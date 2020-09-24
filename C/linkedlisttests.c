#include <stdio.h>
#include "linkedlists.h"

int main() {
  struct node * list;
  struct node * element;

  element = (struct node *)malloc(sizeof(struct node));

  element->key = 5;
  element->value = 10;
  insert(list, element);
  struct node * found;
  found = search(list, 5);

  if (found) {
    printf("Search successful.\n");
  } else {
    printf("Search failed.\n");
  }
  delete(list, element);

}
