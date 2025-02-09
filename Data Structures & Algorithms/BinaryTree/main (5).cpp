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
    void createMapping(unordered_map<int,int> &valueToIndex,vector<int> inorder) {
        for(int i=0; i<inorder.size(); i++) {
            int element = inorder[i];
            int index = i;
            valueToIndex[element] = index;
        }
    }
    int getIndexInorder(vector<int> inorder, int target) {
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* constructTree(unordered_map<int,int> &valMap, vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inorderStart, 
    int inorderEnd, int size) {
        //base case
        if(preOrderIndex >= size) {
            return NULL;
        }
        if(inorderStart > inorderEnd) {
            return NULL;
        }

        //process the first element of preorder as root
        //step1: get element from preorder and create root node for it 
        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);
        //step2: find this element inside inorder and call for left and rigth 
        int elementIndexInsideInorder = valMap[element];
        //inorder left part -> index inorderStart to elementIndexInsideInorder-1
        //inorder right part -> index elementIndexInsideInorder+1 to inorderEnd
        root->left = constructTree(valMap,preorder, inorder, preOrderIndex, inorderStart, elementIndexInsideInorder-1,size);
        root->right = constructTree(valMap, preorder, inorder, preOrderIndex, elementIndexInsideInorder+1 , inorderEnd, size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int size = inorder.size();
        unordered_map<int,int> valMap;
        createMapping(valMap, inorder);
        TreeNode* root = constructTree(valMap,preorder, inorder, preIndex, inorderStart, inorderEnd, size);
        return root;
    }











};