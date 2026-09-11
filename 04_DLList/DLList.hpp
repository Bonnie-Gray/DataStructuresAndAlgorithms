#ifndef DLLIST_HPP
#define DLLIST_HPP

#include "DLLNode.hpp"

template <typename T>
class DLList {
public:
    // No-arg constructor
    DLList();
    //~DLList();

    //copy constructor
    //DLList(const DLList& other);
    // Assignment operator (=)
    //DLList& operator=( const DLList& other);

    //unsigned    size() const;          // Return the size of the list
    bool        empty() const;         // Return true if list is empty
    void        push_front(const T& val);   // Insert the node at the beginning
    void        push_back(const T& val);    // Insert the node at the end
    void        print() const;         // prints the list

    void        pop_front(void);       // Remove the first node from the list
    //void        pop_back(void);

    //void        clear(void);

    //int&        at(unsigned index);     // Returns the reference of the value of the node at index
private:
    DLLNode<T>* head; // First node in the linked list
    DLLNode<T>* tail; // Last node in the linked list
    unsigned list_size; // The number of nodes in the linked list
};


#endif