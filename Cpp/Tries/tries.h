#ifndef TRIES
#define TRIES

#include <bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE = 26;

struct TrieNode {
	struct TrieNode *child[ALPHA_SIZE];
	bool endofstring; //It is true if node represents end of word.
    // Object myRecord;
    // This is where you'd store records associated with 'word' for retrieval. 
};

class Trie {
    public:
        Trie();
        ~Trie();

        void insert(string key);
        bool search(string key);
        bool isEmpty(TrieNode* root);

        TrieNode* remove(string key);

    private:
        TrieNode *root;
        struct TrieNode *createNode(void);
        void makeEmpty(TrieNode *t);
        void insert(struct TrieNode *root, string key);
        bool search(struct TrieNode *root, string key);
        TrieNode* remove(TrieNode* root, string key, int depth = 0);
};

#endif //TRIES