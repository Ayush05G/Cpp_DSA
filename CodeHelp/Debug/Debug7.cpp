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

int main(){
    int n;
    cin>>n;
    cout<<isPowerOfFour(n);
    return 0;
}