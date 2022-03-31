#include "bst_node.h"
#include "avl_tree.h"
#include <numeric>
#include <iostream>

#define NUM_TESTS 12
int main(int argc, char ** argv) {
    int arr[5] = { 1, 2, 3, 8, 4};
    bool tests[NUM_TESTS];

    // Test bst creation
    printf("\nTesting basic BST\n");
    bst_node * testtree = new bst_node(5);
    tests[0] = testtree->contains(5);

    // Test insertion
    for (int i=0; i<5; i++) {
        testtree->insert(arr[i]);
        tests[i+1] = testtree->contains(arr[i]);
    }

    printf("In order: ");
    testtree->printInOrder();
    printf("\nPre order: ");
    testtree->printPreOrder();
    printf("\nPost order: ");
    testtree->printPostOrder();
    printf("\n");

    delete testtree;

    // Test AVL Tree
    printf("\nNow testing AVL trees.\n");
    AVLTree * avl = new AVLTree();
    avl->insert(5);
    tests[6] = avl->contains(5);

    //avl->printTree();

    // Test insertion
    for (int i=0; i<5; i++) {
        avl->insert(arr[i]);
        tests[i+7] = avl->contains(arr[i]);
    }

    //avl->printTree();

    // Accumulate and print test results
    printf("Test results\n");
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