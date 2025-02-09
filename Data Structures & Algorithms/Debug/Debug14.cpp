#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

TreeNode * ans =new TreeNode(0);
    TreeNode* solve(vector<int> &node,int s,int e,int n){
        if(s>e){
            return NULL;
        }
        int mid=(s+e+1)/2;
        TreeNode* p=new TreeNode(node[mid]);
       
         p->left=solve(node,s,mid-1,n);
         p->right=solve(node,mid+1,e,n);
        return p;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode* tmp= new TreeNode(0);
       
       return solve(v,0,v.size()-1,v.size()-1);
        
    }

int main(){
    ListNode* head=new ListNode(-10);
    head->next=new ListNode(-3);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(5);
    head->next->next->next->next=new ListNode(9);
    TreeNode* root=sortedListToBST(head);
    return 0;
}