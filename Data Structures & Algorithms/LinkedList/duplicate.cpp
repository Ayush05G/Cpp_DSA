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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // 1case -> LL is empty
        if(head == NULL) {
            return head;
        }
        //2 case -> LL -> single node 
        if(head -> next == NULL) {
            return head;
        }
        //3 case >1 node 
        // atleast 2 node toh pkka hogi 
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp != NULL) {
            
            //duplicate check karo 
            if(temp->val == prev->val) {
                //duplicate found
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else {
                //duplicate not found
                prev = prev->next;
                temp = temp->next;
            }
            //temp ko set kardo
            temp = prev->next;
        } 
        return head;










    }
};