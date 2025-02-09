/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base cases
        if(root == NULL) {
            return NULL;
        }
        if(root == p) {
            return p;
        }
        if(root == q) {
            return q;
        }

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p,q);

        if(leftAns == NULL && rightAns == NULL) {
            return NULL;
        }
        else if(leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        else if(leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        else {
            //leftAns != NULL && rightAns != NULL
            //ans => root NOde
            return root; 
        }





    }
};