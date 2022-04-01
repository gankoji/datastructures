#include "tries.h"

Trie::Trie() {
	root = createNode();
}

Trie::~Trie() {
	makeEmpty(root);
}

void Trie::makeEmpty(TrieNode * t) {
    if (t != nullptr) {
		for (int i=0; i<ALPHA_SIZE; i++) {
			makeEmpty(t->child[i]);
		}
        delete t;
    }
    t = nullptr;
}

struct TrieNode * Trie::createNode(void) {
	struct TrieNode *tNode = new TrieNode;
	tNode->endofstring = false;
	for (int i = 0; i < ALPHA_SIZE; i++)
		tNode->child[i] = NULL;
	return tNode;
}

bool Trie::isEmpty(TrieNode* root) {
	for (int i = 0; i < ALPHA_SIZE; i++) {
		if (root->child[i])
			return false;
	}
	return true;
}

void Trie::insert(string key) {
	insert(root, key);
}

void Trie::insert(struct TrieNode *root, string key) {
	struct TrieNode *curr = root;
	for (int i = 0; i < (int)key.length(); i++) {
		int index = key[i] - 'A';
		if (!curr->child[index])
			curr->child[index] = createNode();
		curr = curr->child[index];
	}
	curr->endofstring= true; //last node as leaf
}

bool Trie::search(string key) {
	return search(root, key);
}

bool Trie::search(struct TrieNode *root, string key) { //check if key is present in trie. If present returns true
	struct TrieNode *curr = root;
	for (int i = 0; i < (int)key.length(); i++) {
		int index = key[i] - 'A';
		if (!curr->child[index])
			return false;
		curr = curr->child[index];
	}
	return (curr != NULL && curr->endofstring);
}

TrieNode* Trie::remove(string key) {
	return remove(root, key);
}

TrieNode* Trie::remove(TrieNode* root, string key, int depth) {
	//If tree is empty return null.
	if (!root)
		return NULL;
	if (depth == (int)key.size()) { //If last character of key is being processed,
		if (root->endofstring)
			root->endofstring = false; //then that node will be no more end of string after deleting it.
		if (isEmpty(root)) { //If given key is not prefix of any other string,
			delete (root);
			root = NULL;
		}
		return root;
	}

	//If key not last character,
	int index = key[depth] - 'A';
	root->child[index] =
	remove(root->child[index], key, depth + 1); //Then recur for the child which will be obtained by using ASCII value.
	if (isEmpty(root) && root->endofstring == false) { //If root does not have any child leftand it is not end of another word
		delete (root);
		root = NULL;
	}
	return root;
}
