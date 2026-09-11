#include "DLList.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
bool DLList<T>::empty() const {
    return (list_size == 0);
}

template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>;  // Sentinel Node
    tail = new DLLNode<T>;  // Sentinel Node
    //connecting head and tail
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;

    list_size++;
}

template<typename T>
void DLList<T>::push_back(const T& val) {
    tail->prev = new DLLNode<T>(val, tail->prev, tail);                                       
    tail->prev->prev->next = tail->prev;

    list_size++;
}

template<typename T>
void DLList<T>::pop_front() {
    if (!empty()) {
        DLLNode<T>* old_head = head;
        head->next->next->prev = head;
        head = head->next;
        
        delete old_head;
        

        list_size--;
        if (empty()) { // if the last node was deleted
            tail->prev = head;
            head->next = tail;
        }
    }

}

template <typename T>
void DLList<T>::print() const {
    DLLNode<T>* cur = head->next;
    while(cur != tail){
        std::cout << cur->data;
        cur = cur->next;
    }
    std::cout << std::endl;
}