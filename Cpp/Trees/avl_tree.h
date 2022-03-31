#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
using namespace std;

struct AVLNode {
    int element;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode( const int & theElement, AVLNode *lt, AVLNode *rt, int h = 0)
        : element{theElement}, left{lt}, right{rt}, height{h} {}

    AVLNode( int && theElement, AVLNode *lt, AVLNode *rt, int h=0)
        : element{std::move(theElement)}, left{lt}, right{rt}, height{h} {}
};

class AVLTree {
    public:
        AVLTree();
        ~AVLTree();
        AVLTree( const AVLTree & rhs);

        void makeEmpty();
        void insert(const int & x);
        void insert(int && x);
        void remove(const int & x);
        void printTree(ostream & out = cout) const;

        bool contains(const int & x) const;
        bool isEmpty() const;

        const int & findMin() const;
        const int & findMax() const;


    private:

        AVLNode *root;
        static const int ALLOWED_IMBALANCE = 1;

        void insert(const int & x, AVLNode * & t);
        void insert(int && x, AVLNode * & t);
        void remove (const int & x, AVLNode * & t);
        void makeEmpty(AVLNode * & t);
        void printTree(AVLNode *t, ostream & out) const;
        void balance(AVLNode * & t);
        void rotateWithLeftChild( AVLNode * & k2);
        void rotateWithRightChild( AVLNode * & k2);
        void doubleWithLeftChild(AVLNode * & k3);
        void doubleWithRightChild(AVLNode * & k3);

        bool contains(const int & x, AVLNode *t) const;

        int height(AVLNode * t);
        AVLNode * findMin( AVLNode *t) const;
        AVLNode * findMax(AVLNode *t) const;
        AVLNode * clone(AVLNode *t) const;

};

#endif //AVL_TREE