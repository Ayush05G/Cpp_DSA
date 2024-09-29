#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow";
            return -1;
        }
        int value = top->data;
        cout << value << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

private:
    Node* top;
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.pop();
    myStack.pop();
    return 0;
}