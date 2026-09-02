#include "SLList.cpp"
#include <iostream>

int main(void) {
    SLList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    SLList list_copy = list;
    list.push_back(25);
    list.push_back(35);
    list.push_back(45);
    list.pop_front();
    list.pop_back();

    list.print();
    list_copy.print();

    list_copy = list;

    list.print();
    list_copy.print();

    std::cout << list.size() << std::endl;

    return 0;
}
