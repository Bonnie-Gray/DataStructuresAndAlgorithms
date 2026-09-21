#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP
#include "../04_DLList/DLList.hpp"

template <typename T, int size = 100>
class QueueList {
public:
    QueueList();

    bool        empty() const;
    bool        full() const;
    void        print() const;
    void        enqueue(const T& val);

    const T&    dequeue();

    const T&    front();                // Returns first element in the queue but doesn't delete it
    void        clear();                // Removes all elements from the queue
    int         size();                 // Returns the size of the queue

private:
    DDList<T> list;
};

#include "QueueList.tpp"

#endif