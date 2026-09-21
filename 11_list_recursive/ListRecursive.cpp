#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {

    }

};

void printList(const Node* node);

void printListReverse (const Node* node);

int getListSize(const Node* node);

Node* reverseList(Node* node);

int main(void) {
    //Create the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);
    printListReverse(head);

    std::cout << "Size: " << getListSize(head) << std::endl;

    head = reverseList(head);
    printList(head);

    return 0;
}

void printList(const Node* node) { //print recursively
    if (!node) {
        std::cout << "\n";
        return;
    }
    std::cout << node->data << " ";
    printList(node->next);
}

void printListReverse(const Node* node) { //print recursively
    if (!node) {
        std::cout << "\n";
        return;
    }
    Node* temp = reverseList(node);
    printList(temp);
    
}

int getListSize(const Node* node) {
    if (!node) {
        return 0;
    }
    return (1 + getListSize(node->next));
}

Node* reverseList(Node* node) {
    if (!node || !node->next) {
        return node;
    }
    Node* new_head = reverseList(node->next);
    node->next->next = node;
    node->next = nullptr;

    return new_head;
}