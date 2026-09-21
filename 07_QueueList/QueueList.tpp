#include "QueueList.hpp"

template <typename T, int size> 
bool QueueList<T, size>::empty() const {
    return list.empty();
}

template <typename T, int size> 
void QueueList<T, size>::print() {
    list.print();
}

template <typename T, int size> 
void QueueList<T, size>::enqueue() {
    list.push_back();
}

template <typename T, int size> 
void QueueList<T, size>:: dequeue() {
    list.pop_front();
}

template <typename T, int size> 
bool QueueList<T, size>::full() {
return queue_size == size;
}

template <typename T, int size>
const T& QueueList<T, size>::front() {
    return data[head];
}

template <typename T, int size>
void QueueList<T, size>::clear() {
    while(!empty()){
        list.pop_front();
    }

}

template <typename T, int size>
int QueueList<T, size>::size() {
    return size;
}


