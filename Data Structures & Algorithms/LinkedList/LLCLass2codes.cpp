#include <iostream>
using namespace std;

class Node{
  public: 
  int data;
  Node* prev;
  Node* next;

  Node(int value) {
    data = value;
    prev = NULL;
    next = NULL;
  }
};

void insertAtHead(int value, Node* &head, Node* &tail) {
  //2 cases -> LL is empty / non-empty
  //empty wala case
  if(head == NULL && tail == NULL) {
    //iska mtlb, main firstb node create krne wala hu 
    Node* newNode = new Node(value);
    head = newNode;
    tail= newNode;
  }
  else {
    //LL is not empty
    Node* newNode = new Node(value);
    newNode->next = head;
    head -> prev = newNode;
    head = newNode;
  }
}

void print(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp ->next;
  }
  cout << "NULL"<<endl;
}

void printReverse(Node* tail) {
  Node* temp = tail;
  while(temp != NULL) {
    cout << temp->data <<"->";
    temp = temp->prev;
  }
  cout << "NULL" << endl;
}

void insertAtTail(int value, Node* &head, Node* &tail ){
  //2 case -> LL is empty or non-empty;
  if(head == NULL && tail == NULL) {
    //LL is empty
    //Step1: create a new node
    Node* newNode = new Node(value);
    //step2: head update
    head = newNode;
    //step3: tail update
    tail = newNode;
  }
  else {
    //LL is non-empty
    //step1: create a new node
    Node* newNode = new Node(value);
    //step3: connect newNode with tail node
    newNode->prev = tail;
    //step2: connect tail node with newNode
    tail->next = newNode;
    //step4: tail update
    tail = newNode;
  }
}

int getLength(Node* &head) {
  Node* temp = head;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp ->next;
  }
  return count;
}

void insertAtPosition(int position,int value, Node* &head, Node* &tail) {
  //3 cases -> leftmost end, rightmost end, middle me insert krna chahte ho
  int len = getLength(head);
  if(position == 1) {
    //insert leftmost me krna chahte h 
    insertAtHead(value, head,tail);
  }
  else if(position == len+1) {
    //rightmost end pr insert krna chahta hu
    //tail pr insert krna chahta hu
    insertAtTail(value, head, tail);
  }
  else {
    //middle me kisi poistion pr insert krna chahta hu 
    Node* temp = head;
    //fer main temp ko position-2 steps aage badhaya 
    for(int i=0; i<position-2; i++) {
      temp = temp ->next;
    }
    //create node
    Node* newNode = new Node(value);
    //forward pointer set
    Node* forward = temp->next;
    //pointers ko set krra hu 
    newNode->prev = temp;
    temp->next = newNode;
    forward->prev = newNode;
    newNode->next = forward;
  }
  

}

bool searchElement(Node* head, int target) {
  Node* temp = head;
  while(temp != NULL) {
    if(temp ->data == target) {
      return true;
    }
    temp = temp -> next;
  }
  //agar yaha tk pahuch gye, iska mtlb
 // LL poori travel krli h and target nahi mila
  return false;
}


void deleteFromPosition(int position, Node* &head, Node* &tail) {
  int length = getLength(head);
  //LL is empty
  if(head == NULL && tail == NULL) {
    cout << "no nodes to delete" << endl;
    return;
  }
  else if(head == tail) {
    //single node to delete
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  }
  else if(position == 1) {
    //we want to delete head node
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
  }
  else if(length == position) {
    //we want to delete the tail node
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
  }
  else {
    //we want to delete any other node than head and tail node
    Node* backward = head;
    for(int i=0; i<position-2; i++) {
      backward = backward -> next;
    }
    Node* curr = backward->next;
    Node* forward = curr->next;

    //pointers change
    backward->next = forward;
    forward->prev = backward;
    //curr ko isolate karna h 
    curr->prev = NULL;
    curr->next = NULL;
    //curr isolate ho chuka h 
    delete curr;

  }
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;
  //cout << "hello" << endl;
  insertAtTail(10,head,tail);
  //10->NULL;
  insertAtTail(20,head,tail);
  //10->20->NULL;
  insertAtTail(30,head,tail);
  //10->20->30->NULL;
  //print(head);
  insertAtPosition(4, 420, head, tail);
  print(head);
  deleteFromPosition(4, head, tail);
  print(head);



  // insertAtHead(10,head,tail);
  // //10->NULL
  // insertAtHead(20,head,tail);
  // //20->10->NULL
  // insertAtHead(30,head,tail);
  // //30->20->10->NULL
  // print(head);
  // printReverse(tail);
  return 0;
}