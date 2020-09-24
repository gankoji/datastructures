#include <stdlib.h>
#include <stdio.h>

#include "deques.h"

struct node *el1, *el2, *el3;

int main() {
  el1 = (struct node *)malloc(sizeof(struct node));
  el2 = (struct node *)malloc(sizeof(struct node));
  el3 = (struct node *)malloc(sizeof(struct node));

  el1->key = 1;
  el2->key = 2;
  el3->key = 3;

  enqueueBack(el1);
  enqueueFront(el2);
  enqueueBack(el3);

  struct node elRec = dequeueBack();
  struct node elRecF = dequeueFront();

  if (elRec.key == 3 && elRecF.key == 2) {
    printf("Test passed.\n");
  } else {
    printf("Test failed. Got keys: %d, %d. \n", elRec.key, elRecF.key);
  }
}
