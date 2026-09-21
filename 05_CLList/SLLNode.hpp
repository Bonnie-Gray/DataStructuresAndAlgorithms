#ifndef SLLNODE_HPP
#define SLLNODE_HPP

template <typename T>
class SLLNode {
public:
    T data;
    SLLNode* next; //Pointer to the next node

    SLLNode(T d = 0, SLLNode* n = nullptr) {
        data = d;
        next = n;
    }
};


#endif