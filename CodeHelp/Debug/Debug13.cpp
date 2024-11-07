void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();

            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            if (!s.empty()) cur->right = s.top();
            cur->left = nullptr;
        }
    }

