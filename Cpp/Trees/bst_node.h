#ifndef BST_bst_node
#define BST_bst_node

class bst_node {
    public:
        bst_node() {this->data = 0;};
        bst_node(int data) {this->data = data;};
        bst_node *left, *right;
        int data;

        int maxHeight();
        int maxHeight(bst_node * t);
        void insert(int val);
        bool contains(int val);
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
};

#endif