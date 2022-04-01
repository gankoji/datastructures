#ifndef TRIES
#define TRIES

#include <bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE = 26;

struct TrieNode {
	struct TrieNode *child[ALPHA_SIZE];
	bool endofstring; //It is true if node represents end of word.
};

class Trie {
    public:
        Trie();
        ~Trie();

        void insert(string key);
        void remove(string key);
        bool search(string key);
        bool isEmpty(TrieNode* root);

    private:
        struct TrieNode *createNode(void);
        void insert(struct TrieNode *root, string key);
        bool search(struct TrieNode *root, string key);
        TrieNode* deletion(TrieNode* root, string key, int depth = 0);
};

#endif //TRIES