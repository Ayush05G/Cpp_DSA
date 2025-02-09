/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> getMaxSum_helper(Node*root) {
    if(!root) return {0, 0};

    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);

    // sum including the node;
    int a=root->data + left.second + right.second;
    //sum excluding the node;
    int b= max(left.first, left.second) + max(right.first, right.second);
    return {a, b};
    }
    int getMaxSum(Node *root) 
    {
        auto ans=getMaxSum_helper(root);
        return max(ans.first,ans.second);
    }
};