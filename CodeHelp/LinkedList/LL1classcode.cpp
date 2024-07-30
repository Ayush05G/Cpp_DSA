#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    //constructor
    Node(int value) {
      this->data = value;
      this->next = NULL;
    }
};
//returns head of the new LLL after insertion
Node* insertAtHead(int value, Node* &head, Node* &tail) {
  //LL is empty -> head and tail both nULL ko point krre honge
  //it means we are creating first node of LL
  if(head == NULL && tail == NULL ) {
    //step1: create a new node
    Node* newNode = new Node(value);
    //step2: head ko node pr lagado
    head = newNode;
    //step3: tail ko newNOde pr lagado 
    tail = newNode;
  }
  else {
    //LL is not empty
    //pehle se node present hai 
    //insert at head
    //step1: create node
    Node* newNode = new Node(value);
    //step2: connect this newNOde to head node
    newNode->next = head;
    //step3: head update krdo 
    head = newNode;
    
  }
  return head;


}

//return head of the updated list 
void insertAtTail(int value, Node* &head, Node* &tail) {
  if(head == NULL && tail == NULL) {
    //LL is empty
    //iska mtlb abhi tum first node create krne jaa rhe ho LL ki
    //steps: create node, head on that node, tail on that node
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }
  else {
    //LL is not empty
    //step1: create node
    Node* newNode = new Node(value);
    //step2: tail node ko new node se connect karo 
    tail->next  = newNode;
    //step3: tail update
    tail = newNode;
  }

}

void print(Node* head) {
  Node* temp = head;
  //jab tak merea temp NULL k equal nahi h, tab tak node print krte raho
  while(temp != NULL) {
    cout << temp -> data << "->";
    temp = temp-> next;
  }
  cout<<"NULL" << endl;
}

int getLength(Node* head) {
  int len = 0;
  Node* temp = head;

  while(temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

void insertAtPosition(int position,int value, Node* &head, Node* &tail ){
  //assume -> valid positions input
  int length = getLength(head);
  if(position == 1) {
    //insert at ahead krna chahta hu 
    head = insertAtHead(value, head, tail);
  }
  else if(position == length + 1) {
    //insert at tail krna chahta hu 
    insertAtTail(value, head, tail);
  }
  else {
    //insert in between kahin krna chahta hu 
    Node* temp = head;
    for(int i=0; i<position-2; i++) {
      temp = temp -> next;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

//HW -> exact position return karo, jaha pr target aapko mila
//if not found, then return -1
bool searchLL(int target, Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    if(temp ->data == target) {
      return true;
    }
    temp = temp->next;
  }
  //agar yaha tak main pohoch gya
  //iska matlab, poori LL traverse ho chuki h,/
  //and kahin pr bhi target nahi mila
  //iska mtlab return false krdo 
  return false;
}

void deleteNodeFromLL(int position, Node* &head, Node* &tail) {
  //if LL is empty, then we cannot delete
  if(head == NULL && tail == NULL) {
    cout << "No node to delete" << endl;
    return;
  }
  //single node in LL
  if(head == tail) {
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  }
  else {
    //multiple nodes inside LL
    //2 case 
    //first case -> pos = 1 delete krna chahte h 
    if(position == 1) {
      Node* temp = head;
      head = temp->next;
      temp->next = NULL;
      delete temp;
    }
    else {
      //any other node except the first one
      Node* prev = head;
      for(int i=0; i<position-2; i++) {
        prev = prev -> next;
      }
      Node* curr = prev ->next;
      Node* forward = curr ->next;
      prev->next = forward;
      curr->next = NULL;
      delete curr;
    }

  }
}

int main() {

  Node* head = NULL;
  Node* tail = NULL;
  //LL is empty
  insertAtTail(101,head,tail);
  //print(head);
  //101 -> NULL
  insertAtTail(102,head,tail);
  //print(head);
  //101->102->NULL
  insertAtTail(103,head,tail);
  //print(head);
  //101->102->103->NULL
  insertAtPosition(1, 42, head, tail);
  //print(head);
  insertAtPosition(5,57,head,tail);
  //print(head);
  insertAtPosition(3,420,head,tail);
  print(head);
  //cout << searchLL(1030,head);
  deleteNodeFromLL(1,head,tail);
  print(head);
  deleteNodeFromLL(3,head,tail);
  print(head);
  deleteNodeFromLL(4,head,tail);
  print(head);





  // Node* head = NULL;
  // Node* tail = NULL;
  // //LL is empty
  // head = insertAtHead(10, head, tail);
  //   print(head);
  // //10 -> NULL
  // head  = insertAtHead(20,head,tail);
  //   print(head);
  // //20->10->NULL
  // head = insertAtHead(30,head,tail);
  //   print(head);
  //30->20->10->NULL

  //print(head);

  //stack
  //Node first;
  //dynamic memory
  //Node* first = new Node(10);
  return 0;
}