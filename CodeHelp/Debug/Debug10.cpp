#include <iostream>

class Node {
    public:
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    std::cout << "Original Linked List: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}