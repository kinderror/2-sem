#include <iostream>

struct Node {
    int key;
    int value;
    Node *left;
    Node *right;
    Node *par;
};

struct SimpleTree {
    Node *root;
    
    // searches node with needed key
    Node *search(int key) { 
        if (root == nullptr or key == root->key) {
            return root;
        } else if (key < root->key) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }
    // searches node with min key in subtree with sub_root = p
    Node *min(Node *p) { 
        while (p->left != nullptr) p = p->left;
        return p;
    }
    // searches node with max key in subtree with sub_root = p
    Node *max(Node *p) {
        while (p->right != nullptr) p = p->right;
        return p;
    }
    // insertion of node p with left = right = nullptr
    void insert (Node *p) { 
        Node *y = nullptr;
        Node *x = root;
        while (x != nullptr) {
            y = x;
            if (p->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        p->par = y;
        if (y == nullptr) {
            root = p;
        } else if (p->key < y->key) {
            y->left = p;
        } else {
            y->right = p;
        }
    }
    // replaces subtrees
    void transplant (Node *root1, Node *root2) { 
        if (root1->par == nullptr) {
            root = root2;
        } else if (root1 == root1->par->left) {
            root1->par->left = root2;
        } else {
            root1->par->right = root2;
        }
        if (root2 != nullptr) root2->par = root1->par;
    }
    // deletes node with pointer p
    void remove (Node *p) { 
        if (p->left == nullptr) {
            transplant(p, p->right);
        } else if (p->right == nullptr) {
            transplant(p, p->left);
        } else {
            Node *y = min(p->right);
            if (y->par != p) {
                transplant(y, y->right);
                y->right = p->right;
                y->right->par = y;
            }
            transplant(p, y);
            y->left = p->left;
            y->left->par = y;
        }
    }
};

int main() {
    return 0;
}
