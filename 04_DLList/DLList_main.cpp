#include "DLList.tpp"
#include <iostream>

int main(void) {
    DLList<char> list;

    list.push_front('q');
    list.push_front('e');
    list.push_front('r');

    list.push_back('f');
    list.push_back('p');

    list.pop_front();

    list.print();
    
}