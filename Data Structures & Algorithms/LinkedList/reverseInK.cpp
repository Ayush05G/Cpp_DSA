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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // LL is empty
        if(head == NULL ) {
            return head;
        }
        //Single Node
        if(head -> next == NULL) {
            return head;
        }
        ///atleast 2 node, or >1 nodes
        
      
        //check for LL length
        int len = getLength(head);
        if(len < k) {
            //toh reverse krne ki need nhi h,as per question
            return head;
        }

        //1 case hum akrenge , baaaki recursion sambhal lega
        //1 case -> k length ko reverse karna h 

        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;

        while(position < k) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }

        //baaki recursion sambhal lega
        if(curr != NULL) {
            ListNode* recursionKaHead = reverseKGroup(curr, k);
            head->next = recursionKaHead;
        } 

        return prev;

    }
};