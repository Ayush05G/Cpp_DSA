#include <iostream>
using namespace std;

class DeCircularQueue{
  public :
    int *arr;
    int n;
    int front;
    int rear;

    DeCircularQueue(int size) {
      this-> n = size;
      arr = new int[size];
      front = -1;
      rear = -1;
    }
    void pushFront(int val) {
      //4 cases: Overflow, first elemnt, circualr nature, normal flow
      if((front == 0 && rear == n-1)||(rear == front-1)) {
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        front++;
        rear++;
        arr[front] = val;
      }
      else if(front == 0 && rear != n-1) {
        //circular case
        front = n-1;
        arr[front]=val;
      }
      else {
        //normal case
        front--;
        arr[front]= val;
      }
    }
    void pushBack(int val) {
      //4 cases: Overflow, first elemnt, circualr nature, normal flow
      if((front == 0 && rear == n-1)||(rear == front-1)) {
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        front++;
        rear++;
        arr[rear] = val;
      }
      else if(rear == n-1 && front != 0) {
        //circular nature
        rear = 0;
        arr[rear] = val;
      }
      else {
        //normal flow
        rear++;
        arr[rear] = val;
      }
    }
    void popFront() {
      //4 cases: Underflow, single elemtn, circular nature , normal flow 
      if(front==-1 && rear==-1) {
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        //single element
        arr[front] = -1;
        front=-1;
        rear= -1;
      }
      else if(front== n-1 ) {
        //circular nature
        arr[front] = -1;
        front = 0;
      }
      else {
        //normal case
        arr[front] = -1;
        front++;
      }
    }
    void popBack() {
      //4 cases: Underflow, single elemtn, circular nature , normal flow 
      if(front==-1 && rear==-1) {
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        //single element
        arr[front] = -1;
        front=-1;
        rear= -1;
      }
      else if(rear == 0) {
        //circular case
        arr[rear] = -1;
        rear = n-1;
      }
      else {
       //normal case
       arr[rear] = -1;
       rear--; 
      }

    }
    void print() {
    for(int i=0; i<n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};


int main() {
  DeCircularQueue q(5);
  
  q.pushFront(10);
  q.print();
  q.pushFront(20);
  q.print();
  q.pushBack(30);
  q.print();
  q.pushBack(40);
  q.print();
  q.pushBack(50);
  q.print();
  q.pushFront(60);
  q.print();
  q.popFront();
  q.print();
  q.popFront();
  q.print();
    q.popFront();
  q.print();
    q.popBack();
  q.print();
    q.popFront();
  q.print();
    q.popFront();
  q.print();











  return 0;
}