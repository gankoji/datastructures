#include <string>
#include <iostream>
#include "tries.h"

using namespace std;

int main(int argc, char ** argv) {
	string inputs[] = {"HELLOWORLD","HI","BYE", "THE","THENA"}; // Input keys ( only A to Z in upper case)
	int n = sizeof(inputs)/sizeof(inputs[0]);
	struct Trie *root = createNode();
	for (int i = 0; i < n; i++) {
	    insert(root, inputs[i]);
    }

	search(root, "HELLOWORLD")? cout << "Key is Found\n" :
	cout << "Key is not Found\n";
	search(root, "HE")? cout << "Key is Found\n" :
	cout << "Key is not Found\n";
	deletion(root, "THEN")? cout << "Key is deleted\n" :
	cout << "Key is not Deleted\n";

	return 0;
}