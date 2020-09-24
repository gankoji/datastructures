/*  Moving on to singly linked lists. Create a datatype for our nodes that has
    the requisite structure. */
#ifndef SINGLELISTS
#define SINGLELISTS

#include <stdlib.h>

struct  node {
  int key;
  int value;
  struct node * next;
};

/*  Simple enough. We'll have a few methods for dealing with them: Insert,
    Delete, Search. */

/*  To insert an element in a list, we simply add it to the back. This can be
    sped up significantly for long lists by using the version where we feed in a
    pointer to the tail element, but that requires just a touch of extra space
    (4 bytes on modern x86 machine).*/
void insert(struct node * listHead, struct node * element) {
  if (listHead == NULL) {
    /*  Empty list, initialize it with this element. */
    listHead  = element;
    return;
  }

  while (listHead->next != NULL) {
    listHead = listHead->next;
  }
  /*We are now at the end of the list.*/
  listHead->next = element;
  listHead->next->next = NULL;

  return;
}

void delete(struct node * listHead, struct node * element) {
  struct node * prev = listHead;
  while (listHead != element) {
    prev = listHead;
    listHead = listHead->next;
    if (listHead == NULL) {
      /*  We have reached the end of the list without finding the element to
  delete. This is an error condition. Fail quietly for now until a suitable
  exception strategy is developed. */
      return;
    }
  }
  /*  If we've made it here, we've found the struct node to delete. */
  prev->next = listHead->next;
  free(listHead);
  return;
}

struct node * search(struct node * listHead, int key) {
  while(listHead->key != key) {
    listHead = listHead->next;
    if (listHead == NULL) {
      /*  Search was unsuccessful. */
      return NULL;
    }
  }
  return listHead;
}

#endif
