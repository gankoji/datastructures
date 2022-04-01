#include "tries.h"

struct Trie *createNode(void) {
	struct Trie *tNode = new Trie;
	tNode->endofstring = false;
	for (int i = 0; i < ALPHA_SIZE; i++)
		tNode->child[i] = NULL;
	return tNode;
}

void insert(struct Trie *root, string key) {
	struct Trie *curr = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'A';
		if (!curr->child[index])
			curr->child[index] = createNode();
			curr = curr->child[index];
	}
	curr->endofstring= true; //last node as leaf
}

bool search(struct Trie *root, string key) { //check if key is present in trie. If present returns true
	struct Trie *curr = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'A';
		if (!curr->child[index])
			return false;
		curr = curr->child[index];
	}
	return (curr != NULL && curr->endofstring);
}
bool isEmpty(Trie* root) {
	for (int i = 0; i < ALPHA_SIZE; i++) {
		if (root->child[i])
			return false;
	}
	return true;
}

Trie* deletion(Trie* root, string key, int depth = 0) {
	//If tree is empty return null.
	if (!root)
	return NULL;
	if (depth == key.size()) { //If last character of key is being processed,
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
	deletion(root->child[index], key, depth + 1); //Then recur for the child which will be obtained by using ASCII value.
	if (isEmpty(root) && root->endofstring == false) { //If root does not have any child leftand it is not end of another word
		delete (root);
		root = NULL;
	}
	return root;
}
