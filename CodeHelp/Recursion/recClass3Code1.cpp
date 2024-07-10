#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, int i, string output,vector<string> &ans) {
  //base case
  if(i == str.length()) {
    // cout << output << endl;
    ans.push_back(output);
    return;
  }
  //1 case khud solve karunga
  char ch = str[i];
  //include ch 
  printSubsequences(str,i+1,output + ch,ans);
  //exclude ch
  printSubsequences(str,i+1,output,ans);
}

bool checkSorted(int arr[], int n, int index) {
  //base case
  if(index == n-1) {
    //single element wala array is treated as SORTED array
    return true;
  }

  bool currAns = false;
  bool recursionKaAns = false;
  //1 case solve karo
  if(arr[index+1] > arr[index]) 
  {
    currAns = true;
  }
  //baaki recursion sambhal lega
  recursionKaAns = checkSorted(arr,n,index+1);

  return (currAns && recursionKaAns);
  // if(currAns == true && recursionKaAns == true)
  //   return true;
  // else
  //   return false;
}

int main() {  
  string str = "abc";
  string output = "";
  int index=0;

  vector<string> ans;
  printSubsequences(str,index,output,ans);
  cout << ans.size() << endl;
  for(auto i: ans) {
    cout << i << endl;
  }



  // int arr[] = {10,20,300,40,50};
  // int size = 4;
  // int index = 0;
  // bool ans = checkSorted(arr,size, index);
  // cout << "Array is sorted or not: " << ans << endl;
  return 0;
}