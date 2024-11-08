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
        
        if(root == NULL) {
            return NULL;
        }
        //case A: 
        //p and q are both on left side 
        //right -> neglect and left -> select
        if(p->val < root-> val && q->val < root-> val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p , q);
            if(leftAns != NULL) {
                return leftAns;
            }
        }
        //case B:
        //p and q are both on right side 
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            if(rightAns != NULL) {
                return rightAns;
            }
        }
        //case C:
        //p in left subtree and q in right subtree
        //case D:
        // q in left subtree and p in right subtree
        return root;
    }
};