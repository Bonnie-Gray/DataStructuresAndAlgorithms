#include "DLList.hpp"
#include <iosteam>
#include <stdexcept>

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

template <typename T>
DLList<T>::print() {
    
}