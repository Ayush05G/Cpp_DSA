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
int ans=0;
    void pathfromoneroot(TreeNode*root, long long sum){
        if (!root) return;
        if(sum==root->val){
            ++ans;
        }
        pathfromoneroot(root->left,sum-root->val);
        pathfromoneroot(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            pathfromoneroot(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
        
    }
};