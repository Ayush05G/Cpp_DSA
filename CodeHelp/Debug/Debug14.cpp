#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int &targetSum) {
        if(!root)   return false;

        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right) return true;

        bool leftPath = hasPathSum(root->left, targetSum);
        bool rightPath = hasPathSum(root->right, targetSum);
        targetSum += root->val;

        return leftPath || rightPath;
    }

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    cout << hasPathSum(root, targetSum) << endl;
    return 0;
}