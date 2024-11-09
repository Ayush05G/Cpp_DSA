//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool checkCompleteness(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;

        while(!q.empty() ) {
            Node* front = q.front();
            q.pop();

            if(front == NULL) {
                nullFound = true;
            }
            else {
                //front ek valid node h 
                if(nullFound == true) {
                    //not a cbt
                    return false;
                }
                else {
                    //may be a cbt, continue processing
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
    bool checkMaxProperty(Node* root) {
        if(root == NULL) {
            return true;
        }
        if(root->left ==NULL && root->right == NULL) {
            return true;
        }
        
        bool leftAns = checkMaxProperty(root->left);
        bool rightAns = checkMaxProperty(root->right);
        
        
        bool option1 = true;
        if(root->left && root->data < root->left->data) {
            option1 = false;
        }
        bool option2 = true;
        if(root->right && root->data < root->right->data) {
            option2 = false;
        }
        
        bool currAns = option1 && option2;
        
        if(currAns && leftAns && rightAns)
            return true;
        else
            return false;
        
    }
    bool isHeap(struct Node* tree) {
        bool completeness = checkCompleteness(tree);
        bool maxProperty = checkMaxProperty(tree);
        if(completeness && maxProperty) {
            return true;
        }
        else {
            return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends