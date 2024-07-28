#include <bits/stdc++.h>
using namespace std;

//Approach 1(0(logn))
class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        int counter=0;
        while(n>0){
            ans=n%2;
            if(ans==1){
                counter++;
            }
            n/=2;
        }
        return counter;
    }
};

//Approach 2(0(1))
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;

    for (int i = 0; i < 32; ++i)
      if ((n >> i) & 1)
        ++ans;

    return ans;
  }
};