#include <iostream>
#include <stdlib.h>

#include "hashtable.h"

int main(int argc, char ** argv) {
    HashTable h;
    int numLoops = 1000000;

    for (int i=0; i < numLoops; i++) {
        int x = rand();
        h.insert(x, x);
    }
    printf("Max length after %d loops: %d.\n",numLoops, h.maxLength());
    printf("Total collisions after %d loops: %d.\n", numLoops, h.totalCollisions());
    return 0;
}