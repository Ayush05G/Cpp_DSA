#include <bits/stdc++.h>
using namespace std;

int numTrees(int n) {
        if(n==0 || n==1) return 1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;
    cout<<numTrees(n);
    return 0;
}