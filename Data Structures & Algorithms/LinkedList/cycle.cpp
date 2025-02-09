/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast -> next;
            if(fast != NULL) {
                fast = fast -> next;
                slow = slow -> next;
                if(fast == slow) {
                    //cycle present
                    return true;
                }
            }
            
        }
        //loop se bahar, cycle absent
        return false;



        // unordered_map<ListNode* ,bool> m;
        // ListNode* temp = head;
        
        // while(temp != NULL) {
        //     if(m[temp] == true) {
        //         ////pehlse hi true h
        //         //cycle present
        //         return true;
        //     }
        //     else {
        //         //pehle se true nahi h, yaani false;
        //         //toh main visit krra hu ise
        //         m[temp] = true;
        //     }
        //     temp = temp -> next;
        // }
        // //agar yaha tk pohoch gye ho, iska mtlb loop se bahar aagye ho
        // //iska mtlb link list poori traverse hogyi
        // //and end me NULL milgya
        // //no cycle present
        // return false;

    }
};