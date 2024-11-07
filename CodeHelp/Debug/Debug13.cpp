int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 1;
        int ld = rec(root->left, d)+1;
        int rd = rec(root->right, d)+1;
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }