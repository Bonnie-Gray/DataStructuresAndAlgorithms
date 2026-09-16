#include "Deque.hpp"
#include <iostream>

int main(void) {
    Deque<int> d;
    d.push_front(5);
    d.push_front(0);
    d.push_back(10);
    d.push_back(15);

    d.print();
    std::cout << "Empty: " << ((d.empty())? "Yes" : "No") << std::endl;
    std::cout << "Full: " << ((d.full())? "Yes" : "No") << std::endl;

    std::cout << d.pop_back() << std::endl;
    std::cout << d.pop_front() << std::endl;

    d.print();

    std::cout << d.front() << std::endl;
    std::cout << d.back() << std::endl;

    std::cout << d.length() << std::endl;

    d.clear();

    d.print();
}   