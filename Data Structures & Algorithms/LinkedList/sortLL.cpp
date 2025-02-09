//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void print(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
    void insertAtTail(Node* &toMove, Node* &head, Node* &tail) {
       //LL is empty
       if(head == NULL && tail == NULL) {
           head = toMove;
           tail = toMove;
       }
       else {
           tail->next = toMove;
           tail = toMove;
       }
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        
        // LL pr traverse larenge and ye 3 LL ready krenge separate
        Node* temp = head;
        while(temp != NULL) {
            
            //create toMove node and isolate it
            Node* toMove = temp;
            temp = temp -> next;
            toMove->next = NULL;
            
            if(toMove->data == 0) {
                insertAtTail(toMove, zeroHead, zeroTail);
            }
            else if(toMove->data == 1) {
                insertAtTail(toMove, oneHead, oneTail);
            }
            else if(toMove->data == 2) {
                insertAtTail(toMove, twoHead, twoTail);
            }
            
        }

        //yaha jab pohoche, toh teeno LL ready h 
        //merge them 
        //empty wali possibility bhulna mat
        if(zeroHead != NULL) {
            //zero list is non-empty
            if(oneHead != NULL) {
                //one list is non-empty
                zeroTail->next = oneHead;
                //merge with 2 wali list
                oneTail->next = twoHead;
            }
            else {
                //one list is empty
                zeroTail->next = twoHead;
            }
            return zeroHead;
        }
        else {
            //zero List is empty
            if(oneHead != NULL) {
                oneTail->next = twoHead;
                return oneHead;
            }
            else {
                return twoHead;
            }
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends