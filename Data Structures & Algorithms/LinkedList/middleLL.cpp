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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            //fast ko 1 step aage karo
            fast = fast->next;
            //NULL check karo and fast ko 1 step or aage karo
            if(fast != NULL) {
                fast = fast ->next;
                //ab fast k 2 steps complete ho chuke h
                //toh ab slow ko bhi ek step aage karo
                slow = slow -> next;
            }
        }
        return slow;
    }
};