#include "MinHeap.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
void MinHeap<T>::swap (T& v1, T& v2) {
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template <typename T>
void MinHeap<T>::print() const {
    for (const T& val : data) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}


template <typename T>
void MinHeap<T>::insert(const T& val) {
    data.push_back(val);
    int index = data.size() - 1;
    percolateUp(index);
}


// TODO implement 3 methods (Return -1 if the index doesn't exist)
template <typename T>
int MinHeap<T>::getParent(int index) const {
    if (index <= 0 || index >= data.size()) {
        return -1;
    }
    return (index - 1) /2;
}

template <typename T>
int MinHeap<T>::getLeftChild(int index) const {
    if (index < 0) {
        return -1;
    }
    int left = 2 * index + 1;

    if (left >= data.size()) {
        return -1;
    }
}

template <typename T>
int MinHeap<T>::getRightChild(int index) const {
    if (index < 0) {
        return -1;
    }
    int right = 2 * index + 2;

    if (right >= data.size()) {
        return -1;
    }
    return right;
}

template <typename T>
void MinHeap<T>::percolateUp(int index) {
    if (index < 0 || index >= data.size()) {
        std::cout << "perculateUp: incorrect index" << std::endl;
        return;
    }
    while (true) {
        int parent_idx = getParent(index);

        if (parent_idx == -1) {
            break;
        }

        if (data[index] < data[parent_idx]) {
            swap(data[index], data[parent_idx]);
            index = parent_idx;
        }
        else {
            break;
        }
    }
    
}

template <typename T>
T MinHeap<T>::deleteMin() {
    if(data.empty()) {
        throw std::out_of_range("deleteMin: empty heap");
    }

    T res = data[0];
    int last_idx = data.size() -1;
    data[0] = data [last_idx];          // set the last element at the root
    data.pop_back();                    // remove the last element from vector

    percolateDown();


}

template <typename T>
void MinHeap<T>::percolateDown() {
    // Start from the root
    int index = 0;
    while(true) {
        // Find children of the current node
        int left = (getLeftChild()); 
        int right = (getRightChild());
        // If there are no children stop iteration
        if (left = -1) {
            break;
        }
        // Find the smallest child 
        int smallerChild = left;
        if (right != -1 && data[right] < data[left]){
            smallerChild = right;
        }
        // If current value > value of the smallest child - swap the values
        if (data[smallerChild] < data[index]) {
            std::swap(data[smallerChild], data[index]);
            index = smallerChild;
        } 
        // If not - break
        else {
            break;
        }
    }
}