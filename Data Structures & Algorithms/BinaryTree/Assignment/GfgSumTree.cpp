/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    int sum(Node*root){
        if(!root)
        return 0;
        if (!root->left && !root->right){
            int temp= root->data;
            root->data=0;
            return temp;
        }
        int lsum=sum(root->left);
        int rsum=sum(root->right);
        int temp=root->data;
        root->data=lsum+rsum;
        return root->data+temp;
    }
    void toSumTree(Node *node)
    {
        
        sum (node);
    }
};