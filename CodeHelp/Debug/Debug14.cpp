#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* cur, TreeNode*& prev, TreeNode*& first, TreeNode*& sec) {
    if (!cur) { return; }
    inorder(cur->left, prev, first, sec);
    if (prev != NULL && cur->val < prev->val) {
        if (!first) { first = prev; }
        sec = cur;
    }
    prev = cur;
    inorder(cur->right, prev, first, sec);
}

void recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* sec = nullptr;
    inorder(root, prev, first, sec);
    int temp = first->val;
    first->val = sec->val;
    sec->val = temp;
}

int main(){
    // Create a tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    recoverTree(root);
    return 0;
}