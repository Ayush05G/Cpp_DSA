/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int k, int &count, TreeNode *&ans) {
        if(root == NULL) {
            return ;
        }
        //LNR
        //L
        solve(root->left, k, count, ans);
        //N
        count++;
        if(count == k) {
            ans = root;
            return;
        }
        //R
        solve(root->right,k,count, ans);   
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* ans = NULL;
        solve(root,k,count,ans);
        return ans->val;
    }
};