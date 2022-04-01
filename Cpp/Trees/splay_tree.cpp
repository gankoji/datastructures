#include "splay_tree.h"

template <typename Comparable>
SplayTree<Comparable>::SplayTree() {
    nullNode = new SplayNode<Comparable>{0,nullptr,nullptr};
    nullNode->left = nullNode->right = nullNode;
    root = nullNode;
}

template <typename Comparable>
SplayTree<Comparable>::~SplayTree() {
    makeEmpty();
    delete nullNode;
}

template <typename Comparable>
void SplayTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
void SplayTree<Comparable>::makeEmpty(SplayNode<Comparable> * & t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
SplayTree<Comparable>::SplayTree(const SplayTree<Comparable> & rhs) : root{nullptr} {
    root = clone (rhs.root);
}

template <typename Comparable>
SplayNode<Comparable> * SplayTree<Comparable>::clone(SplayNode<Comparable> *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new SplayNode<Comparable>{t->element, clone(t->left), clone(t->right)};
}

template <typename Comparable>
bool SplayTree<Comparable>::isEmpty() const {
    return (root == nullptr);
}

template <typename Comparable>
bool SplayTree<Comparable>::contains(const Comparable& x) {
    if (contains(x, root)) {
        splay(x, root);
        return true;
    } else {
        return false;
    }
    //return contains(x, root);
}

template <typename Comparable>
bool SplayTree<Comparable>::contains(const Comparable& x, SplayNode<Comparable> *t) const {
    if (t == nullptr)
        return false;
    else if(x < t->element)
        return contains(x, t->left);
    else if(x > t->element)
        return contains(x, t->right);
    else
        return true;
}

template <typename Comparable>
int SplayTree<Comparable>::maxHeight() const {
    return height(root);
}

template <typename Comparable>
int SplayTree<Comparable>::height(SplayNode<Comparable> *t) const {
    return (t == nullptr)? -1 : t->height;
}

template <typename Comparable>
void SplayTree<Comparable>::insert(const Comparable& x) {
    static SplayNode<Comparable> *newNode = nullptr;

    if(newNode == nullptr) {
        newNode = new SplayNode<Comparable>{x, nullptr, nullptr};
    }
    newNode->element = x;

    if (root == nullNode) {
        newNode->left = newNode->right = nullNode;
        root = newNode;
    } else {
        splay(x, root);
        if (x < root->element) {
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullNode;
            root = newNode;
        } else if (root->element < x) {
            newNode->right = root->right;
            newNode->left = root;
            root->right = nullNode;
            root = newNode;
        } else {
            return;
        }
    }
    newNode = nullptr;
}

template <typename Comparable>
void SplayTree<Comparable>::remove(const Comparable& x) {
    if (!contains(x)) {
        return;
    }

    SplayNode<Comparable> *newTree;
    if (root->left == nullNode) {
        newTree = root->right;
    } else {
        newTree = root->left;
        splay(x, newTree);
        newTree->right = root->right;
    }
    delete root;
    root = newTree;
}

template <typename Comparable>
void SplayTree<Comparable>::printTree(ostream & out) const {
    out << "Printing Splay tree in-order.\n";
    printTree(root, out);
    out << "\n";
}

template <typename Comparable>
void SplayTree<Comparable>::printTree(SplayNode<Comparable> *t, ostream & out) const {
    if (t == nullptr)
        return;
    else {
        printTree(t->left, out);
        out << " " << t->element << ",";
        printTree(t->right, out);
    }
}

template <typename Comparable>
SplayNode<Comparable> * SplayTree<Comparable>::findMin(SplayNode<Comparable> *t) const {
    if(t==nullptr)
        return nullptr;
    if(t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
const Comparable& SplayTree<Comparable>::findMin() const {
    SplayNode<Comparable> * el = findMin(root);
    if (el != nullptr) {
        return el->element;
    } else {
        return *(new int(-1));
    }
}

template <typename Comparable>
SplayNode<Comparable> * SplayTree<Comparable>::findMax(SplayNode<Comparable> *t) const {
    if(t==nullptr)
        return nullptr;
    if(t->right == nullptr)
        return t;
    return findMax(t->left);
}

template <typename Comparable>
const Comparable& SplayTree<Comparable>::findMax() const {
    SplayNode<Comparable> * el = findMax(root);
    if (el != nullptr) {
        return el->element;
    } else {
        return *(new int(-1));
    }
}

template <typename Comparable>
void SplayTree<Comparable>::rotateWithLeftChild(SplayNode<Comparable> * & k2) {
    SplayNode<Comparable> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename Comparable>
void SplayTree<Comparable>::rotateWithRightChild(SplayNode<Comparable> * & k2) {
    SplayNode<Comparable> *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(k2->height, height(k1->right)) + 1;
    k2 = k1;
}

template <typename Comparable>
void SplayTree<Comparable>::splay(const Comparable & x, SplayNode<Comparable> * & t) {
    SplayNode<Comparable> *leftTreeMax, *rightTreeMin;
    static SplayNode<Comparable> header{0,nullptr,nullptr};

    header.left = header.right = nullNode;
    leftTreeMax = rightTreeMin = &header;

    nullNode->element = x;

    for ( ; ; )
        if (x < t->element) {
            if (x < t->left->element) {
                rotateWithLeftChild(t);
            }
            if (t->left == nullNode) {
                break;
            }
            rightTreeMin->left = t;
            rightTreeMin = t;
            t = t->left;
        } else if (t->element < x) {
            if (t->right->element < x) {
                rotateWithRightChild(t);
            }
            if (t->right == nullNode) {
                break;
            }
            leftTreeMax->right = t;
            leftTreeMax = t;
            t = t->right;
        } else {
            break;
        }

    leftTreeMax->right = t->left;
    rightTreeMin->left = t->right;
    t->left = header.right;
    t->right = header.left;
}