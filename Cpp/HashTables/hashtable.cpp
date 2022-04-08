#include "hashtable.h"

const int DIGS = 15;
const int mersennep = (1<<DIGS) - 1;

int universalHash( int x, int A, int B, int M ) {
    long long hashVal = static_cast<long long>( A ) * x + B;

    hashVal = ( ( hashVal >> DIGS ) + ( hashVal & mersennep ) );
    if( hashVal >= mersennep )
        hashVal -= mersennep;

    return (static_cast<int>( hashVal ) % M + M)%M;
}

HashTable::HashTable() {
    table = new list<pair<int,int>>[M] ();
    
    if (table == nullptr) {
        printf("ERROR: Could not allocate table.\n");
        return;
    }
}

void HashTable::insert(int key, int val) {
    int hash = universalHash(key, A, B, M);
    pair<int,int> p = std::make_pair(key, val);
    table[hash].push_front(p);
}

int HashTable::retrieve(int key) {
    int hash = universalHash(key, A, B, M);
    pair<int,int> foundRecord;

    for (auto it = table[hash].begin(); it != table[hash].end(); it++) {
        if (get<0>(*it) == key) {
            return get<1>(*it);
        }
    }

    return -1;
}

int HashTable::maxLength() {
    size_t maxLen = 0;

    for (int i=0; i<M; i++) {
        maxLen = max(table[i].size(), maxLen);
    }

    return static_cast<int>(maxLen);
}

int HashTable::totalCollisions() {
    size_t collisions = 0;

    for (int i=0; i<M; i++) {
        if (table[i].size() > 1) {
            collisions += table[i].size()-1;
        }
    }

    return static_cast<int>(collisions);
}