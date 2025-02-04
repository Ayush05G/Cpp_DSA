#include <iostream>
using namespace std;

void checkEvenOdd(int n) {
  if(n & 1) {
    cout << "Odd" << endl;
  }
  else {
    cout << "Even" << endl;
  }
}

int getIthBit(int n, int i ) {
  int mask = (1 << i);
  int ans = n & mask;
  if(ans == 0) {
    return 0;
  }
  else {
    return 1;
  }
}

void setIthBit(int n, int i) {
  int mask = (1 << i);
  n = n | mask;
  cout << "Updated number: " << n << endl;
}

void clearIthBit(int &n, int i ) {
  int mask = ~(1 << i);
  n = n & mask;
  //cout << "updated number: " << n << endl;
}

void updateIthBit(int n, int i, int target) {
  //step1: clear i bit 
  clearIthBit(n,i);
  //step2: create mask and OR 
  int mask = (target << i);
  n = n | mask;
  cout << "updated number: " << n << endl;  
}

void clearLastIBits(int n, int i) {
  int mask = (-1 << i);
  n = n & mask;
  cout << "updated number: " << n << endl;
}

int countSetBits(int n) {
  int count = 0;

  while(n != 0) {
    count++;
    n = n & (n-1);
  } 

  return count;
}

void clearBitsInRange(int n, int i, int j) {
  int a = (-1 << (i+1));
  int b = ~(-1 << j);
  int mask = a | b;

  n = n & mask;

  cout << "udpated number: " << n << endl;


}

bool checkPowerOfTwo(int n) {
  int count = countSetBits(n);

  if(count == 1) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  int n = 15;
  // 000000....000001111
  //i -> 2nd bit
  //j -> 1st bit 
  //so i want to clear from 1st to 2nd bit 
  //i.e. 00000000....000001001 -> 9
  clearBitsInRange(n, 2, 1);






  // int n = 16;
  // bool ans = checkPowerOfTwo(n);
  // if(ans == true) {
  //   cout << "Yes, it is power of 2";
  // }
  // else {
  //   cout << "NO, its not power of 2";
  // }
  //cout << countSetBits(n) << endl;
  //clearLastIBits(n, 3);




  //1010
  //0010
  //101
  //checkEvenOdd(n);
  //cout << getIthBit(10,0) << endl;
  //setIthBit(n, 1);
  //111 -> 7
  //clearIthBit(n, 3);
  //updateIthBit(10, 0, 1);
  //1010
  //1011 -> 11
  return 0;
}