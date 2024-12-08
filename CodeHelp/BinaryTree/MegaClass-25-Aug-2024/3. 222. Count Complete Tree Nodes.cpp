class Solution {
public:
    int findLeftHeight(TreeNode*root){
        int count = 0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }

    int findRightHeight(TreeNode*root){ // O(logn)
        int count = 0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh) return (1 << lh) - 1; // 2^lh - 1

        // if lh != rh,
        // ans = 1 + (...) + (...)
        int lans = countNodes(root->left);
        int rans = countNodes(root->right);
        return 1 + lans + rans;
    }
};