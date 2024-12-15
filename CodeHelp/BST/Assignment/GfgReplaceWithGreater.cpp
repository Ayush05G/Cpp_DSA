struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Insert a value into the BST and update successor
    Node* insert(Node* root, int val, int& suc) {
        if (!root) {
            return new Node(val);
        }
        if (val >= root->data) {
            root->right = insert(root->right, val, suc);
        } else {
            suc = root->data;
            root->left = insert(root->left, val, suc);
        }
        return root;
    }

    // Replace elements with the least greater element
    void replace(vector<int>& arr, int n) {
        Node* root = nullptr;
        for (int i = n - 1; i >= 0; i--) {
            int suc = -1;
            root = insert(root, arr[i], suc);
            arr[i] = suc;
        }
    }

    // Main function to find the least greater element
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        replace(arr, n);
        return arr;
    }
};