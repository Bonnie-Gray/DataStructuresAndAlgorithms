#include "BST.hpp"

template <typename = T>
BST::BST() : root = nullptr {

}

template <typename = T>
bool BST::empty() const {
    return root == nullptr;
}

template <typename = T>
void BST::insert(const T& val) {
    if(empty()) {
        root = new BTNode<T>(val);
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = root;

    // Iterate through BST
    while(cur) {
        parent = cur;

        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (val < parent->data && parent->left == nullptr) {
        parent->left = new BTNode<T>(val);
    }
    else (val > parent->data && parent->right == nullptr) {
        parent->right = new BTNode<T>(val);
    }
}

template <typename T>
void BST::contains(const T& val) {
    if (root->data == val) {
        return true;
    }
    else if ()
}