#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int value) {
  //base case
  if(s.empty()) {
    s.push(value);
    return;
  }
  //1 case hum krenge and baaki recursion karega
  int topElement = s.top();
  s.pop();

  //baaki recursion
  insertAtBottom(s,value);

  //backtrack
  s.push(topElement);
}

int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  int value = 13;

  insertAtBottom(s,value);

  //traverse
  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;


  return 0;
}