#include <iostream>

struct Node {
    int key;
    int height;
    int value;
    Node *left;
    Node *right;
};

struct AVL_Tree {
    Node *root;
    
    // returnes height of node with pointer p
    int height (Node *p) {
        return p ? p->height : 0;
    }
    // returnes b_factor of node with pointer p
    int bfactor (Node *p) {
        int bfactor = 0;
        if (p != nullptr) bfactor = height(p->right) - height(p->left);
        return bfactor;
    }
    // replaces height with new value
    void fix_height(Node *p) {
        int hl = height(p->left);
        int hr = height(p->right);
        p->height = std::max(hl, hr) + 1;
    }
    // rotates sub_tree to the right 
    Node *rotateright(Node *p) {
        Node *q = p->left;
        p->left = q->right;
        q->right = p;
        fix_height(p);
        fix_height(q);
        return q;
    }
    // rotates sub_tree to the left
    Node *rotateleft(Node *p) {
        Node *q = p->right;
        p->right = q->left;
        q->left = p;
        fix_height(p);
        fix_height(q);
        return q;
    } 
    // balances tree
    Node *balance(Node *p) {
        fix_height(p);
        if (bfactor(p) == 2) {
            if (bfactor(p->right) < 0) p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if (bfactor(p) == -2) {
            if (bfactor(p->left) > 0) p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }
    // helpful func for insertion 
    Node *rec_insert(Node *par, Node *p) { 
        if (par == nullptr) return p;
        if (p->key < par->key) {
            par->left = rec_insert(par->left, p);
        } else {
            par->right = rec_insert(par->right, p);
        return balance(par);
    }
    // inserts node with pointer p
    void insert(Node *p) { 
        root = rec_insert(root, p);
    }
    // finds node with needed key
    Node *search(Node *p, int key) { 
        if (p == nullptr or key == p->key) return p;
        if (key < p->key) return search(p->left, key);
        else return search(p->right, key);
    }
    // finds node with min key in subtree
    Node *fmin(Node *p) { 
        while (p->left != nullptr) p = p->left;
        return p;
    }
    // finds node with max key in subtree 
    Node *fmax(Node *p) {
        while (p->right != nullptr) p = p->right;
        return p;
    }
    // helpful func for removing
    Node *removemin(Node *p) {
        if (p->left == nullptr) return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }
    // helpful func for removing
    Node *rec_remove(Node *par, Node *p) { 
        if (par == nullptr) return nullptr;
        if (p->key < par->key) 
            par->left = rec_remove(par->left, p);
        } else if (p->key > par->key) {
            par->right = rec_remove(par->right, p);
        } else {
            Node *pl = par->left;
            Node *pr = par->right;
            if (pr == nullptr) return pl;
            Node *min = fmin(pr);
            min->right = removemin(pr);
            min->left = pl;
            return balance(min);
        }
        return balance(par);
    }
    // removes node with pointer p
    void remove(Node *p) { 
        root = rec_remove(root, p);
    }
};

int main() {
    return 0;
}
