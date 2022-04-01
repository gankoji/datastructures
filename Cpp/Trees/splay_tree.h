#ifndef SPLAY_TREE
#define SPLAY_TREE

#include <iostream>
using namespace std;

template <typename Comparable>
struct SplayNode {
    Comparable element;
    SplayNode *left;
    SplayNode *right;
    int height;

    SplayNode( const Comparable & theElement, SplayNode *lt, SplayNode *rt, int h=0)
        : element{theElement}, left{lt}, right{rt}, height{h} {}

    SplayNode( Comparable && theElement, SplayNode *lt, SplayNode *rt, int h=0)
        : element{std::move(theElement)}, left{lt}, right{rt}, height{h} {}
};

template <typename Comparable>
class SplayTree {
    public:
        SplayTree();
        ~SplayTree();
        SplayTree( const SplayTree & rhs);

        void makeEmpty();
        void insert(const Comparable & x);
        void remove(const Comparable & x);
        void printTree(ostream & out = cout) const;

        bool contains(const Comparable & x);
        bool isEmpty() const;

        int maxHeight() const;

        const Comparable & findMin() const;
        const Comparable & findMax() const;

    private:

        SplayNode<Comparable> *root;
        SplayNode<Comparable> *nullNode;
        static const int ALLOWED_IMBALANCE = 1;

        //void insert(const Comparable & x, SplayNode<Comparable> * & t);
        //void insert(Comparable && x, SplayNode<Comparable> * & t);
        //void remove (const Comparable & x, SplayNode<Comparable> * & t);
        void makeEmpty(SplayNode<Comparable> * & t);
        void printTree(SplayNode<Comparable> *t, ostream & out) const;
        void balance(SplayNode<Comparable> * & t);
        void rotateWithLeftChild( SplayNode<Comparable> * & k2);
        void rotateWithRightChild( SplayNode<Comparable> * & k2);
        void splay(const Comparable & x, SplayNode<Comparable> * & t);

        bool contains(const Comparable & x, SplayNode<Comparable> *t) const;

        int height(SplayNode<Comparable> * t) const;

        SplayNode<Comparable> * findMin( SplayNode<Comparable> *t) const;
        SplayNode<Comparable> * findMax(SplayNode<Comparable> *t) const;
        SplayNode<Comparable> * clone(SplayNode<Comparable> *t) const;

};

/* A quick hack here.
 * C++ needs method implementations to instantiate a template. 
 * This means, effectively, that you can't have a templatized class
 * separated between header and cpp file. You can, but all of the 
 * templatized methods have to be in the header. In this case, all 
 * of the methods of SplayTree are templatized, so the whole class
 * implementation needs to be in the same place as the header to be 
 * properly instantiated. Rather than have this file be a hot mess, 
 * I've used the preprocessor here to smash the two files together
 * at compile time. 
 */

#include "splay_tree.cpp"
#endif //SPLAY_TREE