#include "bst_node.h"
#include "avl_tree.h"
#include <numeric>
#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std::chrono;

#define NUM_TESTS 12

void doPerfTest() {
    // For fun now, let's really crank it. 
    bst_node * testtree1 = new bst_node();
    AVLTree * avl1 = new AVLTree();

    const int loops = (int)1e6;
    int theIndex = rand()%loops;
    int theInt = 0;
    for (int i=0; i<loops; i++) {
        int randI = rand();
        if (i==theIndex) theInt = randI;
        testtree1->insert(randI);
        avl1->insert(randI);
    }

    printf("\nPerformance Testing. \n");
    printf("Height difference. BST: %d, AVL: %d.\n", testtree1->maxHeight(), avl1->maxHeight());
    auto start = high_resolution_clock::now();
    for (int i=0; i<loops; i++) {
        testtree1->contains(theInt);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("Time for search. BST: %ld us,", duration.count());

    start = high_resolution_clock::now();
    for (int i=0; i<loops; i++) {
        avl1->contains(theInt);
    }
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);
    printf("AVL: %ld us\n", duration2.count());
    long delta = (duration.count() - duration2.count());
    float pDelta = (float)delta/(float)duration.count()*100.;
    printf("Time difference: %ld us, %5.3f%%.\n", delta, pDelta);
}

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

    printf("Maximum height of basic BST: %d\n", testtree->maxHeight());
    delete testtree;

    // Test AVL Tree
    printf("\nNow testing AVL trees.\n");
    AVLTree * avl = new AVLTree();
    avl->insert(5);
    tests[6] = avl->contains(5);

    avl->printTree();

    // Test insertion
    for (int i=0; i<5; i++) {
        avl->insert(arr[i]);
        tests[i+7] = avl->contains(arr[i]);
    }

    printf("Tree after insertion tests. \n");
    avl->printTree();
    printf("Maximum height of AVL tree: %d\n", avl->maxHeight());

    delete avl;

    // Crank up the heat to show differences
    doPerfTest();

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