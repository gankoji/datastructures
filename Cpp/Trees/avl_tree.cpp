//#include "avl_tree.h"

template <typename Comparable>
AVLTree<Comparable>::AVLTree() {
    root = nullptr;
}

template <typename Comparable>
AVLTree<Comparable>::~AVLTree() {
    makeEmpty();
}

template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode<Comparable> * & t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree<Comparable> & rhs) : root{nullptr} {
    root = clone (rhs.root);
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::clone(AVLNode<Comparable> *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new AVLNode<Comparable>{t->element, clone(t->left), clone(t->right)};
}

template <typename Comparable>
bool AVLTree<Comparable>::isEmpty() const {
    return (root == nullptr);
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable& x) const {
    return contains(x, root);
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable& x, AVLNode<Comparable> *t) const {
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
int AVLTree<Comparable>::maxHeight() const {
    return height(root);
}

template <typename Comparable>
int AVLTree<Comparable>::height(AVLNode<Comparable> *t) const {
    return (t == nullptr)? -1 : t->height;
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable& x) {
    insert(x, root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(Comparable&& x) {
    insert(std::move(x), root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable& x, AVLNode<Comparable> * & t) {
    if (t == nullptr)
        t = new AVLNode<Comparable>{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);

    balance(t);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(Comparable&& x, AVLNode<Comparable> * & t) {
    if (t == nullptr)
        t = new AVLNode<Comparable>{ std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);

    balance(t);
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable& x) {
    remove(x, root);
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable& x, AVLNode<Comparable> * & t) {
    if (t == nullptr)
        return;
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else {
        AVLNode<Comparable> *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }

    balance(t);
}

template <typename Comparable>
void AVLTree<Comparable>::printTree(ostream & out) const {
    out << "Printing AVL tree in-order.\n";
    printTree(root, out);
    out << "\n";
}

template <typename Comparable>
void AVLTree<Comparable>::printTree(AVLNode<Comparable> *t, ostream & out) const {
    if (t == nullptr)
        return;
    else {
        printTree(t->left, out);
        out << " " << t->element << ",";
        printTree(t->right, out);
    }
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::findMin(AVLNode<Comparable> *t) const {
    if(t==nullptr)
        return nullptr;
    if(t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
const Comparable& AVLTree<Comparable>::findMin() const {
    AVLNode<Comparable> * el = findMin(root);
    if (el != nullptr) {
        return el->element;
    } else {
        return *(new int(-1));
    }
}

template <typename Comparable>
AVLNode<Comparable> * AVLTree<Comparable>::findMax(AVLNode<Comparable> *t) const {
    if(t==nullptr)
        return nullptr;
    if(t->right == nullptr)
        return t;
    return findMax(t->left);
}

template <typename Comparable>
const Comparable& AVLTree<Comparable>::findMax() const {
    AVLNode<Comparable> * el = findMax(root);
    if (el != nullptr) {
        return el->element;
    } else {
        return *(new int(-1));
    }
}

template <typename Comparable>
void AVLTree<Comparable>::balance(AVLNode<Comparable> * & t) {
    if (t == nullptr)
        return;

    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
        if (height(t->right->right) >= height(t->right->left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }

    t->height = max( height(t->left), height(t->right)) + 1;
}

template <typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode<Comparable> * & k2) {
    AVLNode<Comparable> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode<Comparable> * & k2) {
    AVLNode<Comparable> *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(k2->height, height(k1->right)) + 1;
    k2 = k1;
}

template <typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode<Comparable> * & k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode<Comparable> * & k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}