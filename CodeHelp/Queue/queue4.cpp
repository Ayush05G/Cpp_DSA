#include <iostream>
using namespace std;

class CircularQueue{
  public:
    int *arr;
    int n;
    int front;
    int rear;

  CircularQueue(int size) {
    this->n = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int val) {
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
  void pop() {
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
  int getFront() {
    if(front == -1) {
      cout << "Queue is empty";
    }
    else {
      return arr[front];
    }
  }
  int getSize() {
    if(front==-1 && rear == -1) {
      return 0;
    }
    else if(rear >= front) {
      return rear-front+1;
    }
    else{
      return n-front+rear+1;
    }
  }
  bool isEmpty() {
    if(front == -1 && rear == -1) {
      return true;
    }
    else {
      return false;
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
  CircularQueue q(5);

  q.push(10);
  q.print();
  q.push(20);
  q.print();
  q.push(30);
  q.print();
  q.push(40);
  q.print();
  q.push(50);
  q.print();
  q.push(60);
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.push(100);
  q.print();
  q.push(101);
  q.print();
  cout << q.getSize() << endl;
  cout << q.isEmpty() << endl;
  cout << q.getFront() << endl;

  return 0;
}