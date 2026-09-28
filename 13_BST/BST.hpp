#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"

template <typename T>
class BST{
public:
    BST();

    bool empty() const;

    void insert(const T& val);

    bool contains(const T& val) const;
private:
    BTNode<T>* root;
};

#include "BST.tpp"

#endif