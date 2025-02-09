struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
  pair<int, int> height(Node*root) {
    if(!root) return {0,0};
    auto lh= height(root->left);
    auto rh= height(root->right);
    int sum = root->data;
    if(lh.first== rh.first){
    sum += lh.second > rh.second? lh.second: rh.second;
        }
    else if(lh.first > rh.first){
    sum += lh.second;
    } 
    else{
    sum += rh.second;
    }
    return {max(lh.first, rh.first) + 1, sum};

}
    int sumOfLongRootToLeafPath(Node *root) {
        auto h=height(root);
        return h.second;
    }
};