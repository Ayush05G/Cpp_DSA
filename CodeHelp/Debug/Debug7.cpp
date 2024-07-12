#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
        if(n<=1){
           return true;
        }
        if(n%4!=0){
           return false;
        }
       
        return isPowerOfFour(n/4);
    }

    double myPow(double x, int n) {

       int p = abs(n);
       double ans = 1.0;
       while(p>=1){
        p-- ;
          ans *= x;
       }
       return n<0 ? 1/ans : ans;    
    }

int main(){
    // int n;
    // cin>>n;
    // cout<<isPowerOfFour(n);

    double x;
    int n;
    cin>>x>>n;
    cout<<myPow(x,n);

    return 0;
}