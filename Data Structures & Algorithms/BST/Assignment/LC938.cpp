class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int ans = 0;

        bool wasInRange = false;
        if (root->val >= low && root->val <= high) {
            wasInRange = true;
            ans += root->val;
        }

        if (wasInRange) {
            ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        } 
        else if (root->val < low) {
            ans += rangeSumBST(root->right, low, high);
        } 
        else if (root->val > high) {
            ans += rangeSumBST(root->left, low, high);
        }

        return ans;
    }
};
