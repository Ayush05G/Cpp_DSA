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
    bool validate(TreeNode*root, long long lb, long long ub){
        if(!root) return true;

        bool isCurrentNodeInRange = root->val > lb && root->val < ub;
        bool isLeftBST = true;
        bool isRightBST = true;
        if(isCurrentNodeInRange) {
            isLeftBST = validate(root->left, lb, root->val);
            isRightBST = validate(root->right, root->val, ub);
        }

        return isCurrentNodeInRange && isLeftBST && isRightBST;
    }

    bool validate2(TreeNode*root, long long lb, long long ub){
        if(!root) return true;

        return root->val > lb && root->val < ub 
            && validate2(root->left, lb, root->val) 
            && validate2(root->right, root->val, ub);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long lb = LONG_MIN, ub = LONG_MAX;
        return validate2(root, lb, ub);
    }
};