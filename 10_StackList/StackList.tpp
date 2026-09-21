#include "StackList.hpp"
#include <stdexcept>
#include <iostream>


template <typename T>
StackList<T>::StackList() {
    top_node = nullptr;
}


template <typename T>
StackList<T>::~StackList() {
    while (!empty()){
        pop();
    }
}

template <typename T>
void        StackList<T>::push(const T& val) {
    if (empty()) {
        throw std::out_of_range("pop: Empty Stack")
    } else {
        new_top = new Node(val, top_idx);
        top_idx++;
    }
}


template <typename T>
bool        StackList<T>::empty() const {
    return top_idx == nullptr;
}

template <typename T>
void        StackList<T>::print() const {
    for (i = top_idx; i >= 0; i--) {
        std::cout << data[i];
    }
}

template <typename T>
T           StackList<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pop: Empty Stack");
    } else {
        Node*<U> old_top = top_idx;
        T to_return = top_idx->data;
        top_idx = top_idx->next;
        delete old_top;
        return to_return;
    }
}

template <typename T>
const T&    StackList<T>::top() const {
    if (empty()) {
        throw std::out_of_range("top: Empty Stack");
    } else {
        return data[top_idx];
    }
}
    