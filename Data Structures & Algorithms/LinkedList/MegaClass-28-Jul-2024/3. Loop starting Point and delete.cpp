/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
                if (fast == slow)
                {
                    return fast;
                }
            }
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head)
    {
        // step 1: check if loop is there or not
        ListNode *fast = hasCycle(head);
        if (!fast)
            return nullptr;

        // fast is non-null means, cycle is there.
        // let's find starting point of cycle
        ListNode *slow = head;
        // now move slow & fast ptr with 1x speed, and
        // return where they meet.

        ListNode *prev = 0;

        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = nullptr; // loop removing
        return slow;          // Starting point
    }
};