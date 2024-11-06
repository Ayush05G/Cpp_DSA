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
    int getHeight(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int ansHeight = max(lh,rh) + 1;
        return ansHeight;
    }
    bool isBalanced(TreeNode* root) {

        if(root == NULL ) {
            return true;
        }

        //current node pr check laga ra hu
        //1 case solve krra hu 
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int absDiff = abs(lh-rh);
        bool status = (absDiff <= 1);

        //baaki recursion sambhal lega
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        //i can say whether tree is balanced or not, when
        //curr node is blanced and 
        //left subtree is balanced and
        //right subtree is balanced
        if(status && leftAns && rightAns) {
            return true;
        }
        else {
            return false;
        }






    }
};