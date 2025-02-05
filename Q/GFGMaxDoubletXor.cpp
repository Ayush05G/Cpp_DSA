//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node* inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    scanf("%d ", &data);
    struct Node* head = new Node(data);
    struct Node* tail = head;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d ", &data);
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
public:
    int maximumDoubletXOR(struct Node* head) {
        if (!head || !head->next) return 0;
        
        vector<int> values;
        
        // Convert linked list to array for easier access
        Node* current = head;
        while (current) {
            values.push_back(current->data);
            current = current->next;
        }
        
        int n = values.size();
        int maxXOR = 0;
        
        // For each pair of doublet nodes
        for (int i = 0; i < n; i++) {
            // Calculate corresponding doublet index
            // If n = 6, then:
            // i = 0 pairs with n-1 = 5
            // i = 1 pairs with n-2 = 4
            // i = 2 pairs with n-3 = 3
            int doubletIdx = n - 1 - i;
            
            // Only process until we reach the middle
            if (i >= doubletIdx) break;
            
            // Calculate XOR of current doublet pair
            int currentXOR = values[i] ^ values[doubletIdx];
            maxXOR = max(maxXOR, currentXOR);
        }
        
        return maxXOR;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        struct Node* head = inputList();

        Solution obj;
        int res = obj.maximumDoubletXOR(head);

        cout << res << endl;
    }
}

// } Driver Code Ends