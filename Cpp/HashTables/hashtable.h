#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <list>
#include <utility>

#include <stdlib.h>

using namespace std;

int universalHash( int x, int A, int B, int M );

class HashTable {
    public:
        HashTable();

        void insert(int key, int val);
        int retrieve(int key);
        int maxLength();
        int totalCollisions();

    private:
        const int A = 1250;
        const int B = 3000;
        const int M = (int)1e6; 

        list<pair<int, int>> * table;
};
#endif //HASH_TABLE