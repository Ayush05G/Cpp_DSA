//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        //step1: reverse list;
        head = reverseList(head);
        //step2: add one
        //mujhe plus one karna h, toh main carry ko hi 1 maaanleta hu
        int carry = 1;
        Node* temp = head;
        
        while(temp != NULL) {
            int sum = carry + temp->data;
            //current node me 1 hi digit store hoga, double digit nahi ho skta 
            int digit = sum % 10;
            carry = sum / 10;
            
            temp -> data = digit;
            //move to next node
            //special case, jo last node k liye hoga
            if(temp -> next == NULL && carry != 0) {
                Node* newNode = new Node(carry);
                newNode->next = NULL;
                
                temp->next = newNode;
                temp = newNode;
            }
            //traverse krre h, toh aage toh badhna hi h 
            temp = temp -> next;
        }

        
        //step3: reverseList;
        head = reverseList(head);
        
        return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends