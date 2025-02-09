/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *solve(Node *head)
    {
        auto it = head;
        auto tail = it; // for tracking tail node.

        while (it)
        {
            if (it->child)
            {
                auto childTail = solve(it->child); // tail node
                // flatten ka kaam
                auto temp = it->next;
                it->next = it->child;
                it->next->prev = it;
                childTail->next = temp;
                if (temp)
                    temp->prev = childTail;
                it->child = nullptr;
            }
            tail = it;
            it = it->next;
        }
        return tail;
    }

    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;
        solve(head);
        return head;
    }
};