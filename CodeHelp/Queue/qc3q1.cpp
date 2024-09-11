#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q) {
  stack<int> st;
  while(!q.empty()) {
    int element = q.front();
    q.pop();

    st.push(element);
  }
  //ab tak saare queue k element stack k andar push hogye honge

  //ab stack se element jab bahar nilakenge, toh vo reverse hogye honge
  //unn reversed elemnt ko queue me insert krdenge 
  while(!st.empty()) {
    int element = st.top();
    st.pop();

    q.push(element);
  }


}

void reverseQueueRec(queue<int> &q) {
  //base case
  if(q.empty()) {
    return ;
  }
  //1 case main solve krunga 
  int frontElement = q.front();
  q.pop();
  //baaki recursion ki h 
  reverseQueueRec(q);
  ///backtracking 
  q.push(frontElement);
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  reverseQueueRec(q);

  //print all element inside queue
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}