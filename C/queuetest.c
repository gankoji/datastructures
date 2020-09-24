
#include "queues.h"
#include <stdio.h>
#include <stdlib.h>

struct node * element1, *element2, *element3;
int main() {
  element1 = (struct node *)malloc(sizeof(struct node));
  element2 = (struct node *)malloc(sizeof(struct node));
  element3 = (struct node *)malloc(sizeof(struct node));

  element1->key = 1;
  element2->key = 2;
  element3->key = 3;

  enqueue(element1);
  enqueue(element2);
  enqueue(element3);


  struct node elRet;
  elRet = dequeue();
  if(elRet.key == 1) {
    printf("Test passed.\n");
  } else {
    printf("Test failed. Got key %d\n", elRet.key);
  }
}
