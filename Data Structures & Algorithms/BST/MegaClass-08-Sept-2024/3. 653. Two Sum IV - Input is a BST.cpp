class BSTIterator {
    stack<TreeNode*>st; // using this stack, I'm doing LNR, inorder traversal.
    stack<TreeNode*>revSt; // reverse inorder traversal
    void pushLeftNodes(TreeNode*root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    void pushRightNodes(TreeNode*root){
        while(root){
            revSt.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
        pushRightNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();

        if(top->right)
            pushLeftNodes(top->right);

        return top->val;
    }

    int before() {
        auto top = revSt.top();
        revSt.pop();

        if(top->left)
            pushRightNodes(top->left);

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    bool hasBefore() {
        return !revSt.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);

        int i = it.next(); // smalled, L -> R
        int j = it.before(); // largest, R -> L

        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k)
                i = it.next(); // start++
            else
                j = it.before(); // end--
        }
        return false;
    }
};