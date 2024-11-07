bool isBalanced(TreeNode* root) {
        if (root == NULL)  return true;
		if (Height(root) == -1)  return false;
		return true;
	}
	int Height(TreeNode* root) {
		if (root == NULL)  return 0;
		int leftHeight = Height(root->left);
		int rightHight = Height(root->right);
		if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;
		return max(leftHeight, rightHight) + 1;
    }