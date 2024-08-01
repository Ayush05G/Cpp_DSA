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
    // ListNode* reverseList(ListNode* &prev, ListNode* &curr) {
    //     //base case
    //     if(curr == NULL) {
    //         //iska mtlb LL reverse ho chuki h
    //         //reversed LL k  starting node pr prev wala pointer hai
    //         return prev;
    //     }
    //     //1 case hum solve karenge 
    //     ListNode* forward = curr->next;
    //     //current node ko piche ki disha me point karwaya 
    //     curr->next = prev;
    //     //pointers ko 1 step aage badhaya and recursion ko pakkda dia aage solve krne k liye 
    //     prev = curr;
    //     curr = forward;
    //     //baaki recursion sambhal lega
    //     return reverseList(prev, curr);
    // }
    ListNode* reverseList(ListNode* head) {

        //iterative approach
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* forward = curr->next;
            //forward pointer set hogya, ab aage ki list lost nhi hogi 
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //newHead of linkedlist ko hoga -> prev pointer
        return prev;


        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // ListNode* newHead = reverseList(prev, curr);
        // return newHead;
    }
};