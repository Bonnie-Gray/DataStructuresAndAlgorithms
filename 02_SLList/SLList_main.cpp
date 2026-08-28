#include "SLList.cpp"
#include <iostream>

int main(void) {
    SLList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_back(25);
    list.push_back(35);
    list.push_back(45);

    list.print();
    std::cout << list.size() << std::endl;

    return 0;
}
