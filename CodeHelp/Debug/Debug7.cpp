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

    void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0'){
        return;
    }
	if(input[0] == input[1]){
        int i = 2;
        for(;input[i]!='\0';i++){
            input[i-1] = input[i]; 
        }
        input[i-1] = input[i];
        removeConsecutiveDuplicates(input);
    }
    else
    removeConsecutiveDuplicates(input+1);
}

int main(){
    // int n;
    // cin>>n;
    // cout<<isPowerOfFour(n);

    // double x;
    // int n;
    // cin>>x>>n;
    // cout<<myPow(x,n);

    char input[100];
    cin.getline(input, 100);
    removeConsecutiveDuplicates(input);
    cout << input << endl;

    return 0;
}