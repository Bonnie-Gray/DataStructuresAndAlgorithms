#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP


template <typename T, int size = 100>
class QueueArray {
public:
    QueueArray();

    bool        empty() const;
    bool        full() const;
    void        print() const;
    void        enqueue(const T& val);

    const T&    dequeue();

    const T&    front();                // Returns first element in the queue but doesn't delete it
    void        clear();                // Removes all elements from the queue
    int         size();                 // Returns the size of the queue

private:
    T data[size];
    int front_index, back_index;
    int queue_size;
};
#include "QueueArray.tpp"

#endif