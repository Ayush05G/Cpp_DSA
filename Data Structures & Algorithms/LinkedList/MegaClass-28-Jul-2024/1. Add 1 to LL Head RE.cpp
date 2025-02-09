#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    // jab tak merea temp NULL k equal nahi h, tab tak node print krte raho
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void solve(Node *head, int &carry)
{
    if (!head)
        return;
    solve(head->next, carry); 0->0 ->0-> x

    // 1 case
    int sum = head->data + carry;
    int digit = sum % 10;
    carry = sum / 10; // imp.
    head->data = digit;
}

Node *add1(Node *head, int &carry)
{
    solve(head, carry);
    if (carry)
    {
        // insertAtHead
        Node *newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}

int main()
{
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    print(head);
    int carry = 1;
    head = add1(head, carry);
    print(head);
    return 0;
}