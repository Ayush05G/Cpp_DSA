#include <iostream>
using namespace std;

void printPermutation(string &str, int i) {
  //base case
  if( i >= str.length()) {
    cout << str << endl;
    return;
  }
  //1 case main solve karunga , baaki recursion sambhal lega
  //1 case -> main i wale dabbe k upar, hr ek element kop chance dunga
  for(int j=i; j<str.length(); j++) {
    //cout << "giving a call for " << i << " and " << j << endl;
    //chance dene k liye, swap kia tha 
    swap(str[i], str[j]);
    //baaki recursion dekh lega 
    //cout << "calling for string: " << str << endl;
    printPermutation(str,i+1);
    //backtrack
    swap(str[i], str[j]);
  }

}

int main() {
  string str = "abc";
  int i = 0;
  printPermutation(str,i);
  return 0;
}