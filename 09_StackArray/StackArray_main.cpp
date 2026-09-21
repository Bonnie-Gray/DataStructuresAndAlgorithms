#include "StackArray.hpp"
#include <iostream>

int main(void) {
    StackArray<int> s;
    s.push(0);
    s.push(5);
    s.push(10);
    s.push(15);

    s.print();

    std::cout << "Full: " << ((s.full())? "Yes" : "No") << std::endl;
    std::cout << "Empty: " << ((s.empty())? "Yes" : "No") << std::endl;

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    s.print();

    std::cout << s.top() << std::endl;

    return 0;
}