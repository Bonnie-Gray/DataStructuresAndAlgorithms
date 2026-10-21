#include "MinHeap.hpp"
#include <std.except>
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
    
    
}

template <typename T>
int MinHeap<T>::getLeftChild(int index) const {
    
}

template <typename T>
int MinHeap<T>::getRightChild(int index) const {

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
        throw std::out_of_range("deleteMin: empty heap")
    }

    T res = data[0];
    int last_idx = data.size() -1;
    data[0] = data [last_idx];          // set the last element at the root
    data.pop_back();                    // remove the last element from vector

    perculateDown();


}

template <typename T>
void MinHeap<T>::perculateDown() {
    // Start from the root
    // Find children of the current node
    // If there are no children stop iteration
    // Find the smallest child 
    // If current value > value of the smallest child - swap the values
    // If not - break
}