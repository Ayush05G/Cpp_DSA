class Solution {
    public:
    ListNode* deleteMiddle(ListNode* head) {
       
        if (head->next == nullptr) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
    
        while (fast != nullptr && fast->next != nullptr ) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        prev->next = slow->next;
        delete slow;
        return head;
    }
    };