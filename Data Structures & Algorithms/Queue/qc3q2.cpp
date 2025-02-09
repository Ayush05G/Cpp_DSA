#include <iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseInKGroup(queue<int>& q, int k, int count) {

  if(count >= k) {
    //toh toh main pkka reverse krunga
    stack<int> s;
    //fetch k elements from queue, insert in stack
    for(int i=0; i<k; i++) {
      int element = q.front();
      q.pop();

      s.push(element);
    }
    //fetch k elements from stack and insert in queue
    for(int i=0; i<k; i++) {
      int element = s.top();
      s.pop();

      q.push(element);
    }
    //1 case maine solve krlia h 
    //baaaki recursion sambhal lega
    reverseInKGroup(q, k, count-k);
  }

  else {
    //count < k
    //iska mtlab as it is queue k front se
    //uthakar queue k end me in elemnts ko insert krna h
    for(int i=0; i<count; i++) {
      int element = q.front();
      q.pop();
      q.push(element);
    }
  }





}


int main() {
  queue<int> q;

  q.push(10);
  // q.push(20);
  // q.push(30);
  // q.push(40);
  // q.push(50);
  // q.push(60);
  // q.push(70);
  // q.push(80);
  // q.push(90);
  // q.push(100);
  // q.push(110);

  int k = 3;
  int count = q.size();
  //count -> it tracks the number of elements to reverse

  reverseInKGroup(q, k, count);

  //printing 
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  
  return 0;
}