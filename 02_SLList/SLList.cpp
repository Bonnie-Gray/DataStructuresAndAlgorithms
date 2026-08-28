#include "SLList.hpp"
#include <iostream>

SLList::SLList() : head(nullptr), list_size(0) {

}


unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const {
    return (size() == 0);
}

void SLList::push_front(int val) {
    SLLNode* new_node = new SLLNode(val);   // adds new node with val
    new_node->next = head;                  // new nodoe points at first in line
    head = new_node;                        // changes head to be the new value


    list_size++;
}

void SLList::push_back(int val) {
    SLLNode* new_node = new SLLNode(val);   // creates new node with value
    SLLNode* rear = head;                   // creates temp node to find end of link list
    while (rear->next) {                    // if there is a node in next
        rear = rear->next;                  // move rear to next node
    }
    rear->next = new_node;                  // once end is found link the new node to end


    list_size++;                            //increment list size
}

void SLList::print() const {
    std::cout << "{ ";

    SLLNode* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << "->";
        }
        cur = cur->next;
        }
    std::cout << " }" << std::endl;
}

