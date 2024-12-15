class Solution{
  public:
    void findallNodes(Node* root,map<int,int> &allnodes)
{
    if(root == NULL)
    return ;
    
    allnodes[root->data] = 1;
    findallNodes(root->left,allnodes);
    findallNodes(root->right,allnodes);
}
bool check(Node* root,map<int,int> &allnodes)
{
    if(root == NULL)
    return false;
    
    if(root->left == NULL and root->right == NULL)
    {
        int pre = root->data - 1;
        int next = root->data + 1;

        if(allnodes.find(pre) != allnodes.end() and allnodes.find(next) != allnodes.end())
        return true;
    }
    
    return check(root->left,allnodes) or check(root->right,allnodes);
    
}
bool isDeadEnd(Node *root)
{
    // Base case
   if (root == NULL)
        return false ;
    map<int,int> allnodes;
      // adding 0 for handling the exception of node having data = 1
    allnodes[0] = 1;
    findallNodes(root,allnodes);
    
    return check(root,allnodes);
    
}
};