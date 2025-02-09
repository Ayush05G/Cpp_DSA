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
    int getMax(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        while(root->right != NULL) {
            root = root->right;
        }
        //iska mtlb, jab main yaha pohochunga
        //tab root extreme left pr hoga
        return root->val;
    }
    int getMin(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        while(root->left != NULL) {
            root = root->left;
        }
        //iska mtlb, jab main yaha pohochunga
        //tab root extreme left pr hoga
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            //match
            //ab mujhe node delete krni h 
            //cases:
            //with 0 child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            //with left child only
            if(root->left != NULL && root->right == NULL) {
                TreeNode* leftChild = root->left;
                root->left = NULL;
                delete root;
                return leftChild;
            }
            //with right child only
            if(root->left == NULL && root->right != NULL) {
                TreeNode* rightChild = root->right;
                root->right = NULL;
                delete root;
                return rightChild;
            }
            ///with both left and left child
            if(root->left != NULL && root->right != NULL) {
                // //to find just chotta element
                // int maxVal = getMax(root->left);
                // ///replace root node's value with maxVal
                // root->val = maxVal;
                // //delete actual node of maxVal;
                // root->left = deleteNode(root->left, maxVal);
                // return root;

                int minVal = getMin(root->right);
                root->val = minVal;
                root->right = deleteNode(root->right, minVal);
                return root;
            }

        }
        else {
            //not match
            //left ya right joa 
            if(key < root->val) {
                //left jao 
                root->left = deleteNode(root->left, key);
            }
            else {
                //right jao
                root->right = deleteNode(root->right, key);
            }
        }
    return root;
    }
};