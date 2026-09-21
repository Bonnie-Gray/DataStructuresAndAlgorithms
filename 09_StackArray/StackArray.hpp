#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

template <typename T, int capacity = 100>
class StackArray {
public:
    StackArray();

    void push(const T& val);
    T   pop();
    bool full() const;
    bool empty() const;
    void print() const;
    const T& top() const; //returns the reference to the top element

    private:
    T data[capacity];
    int top_idx;
};

#include "StackArray.tpp"
#endif