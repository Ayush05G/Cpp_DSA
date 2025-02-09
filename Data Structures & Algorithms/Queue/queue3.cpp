#include <iostream>
using namespace std;

class Deque{
  private:
    int *arr;
    int n ;
    int front; 
    int rear;
  public:
    Deque(int size) {
      this->n = size;
      arr = new int[size];
      front = -1;
      rear = -1;
    }
    void pushFront(int val) {
      if(front == 0) {
        //iska mtlb mere paas left side me koi or jagah hi nahi. 
        //hai insert krne k liye
        cout << "Overflow" << endl;
      }
      else if(front == -1 && rear == -1) {
        //queue pehle empty thi, and ab main first elemnt
        //insert krne aaya hu 
        front++;
        rear++;
        arr[front] = val;
      }
      else {
        //normal flow
        front--;
        arr[front] = val;
      }
    }
    void popBack() {
      if(front == -1 && rear == -1) {
        //is case me queue phle sse hi empty h, no element to pop
        // therefpore underflow hojaega
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        //iss case me queue k andar sirf 1 hielemtn bacha hua h 
        //there after removing it, queue will get empty
        arr[rear] = -1;
        front = -1;
        rear = -1;
      }
      else {
        //normal flow';
        arr[rear] = -1;
        rear--;
      }
    }
    void pushBack(int val) {
      if(rear == n-1) {
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        //inserting first element;
        rear++;
        front++;
        arr[rear]= val;
      }
      else {
        //normal flow
        rear++;
        arr[rear] = val;
      }
    }
    void popFront() {
      if(front==-1 && rear==-1) {
        //queue is empty
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        //single element
        arr[front] = -1;
        front = -1;
        rear = -1;
      }
      else {
        //normal flow
        arr[front] = -1;
        front++;
      }
    }
    void print() {
      for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
      }cout << endl;
    }
};



int main() {
  Deque dq(5);

  dq.pushFront(10);
  dq.print();
  dq.pushFront(20);
  dq.print();
  dq.pushBack(15);
  dq.print();
  dq.pushBack(35);
  dq.print();
  dq.pushFront(100);
  dq.print();
  dq.popFront();
  dq.print();
  dq.popFront();
  dq.print();
  dq.popFront();
  dq.print();
  dq.popFront();
  dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  // dq.popBack();
  // dq.print();
  return 0;
}