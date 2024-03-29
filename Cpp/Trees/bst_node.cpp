#include "bst_node.h"
#include <iostream>

int bst_node::maxHeight() {
    return maxHeight(this);
}

int bst_node::maxHeight(bst_node * t) {
    if (t == nullptr) {
        return -1;
    }

    int lt = maxHeight(t->left);
    int rt = maxHeight(t->right);
    return std::max( lt, rt ) + 1;
}
void bst_node::insert(int value) {
    if (value <= data) {
        if (left == nullptr) {
            left = new bst_node(value);
        } else {
            left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = new bst_node(value);
        } else {
            right->insert(value);
        }
    }
}

bool bst_node::contains(int value) {
    if (value == data) {
        return true;
    } else if (value < data) {
        if (left == nullptr) {
            return false;
        } else {
            return left->contains(value);
        }
    } else {
        if (right == nullptr) {
            return false;
        } else {
            return right->contains(value);
        }
    }
}

void bst_node::printInOrder() {
    if (left != nullptr) {
        left->printInOrder();
    }

    printf("%d, ", data);

    if (right != nullptr) {
        right->printInOrder();
    }
}

void bst_node::printPreOrder() {
    printf("%d, ", data);

    if (left != nullptr) {
        left->printInOrder();
    }

    if (right != nullptr) {
        right->printInOrder();
    }
}

void bst_node::printPostOrder() {
    if (left != nullptr) {
        left->printInOrder();
    }

    if (right != nullptr) {
        right->printInOrder();
    }

    printf("%d, ", data);
}