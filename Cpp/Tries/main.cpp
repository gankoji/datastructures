#include <string>
#include <iostream>
#include "tries.h"

using namespace std;

#define NUM_TESTS 3

int main(int argc, char ** argv) {
	string inputs[] = {"HELLOWORLD","HI","BYE", "THE","THENA"}; // Input keys ( only A to Z in upper case)
	int n = sizeof(inputs)/sizeof(inputs[0]);

	bool tests[NUM_TESTS];

	Trie *trie = new Trie();
	for (int i = 0; i < n; i++) {
	    trie->insert(inputs[i]);
    }

	tests[0] = trie->search("HELLOWORLD");
	tests[0]? cout << "Key is Found\n" : cout << "Key is not Found\n";
	tests[1] = !(trie->search("HE"));
	tests[1]? cout << "Key is Found\n" : cout << "Key is not Found\n";
	tests[2] = (trie->remove("THEN") != nullptr);
	tests[2]? cout << "Key is deleted\n" : cout << "Key is not Deleted\n";

    // Accumulate and print test results
    printf("\n\nTest results\n");
    int sum = std::accumulate(tests, tests+NUM_TESTS, 0);
    if (sum == NUM_TESTS) {
        std::cout << "All tests passed.\n";
    } else {
        for (int i=0; i<NUM_TESTS; i++) {
            std::cout << "Test " << i << ": " << (tests[i]? "Passed.\n":"Failed.\n");
        }
    }

	return 0;
}