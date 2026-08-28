#include <iostream> //8-26-2026
#include "SLLNode.hpp"

int main(void) {
    // Create SLLNodes
    SLLNode* n1 = new SLLNode(1);
    SLLNode* n2 = new SLLNode(2);
    SLLNode* n3 = new SLLNode(3);
    SLLNode* n4 = new SLLNode(4);

    // Link the Nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Print the value of the first node
    std::cout << n1->data << std::endl;

    // Print the value of the second node
    std::cout << n2->data << std::endl;
    // or through n1
    std::cout << n1->next->data << std::endl;

    // Iterate through the nodes
    SLLNode* cur = n1;

    while(cur != nullptr) {
        std::cout << cur->data;  // access the data of the current node
        if (cur->next != nullptr) {
            std::cout << "<";
        }
        cur = cur->next;
    }





    return 0;
}