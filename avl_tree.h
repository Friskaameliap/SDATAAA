#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int id;
    int height;
    AVLNode *left, *right;
    AVLNode(int val) : id(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    int height(AVLNode *n) { return n ? n->height : 0; }
    int getBalance(AVLNode *n) { return n ? height(n->left) - height(n->right) : 0; }

    AVLNode* rightRotate(AVLNode *y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode *x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

public:
    AVLNode* insert(AVLNode* node, int id) {
        if (!node) return new AVLNode(id);
        if (id < node->id) node->left = insert(node->left, id);
        else if (id > node->id) node->right = insert(node->right, id);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && id < node->left->id) return rightRotate(node);
        if (balance < -1 && id > node->right->id) return leftRotate(node);
        if (balance > 1 && id > node->left->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && id < node->right->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inOrder(AVLNode *root) {
        if (root) {
            inOrder(root->left);
            cout << root->id << " ";
            inOrder(root->right);
        }
    }
};

#endif