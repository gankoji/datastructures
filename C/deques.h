#ifndef DEQUES
#define DEQUES

#include <stdlib.h>

/*  Deques, or 'double ended queues', are just that: queues/FIFOs from which we
    can add and remove items from both 'ends', as opposed to a queue, where we
    push to the back and pop from the front. */

#include "linkedlists.h"

struct node * listHead = NULL;
struct node * listTail = NULL;

void initialize(struct node * element) {
  listHead = element;
  listTail = listHead;
  listHead->next = NULL;
  listTail->next = NULL;
}

/*  O(1) */
void enqueueBack(struct node * element) {
  if (listHead == NULL) {
    /*  Queue is empty, initialize */
    initialize(element);
    return;
  }

  insert(listTail, element);
  listTail = listTail->next;
  return;
}

/* O(1) */
void enqueueFront(struct node * element) {
  if (listHead == NULL) {
    initialize(element);
  }

  element->next = listHead;
  listHead = element;
  return;
}

/*  O(1) */
struct node dequeueFront(void) {
  if(listHead == NULL) {
    /*  We've tried to dequeue from an empty queue, which isn't a valid op. */
    struct node emptyEl;
    return emptyEl;
  }

  /*  The queue has at least one element, so pop it. */
  struct node el = *listHead;
  listHead = listHead->next;
  return el;
}

/*  This method is O(n), unlike the rest. Trying to come up with a way to
    maintain a pointer to the penultimate element without using a doubly linked
    list as the underlying structure, but I don't think it's possible. */
struct node dequeueBack(void) {
  if(listHead == NULL) {
    /*  We've tried to dequeue from an empty queue, which isn't a valid op. */
    struct node emptyEl;
    return emptyEl;
  }

  struct node *current = listHead;
  while (current->next != listTail) {
    /*  Iterate through queue to find penultimate element. */
    current = current->next;
  }
  /*  Now we have the penultimate element in hand. */
  struct node el = *listTail;
  current->next = NULL;
  return el;
}

#endif
