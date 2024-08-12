#include <iostream>

class Node {
    public:
    int data;
    Node* next;
};

Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* mergedList = new Node;  // Create a dummy node to simplify the code
    Node* current = mergedList;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach the remaining nodes (if any)
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList->next;  // Return the actual head of the merged list
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Populate list1 with values 1, 3, 5
    for (int i = 1; i <= 5; i += 2) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = list1;
        list1 = newNode;
    }

    // Populate list2 with values 2, 4, 6
    for (int i = 2; i <= 6; i += 2) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = list2;
        list2 = newNode;
    }

    Node* mergedList = mergeSortedLists(list1, list2);

    std::cout << "Merged Sorted List: ";
    printList(mergedList);

    return 0;
}