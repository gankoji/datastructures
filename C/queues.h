/*  Queues are a simple compound structure that builds on the linked list as a
    base. */
#ifndef QUEUES
#define QUEUES

#include "linkedlists.h"

struct node * listHead = NULL;
struct node * listTail = NULL;

void enqueue(struct node * element) {
  if (listHead == NULL) {
    /*  Queue is empty, initialize */
    listHead = element;
    listTail = listHead;
    listHead->next = NULL;
    return;
  }

  insert(listTail, element);
  listTail = listTail->next;
  return;
}

struct node dequeue(void) {
  if(listHead == NULL) {
    /*  We've tried to dequeue from an empty queue, which isn't a valid op. */
    return NULL;
  }

  /*  The queue has at least one element, so pop it. */
  struct node el = *listHead;
  listHead = listHead->next;
  return el;
}
#endif
