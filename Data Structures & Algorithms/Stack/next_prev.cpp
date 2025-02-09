#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void nextSmallerElement(int arr[], int n, vector<int>& ans) {
  stack<int> s;
  s.push(-1);

  for(int i=n-1; i>=0; i-- ) {
    int element = arr[i];
    while(s.top() >= element) {
      s.pop();
    }
    //jab main yaha pohocha, iska mtlb, stack top pr koi chooota elemnet
    //aa chuka h, usko answer me store karlo
    ans.push_back(s.top());
    //baaki element ko stack me push toh krna hi h
    s.push(element);
  }

}

void prevSmallerElement(int arr[], int n, vector<int>& ans) {
  stack<int> s;
  s.push(-1);

  //fark sirf ioss wale loop ka h 
  for(int i=0; i<n; i++) {
    int element = arr[i];
    while(s.top() > element) {
      s.pop();
    }
    //yaha agye mtlb stack top koi chotta element h 
    ans.push_back(s.top());
    s.push(arr[i]);
  }
}

int main() {
  //input 
  int arr[] = {8,4,6,2,3};
  int n = 5;

  vector<int> ans;

  prevSmallerElement(arr,n,ans);
  //reverse(ans.begin(), ans.end());
  for(auto i: ans) {
    cout << i << " ";
  }

  return 0;
}