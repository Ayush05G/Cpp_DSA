/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, int s, int e) {
        if(s > e) {
            return NULL;
        }
        //1 case solve krdeta hu 
        int mid = (s+e)/2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        //baaki recursion sambhal lega 
        root->left = solve(inorder, s, mid-1);
        root->right = solve(inorder, mid+1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& inorder) {
        int s = 0;
        int n = inorder.size();
        int e = n - 1;
        TreeNode* root = solve(inorder, s, e);
        return root;
    }
};