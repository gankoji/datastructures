#ifndef DOUBLELISTS
#define DOUBLELISTS

#include <stdlib.h>

struct  dlnode {
  int key;
  int value;
  struct dlnode * next;
  struct dlnode * prev;
};

/*  Simple enough. We'll have a few methods for dealing with them: Insert,
    Delete, Search. */

/*  To insert an element in a list, we simply add it to the back. This can be
    sped up significantly for long lists by using the version where we feed in a
    pointer to the tail element, but that requires just a touch of extra space
    (4 bytes on modern x86 machine).*/
void insert(struct dlnode * listHead, struct dlnode * element) {
  if (listHead == NULL) {
    /*  Empty list, initialize it with this element. */
    listHead  = element;
    listHead->next = NULL;
    listHead->prev = NULL;
    return;
  }
  while (listHead->next != NULL) {
    listHead = listHead->next;
  }
  /*We are now at the end of the list.*/
  listHead->next = element;
  listHead->next->prev = listHead;
  return;
}

void delete(struct dlnode * listHead, struct dlnode * element) {
  while (listHead != element) {
    listHead = listHead->next;
    if (listHead == NULL) {
      /*  We have reached the end of the list without finding the element to
  delete. This is an error condition. Fail quietly for now until a suitable
  exception strategy is developed. */
      return;
    }
  }
  /*  If we've made it here, we've found the struct dlnode to delete. */
  listHead->prev->next = listHead->next;
  listHead->next->prev = listHead->prev;
  free(listHead);
  return;
}

struct dlnode * search(struct dlnode * listHead, int key) {
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
