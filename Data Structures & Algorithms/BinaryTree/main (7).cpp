/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void LeftBoundary(Node* root, vector<int> & ans) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            //leaf node 
            return ;
        }
        
        ans.push_back(root->data);
        
        if(root->left != NULL) {
            LeftBoundary(root->left, ans);    
        }
        else {
            LeftBoundary(root->right, ans);
        }
    }
    void LeafBoundary(Node* root, vector<int>& ans) {
        if(root == NULL) {
            return ;
        }
        if(root->left == NULL && root->right == NULL) {
            //leaf node 
            ans.push_back(root->data);
        }
        LeafBoundary(root->left, ans);
        LeafBoundary(root->right, ans);
    }
    void RightBoundary(Node* root, vector<int>& ans) {
         if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            //leaf node 
            return ;
        }
        
        if(root->right != NULL) {
            RightBoundary(root->right,ans);
        }
        else {
            RightBoundary(root->left, ans);
        }
        //kyokki mujhe reverse order store krna h 
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {   vector<int> ans;
    
        if(root == NULL) {
            return ans;
        }
        //A -> root node
        ans.push_back(root->data);
        //B -> left subtree -> left boundary
        LeftBoundary(root->left, ans);
        //C -> left subtree -> leaf boundary
        LeafBoundary(root->left, ans);
        //D -> right subtree -> leaf boundary
        LeafBoundary(root->right,ans);
        //E -> right subtree -> right boundary
        RightBoundary(root->right, ans);
        
        return ans;
    }
};