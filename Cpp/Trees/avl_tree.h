#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
using namespace std;

template <typename Comparable>
struct AVLNode {
    Comparable element;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt, int h = 0)
        : element{theElement}, left{lt}, right{rt}, height{h} {}

    AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt, int h=0)
        : element{std::move(theElement)}, left{lt}, right{rt}, height{h} {}
};

template <typename Comparable>
class AVLTree {
    public:
        AVLTree();
        ~AVLTree();
        AVLTree( const AVLTree & rhs);

        void makeEmpty();
        void insert(const Comparable & x);
        void insert(Comparable && x);
        void remove(const Comparable & x);
        void printTree(ostream & out = cout) const;

        bool contains(const Comparable & x) const;
        bool isEmpty() const;

        int maxHeight() const;

        const Comparable & findMin() const;
        const Comparable & findMax() const;


    private:

        AVLNode<Comparable> *root;
        static const int ALLOWED_IMBALANCE = 1;

        void insert(const Comparable & x, AVLNode<Comparable> * & t);
        void insert(Comparable && x, AVLNode<Comparable> * & t);
        void remove (const Comparable & x, AVLNode<Comparable> * & t);
        void makeEmpty(AVLNode<Comparable> * & t);
        void printTree(AVLNode<Comparable> *t, ostream & out) const;
        void balance(AVLNode<Comparable> * & t);
        void rotateWithLeftChild( AVLNode<Comparable> * & k2);
        void rotateWithRightChild( AVLNode<Comparable> * & k2);
        void doubleWithLeftChild(AVLNode<Comparable> * & k3);
        void doubleWithRightChild(AVLNode<Comparable> * & k3);

        bool contains(const Comparable & x, AVLNode<Comparable> *t) const;

        int height(AVLNode<Comparable> * t) const;
        AVLNode<Comparable> * findMin( AVLNode<Comparable> *t) const;
        AVLNode<Comparable> * findMax(AVLNode<Comparable> *t) const;
        AVLNode<Comparable> * clone(AVLNode<Comparable> *t) const;

};

/* A quick hack here.
 * C++ needs method implementations to instantiate a template. 
 * This means, effectively, that you can't have a templatized class
 * separated between header and cpp file. You can, but all of the 
 * templatized methods have to be in the header. In this case, all 
 * of the methods of AVLTree are templatized, so the whole class
 * implementation needs to be in the same place as the header to be 
 * properly instantiated. Rather than have this file be a hot mess, 
 * I've used the preprocessor here to smash the two files together
 * at compile time. 
 */

#include "avl_tree.cpp"
#endif //AVL_TREE