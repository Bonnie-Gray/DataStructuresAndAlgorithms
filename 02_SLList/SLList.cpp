#include "SLList.hpp"
#include <iostream>
#include <stdexcept>

SLList::SLList() : head(nullptr), tail(nullptr), list_size(0) {

}
SLList::~SLList() {
    clear();
}

SLList::SLList(const SLList& other) : head(nullptr), tail(nullptr), list_size(0) {
    SLLNode* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }
}

SLList& SLList::operator=(const SLList& other) {
    clear();
    
    SLLNode* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }

    return *this;
}

unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const {
    return (size() == 0);
}

void SLList::push_front(int val) {
    //SLLNode* new_node = new SLLNode(val);   // adds new node with val
    //new_node->next = head;                  // new nodoe points at first in line
    //head = new_node;                        // changes head to be the new value

    //There is an alternative way
    head = new SLLNode(val, head);

    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

void SLList::push_back(int val) {
    //SLLNode* new_node = new SLLNode(val);   // creates new node with value
    //SLLNode* tail = head;                   // creates temp node to find end of link list
    // if (empty()) {
    //    push_front(val);
    //    return;
    //}                  
    //while (tail->next) {                    // if there is a node in next
    //    tail = tail->next;                  // move rear to next node
    //}
    //tail->next = new_node;                  // once end is found link the new node to end

    if (empty()) {
        push_front(val);
        return;
    }
    tail->next = new SLLNode(val);          //Add the new node at the end
    tail = tail->next;                      //Update the tail


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

void SLList::pop_front(void) {
    if (!empty()) {
        SLLNode* old_head = head;
        head = head->next;

        delete old_head;

        list_size--;
        if (empty()) { // if the last node was deleted
            tail = head;
        }
    }
}

void SLList::pop_back(void) {
    if(!empty()) {
        if(size() == 1) {
            pop_front();
            return;
        }
    }
    
    if(!empty()) {
        SLLNode* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        
    }
    list_size--;

    if (empty()) {
        tail = head;
    }
    
}

void SLList::clear(void){
    while (!empty()) {
        pop_front();
    }
}

int& SLList::at(unsigned index) {
    if (index >= size()) {
        throw std::logic_error("at incorrect index");
    }

    SLLNode* cur = head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
    }

    return cur->data;
}