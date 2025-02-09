/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to insert nodes containing the Greatest Common Divisor (GCD) of the
    // adjacent nodes' values, between those nodes in the list.
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return nullptr; // Return if the list is empty
      
        ListNode* current = head; // Current node is set to the head of the list
        ListNode* nextNode = head->next; // Next node is the one following current
      
        // Iterate over each pair of adjacent nodes until the end of the list
        while (nextNode) {
            // Calculate GCD of the values in the current and next nodes
            int gcdValue = std::gcd(current->val, nextNode->val);
          
            // Insert a new node with calculated GCD value between current and next nodes
            current->next = new ListNode(gcdValue, nextNode);
          
            // Move to the next pair of nodes, skipping over the newly inserted node
            current = nextNode;
            nextNode = nextNode->next;
        }
        return head; // Return the updated list with inserted GCD nodes
    }
};