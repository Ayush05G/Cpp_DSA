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
    ListNode* getMiddle(ListNode* head, ListNode* &middleNodeKaPrev) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast -> next;
            if(fast != NULL) {
                fast = fast -> next;
                middleNodeKaPrev = slow;
                slow = slow -> next;
            }
        }
        return slow;
    }
    ListNode* reverseList(ListNode* & prev, ListNode* &curr) {
        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev= curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            //LL is empty
            return true;
        }
        if(head->next == NULL ) {
            //single node
            return true;
        }

        //travel till middle node and break the LL in 2 halves
        ListNode* firstHalfHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head, middleNodeKaPrev); 
        //break
        middleNodeKaPrev -> next = NULL;

        //reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = middleNode;
        ListNode* secondHalfHead = reverseList(prev, curr);

        //compare both the halves and decide T/F
        //even len wale case me dono part ki length equal hogi
        //odd wale case , second half ki length badi hogi by 1 
        //that's why main comparison hamesha first half ki length k hisaab se karunga 
        ListNode* temphead1 = firstHalfHead;
        ListNode* temphead2 = secondHalfHead;
        while(temphead1 != NULL) {
            if(temphead1 ->val != temphead2 ->val) {
                //not a palindrome
                return false;
            }
            else {
                //data equal hai, toh let's move to aage wali nodes
                temphead1 = temphead1 -> next;
                temphead2 = temphead2 -> next;
            }
        }
        //agar main yaha tk pohoch gya
        //iska mtlab kahin por bhi 
        //data mismatch nahi hua
        //palindrome haib 
        return true;
    }
};