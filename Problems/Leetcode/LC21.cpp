#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.   
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==0)return list2;
        if(list2==0)return list1;
        ListNode*ans=new ListNode(-1);
        ListNode*mptr=ans;
        while(list1&&list2){
            if(list1->val<=list2->val){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }
            else{
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }
 while(list1){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
    }
    while(list2){
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
    }
    return ans->next;
    }
};